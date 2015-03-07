#include "Index_server.h"

#include <cassert>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <pthread.h>
#include <sstream>
#include <cmath>
#include <algorithm>

#include "mongoose.h"

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::ostream;
using std::ostringstream;
using std::string;
using std::vector;

namespace {
    int handle_request(mg_connection *);
    int get_param(const mg_request_info *, const char *, string&);
    string get_param(const mg_request_info *, const char *);
    string to_json(const vector<Query_hit>&);

    ostream& operator<< (ostream&, const Query_hit&);
}

pthread_mutex_t mutex;

// ***helper function*** sorting the similarity score:
bool sortfunc(Query_hit hit1, Query_hit hit2){
	return (hit1.score>hit2.score);
}

// Runs the index server on the supplied port number.
void Index_server::run(int port)
{
    // List of options. Last element must be NULL
    ostringstream port_os;
    port_os << port;
    string ps = port_os.str();
    const char *options[] = {"listening_ports",ps.c_str(),0};

    // Prepare callback structure. We have only one callback, the rest are NULL.
    mg_callbacks callbacks;
    memset(&callbacks, 0, sizeof(callbacks));
    callbacks.begin_request = handle_request;

    // Initialize the global mutex lock that effectively makes this server
    // single-threaded.
    pthread_mutex_init(&mutex, 0);

    // Start the web server
    mg_context *ctx = mg_start(&callbacks, this, options);
    if (!ctx) {
        cerr << "Error starting server." << endl;
        return;
    }

    pthread_exit(0);
}

// Load index data from the file of the given name.
void Index_server::init(ifstream& infile1, ifstream& infile2)//infile1: tfidf; infile2: pagerank
{
	string line;
    // Fill in this method to load the inverted index from disk.
    while(getline(infile1, line)){
		std::stringstream iss(line);
		string word;
		iss >> word;
		int df;
		iss >> df;
		string temp;
		while(iss){
			iss >> temp;
			int t = temp.find(':');
			string pagid = temp.substr(0, t);
			string tfidf_str = temp.substr(t + 1);
			double tfidf = std::stod(tfidf_str);
			tfidfSet[word].emplace(pagid, tfidf);
		}
	}

	while(getline(infile2, line)){
		int t = line.find(',');
		string pagid = line.substr(0, t);
		string pageRank_str = line.substr(t + 1);
		double pageRank = stod(pageRank_str);
		pageRankSet.emplace(pagid, pageRank);
	}
}

// Search the index for documents matching the query. The results are to be
// placed in the supplied "hits" vector, which is guaranteed to be empty when
// this method is called.
void Index_server::process_query(const string& query, vector<Query_hit>& hits, string w_str)
{
    cout << "Processing query '" << query << "'" << endl;
	cout << "w = " << w_str << endl;

	double w = stod(w_str);

	//remove punctuation
	int len = query.size();
	int j = 0; 
	string query_new = query;
	for(int i=0; i<len; i++){
		if(!ispunct(query[i])){
			query_new[j] = query[i];
			query_new[j] = tolower(query_new[j]);
			j++;
		}
	}
	query_new.resize(j);

	//readin the words in the query except the stop words
	std::stringstream qss(query_new);
	std::vector<string> tokens;
	std::string temp;
	while(qss){
		qss >> temp;
		if(stop_words.count(temp) == 0){
			tokens.push_back(temp);
		}
	}
	if(tokens.size() == 0) return;//return if all words in query are stop words

	std::unordered_set<string> possible_docs;
	string firstWord = tokens[0];

	if(tfidfSet.count(firstWord) == 0) return;//return if first word is contained in none of the docs

	//list the docs that contains the first word
	std::unordered_map<std::string, double>::iterator itr;
	for(itr = tfidfSet[firstWord].begin(); itr != tfidfSet[firstWord].end(); itr++){
		possible_docs.emplace(itr->first);
	}

	//remove the docs from possible_docs that doesn't contain the following words in tokens
	std::unordered_set<string>::iterator itr2;
	if(tokens.size() > 1){
		for(unsigned int i = 1; i < tokens.size(); i++){
			string a = tokens[i];
			for(itr2 = possible_docs.begin(); itr2 != possible_docs.end(); itr2++){
				if(tfidfSet[a].count(*itr2) == 0){
					possible_docs.erase(itr2);
					if(possible_docs.empty()) return;//return if there is no words in possible_docs left
				}
			}
		}
	}

	//now calculate tfidf of the query(tokens)
	std::unordered_map<string, double> query_tf;
	for(unsigned int i = 0; i < tokens.size(); i++){
		if(query_tf.count(tokens[i]) == 0){
			query_tf.emplace(tokens[i], 1.0);
		}
		else{
			query_tf[tokens[i]]++;
		}
	}
	std::unordered_map<string, double> query_tfidf;
	double N = (double)pageRankSet.size();//total number of docs
	for(unsigned int i = 0; i < tokens.size(); i++){
		if(query_tfidf.count(tokens[i]) == 0){
			double tfidf_temp = (double)tfidfSet[tokens[i]].size();//df
			tfidf_temp = query_tf[tokens[i]] * log(N / tfidf_temp) / log(10);
			query_tfidf.emplace(tokens[i], tfidf_temp);
		}
	}
	double denominator = 0.0;
	for(itr = query_tfidf.begin(); itr != query_tfidf.end(); itr++){
		denominator += (itr->second) * (itr->second);
	}
	denominator = sqrt(denominator);
	for(itr = query_tfidf.begin(); itr != query_tfidf.end(); itr++){
		itr->second = itr->second / denominator;
	}

	//now calculate the scores of each doc
	for(itr2 = possible_docs.begin(); itr2 != possible_docs.end(); itr2++){
		//Query_hit *in = new Query_hit(*itr2, pageRankSet[*itr2]);
		char* id = new char[(*itr2).length() + 1];
		strcpy(id, (*itr2).c_str());
		Query_hit *in = new Query_hit(id, w * pageRankSet[*itr2]);
		hits.push_back(*in);
	}
	
	for(unsigned int i = 0; i < hits.size(); i++){
		for(itr = query_tfidf.begin(); itr != query_tfidf.end(); itr++){
			hits[i].score += itr->second * tfidfSet[itr->first][hits[i].id] * (1 - w);
		}
	}

	sort(hits.begin(), hits.end(), sortfunc);
	
	cout << "the search result is as follows" << endl;
	for(unsigned int i = 0; i < hits.size(); i++){
		cout << hits[i].id << " " << hits[i].score << endl;
	}
	
    // Fill this in to process queries.
}

namespace {
    int handle_request(mg_connection *conn)
    {
        const mg_request_info *request_info = mg_get_request_info(conn);

        if (!strcmp(request_info->request_method, "GET") && request_info->query_string) {
            // Make the processing of each server request mutually exclusive with
            // processing of other requests.

            // Retrieve the request form data here and use it to call search(). Then
            // pass the result of search() to to_json()... then pass the resulting string
            // to mg_printf.
            string query;
            if (get_param(request_info, "q", query) == -1) {
                // If the request doesn't have the "q" field, this is not an index
                // query, so ignore it.
                return 1;
            }

			string w_str;            
			if (get_param(request_info, "w", w_str) == -1) {
       // If the request doesn't have the "w" field, this is not an index
       //        // query, so ignore it.
				return 1;
			}

            vector<Query_hit> hits;
            Index_server *server = static_cast<Index_server *>(request_info->user_data);

            pthread_mutex_lock(&mutex);
            server->process_query(query, hits, w_str);
            pthread_mutex_unlock(&mutex);

            string response_data = to_json(hits);
            int response_size = response_data.length();

            // Send HTTP reply to the client.
            mg_printf(conn,
                      "HTTP/1.1 200 OK\r\n"
                      "Content-Type: application/json\r\n"
                      "Content-Length: %d\r\n"
                      "\r\n"
                      "%s", response_size, response_data.c_str());
        }

        // Returning non-zero tells mongoose that our function has replied to
        // the client, and mongoose should not send client any more data.
        return 1;
    }

    int get_param(const mg_request_info *request_info, const char *name, string& param)
    {
        const char *get_params = request_info->query_string;
        size_t params_size = strlen(get_params);

        // On the off chance that operator new isn't thread-safe.
        pthread_mutex_lock(&mutex);
        char *param_buf = new char[params_size + 1];
        pthread_mutex_unlock(&mutex);

        param_buf[params_size] = '\0';
        int param_length = mg_get_var(get_params, params_size, name, param_buf, params_size);
        if (param_length < 0) {
            return param_length;
        }

        // Probably not necessary, just a precaution.
        param = param_buf;
        delete[] param_buf;

        return 0;
    }

    // Converts the supplied query hit list into a JSON string.
    string to_json(const vector<Query_hit>& hits)
    {
        ostringstream os;
        os << "{\"hits\":[";
        vector<Query_hit>::const_iterator viter;
        for (viter = hits.begin(); viter != hits.end(); ++viter) {
            if (viter != hits.begin()) {
                os << ",";
            }

            os << *viter;
        }
        os << "]}";

        return os.str();
    }

    // Outputs the computed information for a query hit in a JSON format.
    ostream& operator<< (ostream& os, const Query_hit& hit)
    {
        os << "{" << "\"id\":\"";
        int id_size = strlen(hit.id);
        for (int i = 0; i < id_size; i++) {
            if (hit.id[i] == '"') {
                os << "\\";
            }
            os << hit.id[i];
        }
        return os << "\"," << "\"score\":" << hit.score << "}";
    }
}
