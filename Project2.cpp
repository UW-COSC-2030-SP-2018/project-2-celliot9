// Carmen Elliott
// Project 2
// Due May 4, 2018
// Testing File

#include "RandomUtilities.h"
#include "BloomFilter.h"
#include "Project2.h"
#include<iostream>
#include<vector>
#include <algorithm> //  to use for testing
using std::sort;

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main()
{

	// QUICK SORT TEST
	// Testing against std::sort to ensure the vector sorted correctly.
	vector<int> vec1 = getNums(80, 1, 500);
	vector<int> testVec = vec1;
	QuickSort(vec1);
	sort(testVec.begin(), testVec.end());

	if (vec1 == testVec)
	{
		cout << "QuickSort was successful! " << endl;
		printVec(vec1);
	}
	else
	{
		cout << "QuickSort did not match test vector... Fail! " << endl;
		printVec(vec1);
	}



	// BINARY SEARCH TEST
	// Function itself returns whether or not a value was found and where.
	
	vector<int>vec = getNums(80, 1, 100);
	QuickSort(vec); // start with a sorted vector
	int right = vec.size();
	cout << "Before Binary Search: " << endl;
	printVec(vec);
	cout << endl;
	int search;
	cout << "Enter the value to be searched: ";
	cin >> search;
	BinarySearch(vec, search, right);
	cout << endl;

	// MERGE SORT TEST
	// Use std::sort to ensure propper sorting with merge sort function
	vec1 = getNums(80, 1, 500);
	testVec = vec1;
	vec1 = MergeSort(vec1);
	sort(testVec.begin(), testVec.end());
	if (vec1 == testVec)
	{
		cout << "MergeSort was successful!" << endl;
		printVec(vec1);
	}
	else
	{
		cout << "MergeSort did not match test vector... Fail!" << endl;
		printVec(vec1);
	}
	cout << endl;
	


	// HASHING TESTS 
	cout << "Hash a String to Int:\nHello World this is a test of the string hashing and this is over eighty characters for the test and it works" << endl;
	string str = "Hello World this is a test of the string hashing and this is over eighty characters for the test and it works";
	cout << endl;
	cout << "After Hash: " << endl;
	hashString(str);
	cout << endl;
	unsigned int num = 800;
	cout << "Hash an Int to Int:\n800" << endl;
	cout << "After Hash: " << endl;
	IntToString(num);
	cout << endl;
	

	//BLOOM FILTER TEST
	
	vector<HashFunction> hashFunctions;
	hashFunctions.push_back(djb2);
	hashFunctions.push_back(sdbm);

	BloomFilter bf(1024, hashFunctions);

	// insert words into the filter
	vector<string> setOfStrings({
		"Hello World!", "pears", "java", "c++", "old", "new"});


	cout << "Bloom filter tests for the following:" << endl;

	for (std::vector<std::string>::iterator iter = setOfStrings.begin(); iter != setOfStrings.end(); iter++) {
		bf.add(*iter);
		cout << "\t" + *iter << endl;
	}

	// testing a set of strings against the bloom filter
	std::vector<std::string> testSetOfStrings({
		"Hello World!", "pears", "java", "c++", "old", "new", "airplane", "car", "bike"});

	cout << "Testing set for the following:" << std::endl;
	cout << std::boolalpha;

	for (std::vector<std::string>::iterator iter = testSetOfStrings.begin(); iter != testSetOfStrings.end(); iter++) {
		cout << "\t" + *iter + ": " << bf.search(*iter) << endl;
	}

	getchar();



}

