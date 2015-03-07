#include "Index_server.h"

#include <cstdlib>
#include <fstream>
#include <iostream>

using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::string;

Index_server server;

int main(int argc, char *argv[])
{
    if (argc < 4) {
        cerr << "Usage: indexServer <portnum> <inverted-index-filename> <pagerank-filename>" << endl;
        return -1;
    }

    int port = atoi(argv[1]);
    if (port < 1024 || port > 65535) {
        cerr << "Port must be between 1024 and 65535 (exclusive)." << endl;
        return -1;
    }

    const char *fname1 = argv[2];
    ifstream infile1(fname1);
    if (!infile1.is_open()) {
        cerr << "Error opening file: " << fname1 << endl;
        return -1;
    }

    const char *fname2 = argv[3];
    ifstream infile2(fname2);
    if (!infile2.is_open()) {
        cerr << "Error opening file: " << fname2 << endl;
        return -1;
    }

    cout << "Init server with fname1 " << fname1 << " and fname2 " << fname2 << endl;
    server.init(infile1, infile2);

	std::vector<Query_hit> hits;
/*
	Query_hit in("a", 0.1);
	hits.push_back(in);
	hits.pop_back();
	if(hits.empty()){
		cout << "yes" << endl;
	}
	server.process_query("zumbo, zzzz", hits, 0.5);
*/
    server.run(port);

    return 0;
}
