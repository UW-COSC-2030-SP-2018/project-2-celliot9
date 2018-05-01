// Carmen Elliott
// Bloom Filter Implementation 

#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H
#include <iostream>
#include <string>
#include <vector>
#include <iterator>


// bloom filter implementation

typedef unsigned int(*HashFunction)(std::string);

class BloomFilter {
	unsigned int numberOfCells;
	unsigned int numberOfFunctions;
	bool* cell;
	std::vector<HashFunction> hashFunctions;

public:

	BloomFilter(unsigned int numbCells, std::vector<HashFunction> funcs) : numberOfCells(numbCells), hashFunctions(funcs) {
		cell = (bool*)calloc(numbCells, sizeof(bool));
	}

	void add(std::string str) {
		for (std::vector<HashFunction>::iterator iter = hashFunctions.begin(); iter != hashFunctions.end(); iter++) {
			cell[(*iter)(str) % numberOfCells] = true;
		}
	}

	bool search(std::string str) {
		bool strInSet = true;

		for (std::vector<HashFunction>::iterator iter = hashFunctions.begin(); iter != hashFunctions.end(); iter++) {
			if (cell[(*iter)(str) % numberOfCells] == false) {
				strInSet = false;
				break;
			}
		}

		return strInSet;
	}

	~BloomFilter() {
		free(cell);
		cell = NULL;
	}
};

// two different hash functions to test Bloom Filter
unsigned int djb2(std::string str) {
	unsigned int hash = 5381;

	for (std::string::iterator iter = str.begin(); iter != str.end(); iter++) {
		hash = ((hash << 5) + hash) + *iter;
	}

	return hash;
}

unsigned int sdbm(std::string str) {
	unsigned int hash = 0;

	for (std::string::iterator iter = str.begin(); iter != str.end(); iter++) {
		hash = ((hash << 6) + (hash << 16) - hash) + *iter;
	}

	return hash;
}



#endif