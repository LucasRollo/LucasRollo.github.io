#include "ChainingHashTable.h"
#include <fstream>

using namespace std;
///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor (NOTE: graders will use a default constructor for testing)
ChainingHashTable::ChainingHashTable() : HashTable(){
	for(int i = 0; i < 10000; i++){
		table[i] = new std::list<pair<string, int>>();
	}

}

// destructor
ChainingHashTable::~ChainingHashTable(){
		for(int i = 0; i < 10000; i++){
		delete table[i];
	}

}

// inserts the given string key
void ChainingHashTable::insert(std::string key, int val) {
	int index = hash(key);
	bool found = false;

	for (auto iter = table[index]->begin(); iter != table[index]->end(); ++iter){
	    if(iter->first == key){
			iter->second++;
			found = true;
		}
	}

	if(!found){
		table[index]->push_back(std::pair<std::string, int>(key, 1));
	}
	
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ChainingHashTable::remove(std::string key) {
	int index = hash(key);
	int val = 0;
	bool found = false;

	if(table[index]->empty()){
		assert(false);
	}

	for (auto iter = table[index]->begin(); iter != table[index]->end(); ++iter){
	    if(iter->first == key){
			val = iter->second;
			table[index]->erase(iter);
			found = true;
			break;
		}
	}

	if(!found){
		assert(false);
	}

	return val;
}

// getter to obtain the value associated with the given key
int ChainingHashTable::get(std::string key) {
	int index = hash(key);

	for (auto iter = table[index]->begin(); iter != table[index]->end(); ++iter){
	    if(iter->first == key){
			return iter->second;
		}
	}

	return 0;
}

// prints number of occurrances for all given strings to a txt file
void ChainingHashTable::printAll(std::string filename) {

	insertAll(filename);

	ofstream out("output.txt", ios::out);

	for(int i = 0; i < 10000; ++i){

		for(auto iter = table[i]->begin(); iter != table[i]->end(); ++iter){
			out << iter->first << " " << iter->second << "\n";
		}

	}
	

}

// inserts all of the items in a txt file into the hash table
void ChainingHashTable::insertAll(std::string filename){
	ifstream in(filename + ".txt",ios::in);
	string word;

	while(in >> word){
        this->insert(word, 0);
	}
}