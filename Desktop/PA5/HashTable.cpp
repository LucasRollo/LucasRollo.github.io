#include "HashTable.h"

using namespace std;

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// default constructor
HashTable::HashTable(){
	
}

// destructor
HashTable::~HashTable() {

}

// hash function to determine index where string key goes, as mentioned in the instructions
int HashTable::hash(string s) {
	int hash = 0;
	int n = s.length(); //s is the given word
	for (int i = 0; i < n; i++) {
		hash = hash + s[i] * 5; //1337 is my chosen positive integer
	}

	int index = hash % 10000; //the total hash % our hash table size (1000) is the index of the key
	return index;
}

// returns a boolean of whether the hash table is empty or not
bool HashTable::isEmpty() const {
	
	return false;
}
