// Carmen Elliott
// Project 2
// Due May 4, 2018
// Recursive implementation of Quick Sort, Binary Search, and Merge Sort (ALL Vectors),
// Text/ Int to Int Hash,
// and Bloom Filter

#ifndef PROJECT2_H
#define PROJECT2_H

#include "RandomUtilities.h"
#include<iostream>;
#include<vector>;


using std::vector;
using std::cout;
using std::cin;
using std::endl;
using namespace std;




//Generates random vectors.. used from an old lab.
// Useful for testing.
vector<int> getNums(size_t listSize, int minNum, int maxNum)
{
	vector<int> theList;
	for (size_t i = 0; i < listSize; ++i)
	{
		theList.push_back(randReal(minNum, maxNum));
	}
	return theList;
}



/*
The partition function assign the last element of the vector
as the pivot. The pivot is placed in correct sorted spot
of vec. All elements smaller than pivot are then placed
on the left and all larger placed on the right of the pivot.
*/
int partition(vector<int>& vec, int left, int right)
{
	int pivot = vec[left];
	int i = left;
	int temp; // for swap purposes
	for (int j = left + 1; j < right; j++) // if current element is less than or equal to pivot
	{
		if (vec[j] <= pivot)
		{
			i++;
			temp = vec[j];
			vec[j] = vec[i];
			vec[i] = temp;
		}
	}
	temp = vec[left];
	vec[left] = vec[i];
	vec[i] = temp;
	return i;
}
//This uses the partition function above to finish quick sort.
// the variable left is the first index and right is the last index
// 
// 
void QuickSort(vector<int>& vec, int left = 0, int right = -1)
{
	if (right == -1)
	{
		right = vec.size();
	}
	if (left < right)
	{
		int pi = partition(vec, left, right); // pi is the partitoning index

		QuickSort(vec, left, pi); // Sorts the elements before and after partition seperately 
		QuickSort(vec, pi + 1, right);
	}
}

//http://www.fredosaurus.com/notes-cpp/algorithms/searching/rbinarysearch.html
// https://www.geeksforgeeks.org/binary-search/
// https://codescracker.com/cpp/program/cpp-program-binary-search.htm
// Recursive Binary Search of a vector

void BinarySearch(vector<int>& vec, int search, int right, int left = 0)
{
	
	int mid = (left + right) / 2;
	while (left <= right)
	{

		if (vec[mid] < search)
		{
			left = mid + 1;
		}
		else if (vec[mid] == search)
		{
			cout << search << " found at location " << mid + 1 << endl;
			break;
		}
		else
		{
			right = mid - 1;
		}
		mid = (left + right) / 2;
	}
	if (left > right)
	{
		cout << search << " is not present." << endl;

	}
	

}
 // Implementation of MergeSort Function with Merge
vector<int> Merge(vector<int> left, vector<int> right)
{
	vector<int> result;
	while ((int)left.size() > 0 || (int)right.size() > 0)
	{
		if ((int)left.size() > 0 && (int)right.size() > 0)
		{
			if ((int)left.front() <= (int)right.front())
			{
				result.push_back((int)left.front());
				left.erase(left.begin());
			}
			else
			{
				result.push_back((int)right.front());
				right.erase(right.begin());
			}
		}
		else if ((int)left.size() > 0)
		{
		
			for (int i = 0; i < (int)left.size(); i++)
			{
				result.push_back(left[i]);
			}
			break;
		} 
		else if ((int)right.size() > 0)
		{
			for (int i = 0; i < (int)right.size(); i++)
			{
				result.push_back(right[i]);
			}
			break;
		}
		
	}
	return result;
}
// Recursive Merge Sort Implemention 
// http://www.bogotobogo.com/Algorithms/mergesort.php
// https://www.sanfoundry.com/cpp-program-implement-merge-sort/
// https://www.geeksforgeeks.org/merge-sort/
vector<int> MergeSort(vector<int> vec)
{
	if (vec.size() <= 1)
	{
		return vec;
	}
	vector<int> left, right, result;
	int mid = ((int)vec.size() + 1) / 2;
	for (int i = 0; i < mid; i++)
	{
		left.push_back(vec[i]);
	}
	for (int i = mid; i < (int)vec.size(); i++)
	{
		right.push_back(vec[i]);
	}

	left = MergeSort(left);
	right = MergeSort(right);
	result = Merge(left, right);
	return result;

}


 //djb2 hash function for string to int hashing
// http://www.cse.yorku.ca/~oz/hash.html
// https://softwareengineering.stackexchange.com/questions/49550/which-hashing-algorithm-is-best-for-uniqueness-and-speed
unsigned int hashString(string const& str)
{
	unsigned int hash = 5381;
	int c;
	for(auto c : str)
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	cout << hash << endl;
	return hash;
}


// Convert an integer to a string to be hashed. 
// Then the string created runs through the djb2 hashing
unsigned int IntToString(int num)
{
	string strg = std::to_string(num);
	unsigned int hashed = hashString(strg);
	return hashed;
}

// Function for quick printing of vectors
void printVec(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

#endif