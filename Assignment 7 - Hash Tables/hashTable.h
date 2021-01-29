/*
 * hashTable.h
 *
 *  Created on: Oct 6, 2020
 *      Author: dal07
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <vector>
#include <iostream>

using namespace std;

class node
{
public:
	string city;
	int key;
	node() { key = 0; city = "";}
	node(int k, string c) { key = k; city = c; }
};

class hashmap
{
public:
	hashmap(int);
	void insert(int key);
	void erase(int key, int hashfunc);
//	void erase(int key, int(hashmap::*hashFunc)(int,int));
	void print();
	int hashOne(int key, int i);
	int hashTwo(int key, int i);
//	void insertKey(int key, string line, int(hashmap::*hashFunc)(int,int));
	void insertKey(int key, string line, int hashfunc);
	void hashing(int);
private:
	node * map;
};

hashmap::hashmap(int n)
{
	map = new node[n];
}

void hashmap::insertKey(int key, string line, int hashfunc)
{
	node * newNode = new node(key,line);// = new node;
	if(hashfunc == 1)
	{
		int i = 0;
		do
		{
			key = hashOne(key, i);
			i++;

			if(map[key])
		}while(map[key] != NULL);
	}
	else
	{
		int i = 0;
		do
		{
			key = hashTwo(key, i);
			i++;
		}while(map[key] != NULL);
	}
	map[key] = *newNode;
}

void hashmap::erase(int key, int hashfunc)
{
//	string line;
//	for(int i = 0; i < map.size(); i++)
//	{
//		if(map[i].key == key)
//			line = map[i].city;
//	}

	int i = 0;
	if(hashfunc == 1)
	{
		do
		{
			key = hashOne(key, i);
			i++;
		}while(map[key].city != "" && i < map.size());
	}
	else
	{
		do
		{
			key = hashTwo(key, i);
			i++;
		}while(map[key].city != "" && i < map.size());
	}

	if(map[key].city != "")
		map.erase(map.begin() + key);
}

// Part 1. hashing helper functions
int hashmap::hashOne(int key, int i)
{
	return ((key % 29) + i*(13- key % 13)) % 29;
}

// Part 2. hashing helper functions
int hashmap::hashTwo(int key, int i)
{
	return (key % 31 + i*i) % 31;
}

void hashmap::print()
{
	// print the map
	for(it = map.begin(); it != map.end(); ++it)
	{
		cout << "(" << it->key << "," << it->city << ")\n";
	}
}

void hashmap::hashing(int hashfunc)
{
	ifstream input ("input.txt");	// read in input from a separate txt file

	string line;
	int key;

	while(input >> line)
	{
		if(line[0] == 'D') // if the line begins with "Delete" - erase key
		{
			input >> line;
			input >> key;
			erase(key, hashfunc);
		}
		else	// insert key and its info
		{
			key = stoi(line);
			input.ignore(100, ' ');
			getline(input, line);
			insertKey(key, line, hashfunc);
		}
	}

	print();
}




#endif /* HASHTABLE_H_ */
