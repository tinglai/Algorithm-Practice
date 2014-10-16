#include <iostream>
#include <string>
#include <queue>
#include <climits>

using namespace std;

struct Pet{
	int timestamp = INT_MAX;
	string name;
	bool isDog;

	Pet(){}
	Pet(string mingzi, bool isD):
		name(mingzi), isDog(isD){}
};

struct PetQueue{
	queue<Pet> dogs;
	queue<Pet> cats;
	int time = 0;//every time a new pet
				 //comes into the shelter
				 //time++. I use this to record
				 //the order of the pets' entrance
	
	PetQueue(){}
	PetQueue(Pet*, int);
	void enqueue(Pet);
	Pet dequeueAny();
	Pet dequeueDog();
	Pet dequeueCat();
};

int main(){
	PetQueue pets;
	Pet dog1("dog1", true);
	Pet dog2("dog2", true);
	Pet dog3("dog3", true);
	Pet dog4("dog4", true);
	Pet cat1("cat1", false);
	Pet cat2("cat2", false);
	Pet cat3("cat3", false);
	pets.enqueue(cat1);
	pets.enqueue(dog1);
	pets.enqueue(cat2);
	pets.enqueue(cat3);
	pets.enqueue(dog2);
	pets.enqueue(dog3);
	pets.enqueue(dog4);
	
	cout << "the first pet is " << pets.dequeueAny().name << endl;
	cout << "then, the first cat is " << pets.dequeueCat().name << endl;
	cout << "then, the first dog is " << pets.dequeueDog().name << endl;
	cout << "then, the first dog is " << pets.dequeueDog().name << endl;
	cout << "then, the first pet is " << pets.dequeueAny().name << endl;
}

PetQueue::PetQueue(Pet* array, int n){
	for(int i = 0; i < n; i++){
		enqueue(array[0]);
	}
}

void PetQueue::enqueue(Pet in){
	if(in.isDog){
		dogs.push(in);
	}
	else{
		cats.push(in);
	}
	in.timestamp = time;
	time++;
}

Pet PetQueue::dequeueAny(){
	Pet result;
	if(dogs.empty() && cats.empty()){
		cout << "there are no pets left" << endl;
		Pet temp("no pet left", true);
		result = temp;
		return result;
	}
	else if(dogs.empty()){
		result = cats.front();
		cats.pop();
		return result;
	}
	else if(cats.empty()){
		result = dogs.front();
		dogs.pop();
		return result;
	}
	else if(dogs.front().timestamp < 
	   cats.front().timestamp){//if top_dog is elder than top_cat
		result = dogs.front();
		dogs.pop();
	}
	else{
		result = cats.front();
		cats.pop();
	}
	return result;
}

Pet PetQueue::dequeueDog(){
	Pet result;
	result = dogs.front();
	dogs.pop();
	return result;
}

Pet PetQueue::dequeueCat(){
	Pet result;
	result = cats.front();
	cats.pop();
	return result;
}
