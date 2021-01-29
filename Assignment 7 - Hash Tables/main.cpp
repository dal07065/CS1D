// Lina Kang
// CS1D MW 2:30 - 5:00 PM
// Assignment 7 - Hashing
// This program exercises the hashing algorithms using a map

/* OUTPUT
Lina Kang
CS1D MW 2:30-5:00PM
Assignment 7 - Hashing
This program exercises the hashing algorithms using a map
Data Structure Used: map
--------------------------
Part One:
--------------------------
(0,San Diego)
(1,El Segundo)
(2,Los Angeles)
(3,San Diego)
(4,San Clemente)
(6,Tustin)
(9,Vista)
(10,Dana Point)
(11,La Jolla)
(12,San Juan)
(13,Santa Ana)
(14,Laguna Beach)
(15,Irvine)
(16,Oceanside)
(17,Orange)
(18,Laguna Niguel)
(19,Brea)
(20,Anaheim)
(22,San Clemente)
(23,Aliso Viejo)
(26,Del Mar)
(28,Laguna Hills)
--------------------------
Part Two:
--------------------------
(0,Los Angeles)
(1,San Diego)
(3,San Diego)
(4,Tustin)
(5,Laguna Hills)
(6,San Juan)
(10,San Clemente)
(11,Riverside)
(12,La Jolla)
(13,Irvine)
(16,Laguna Beach)
(17,Orange)
(18,Laguna Niguel)
(19,Anaheim)
(20,Brea)
(22,San Clemente)
(23,Del Mar)
(25,Vista)
(26,El Segundo)
(27,Aliso Viejo)
(29,Santa Ana)
(30,Dana Point)
 */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "hashTable.h"

using namespace std;

//main function that does all the hashing
//void hashing(int (*hashFunc)(int),
//		void (*insert)(int, string, map<int, string> &));

//// Part 1. hashing helper functions
//int hashOne(int key);
//int hashDouble(int key);
//void insertKeyDouble(int key, string line, map<int, string> &hashmap);
//
//// Part 2. hashing helper functions
//int hashTwo(int key);
//void insertKeyQuadratic(int key, string line, map<int, string> &hashmap);

int main()
{
	cout << "Lina Kang\n"
			"CS1D MW 2:30-5:00PM\n"
			"Assignment 7 - Hashing\n"
			"This program exercises the hashing algorithms using a map\n";
	cout << "Data Structure Used: map  \n"
			"--------------------------\n"
			"Part One: \n"
			"--------------------------\n";

	hashmap citiesDouble;

	citiesDouble.hashing(1);

	cout << "--------------------------\n"
			"Part Two: \n"
			"--------------------------\n";

	hashmap citiesQuadratic;

	citiesQuadratic.hashing(2);

}
//
//// main function that does all the hashing
//void hashing(int (*hashFunc)(int), void (*insert)(int, string, map<int, string> &))
//{
//	map<int, string> hashmap;
//	map<int, string>::iterator p;
//
//	ifstream input ("input.txt");	// read in input from a separate txt file
//
//	string line;
//	int key;
//
//	while(input >> line)
//	{
//		if(line[0] == 'D') // if the line begins with "Delete" - erase key
//		{
//			input >> line;
//			input >> key;
//			key = hashFunc(key);
//			if(hashmap[key] != "")
//				hashmap.erase(key);
//		}
//		else	// insert key and its info
//		{
//			key = stoi(line);
//			input.ignore(100, ' ');
//			getline(input, line);
//			insert(key, line, hashmap);
//		}
//	}
//
//	// print the map
//	for(p = hashmap.begin(); p != hashmap.end(); ++p)
//	{
//			cout << "(" << p->first << "," << p->second << ")\n";
//	}
//}
//
//// Part 1. hashing helper functions
//int hashOne(int key)
//{
//	return key % 29;
//}
//int hashDouble(int key)
//{
//	return 13 - key % 13;
//}
//void insertKeyDouble(int key, string line, map<int, string> &hashmap)
//{
//	int i = 0;
//	do
//	{
//		key = hashOne(hashOne(key) + i*hashDouble(key));
//		i++;
//	}while(hashmap[key] != "");
//	hashmap[key] = line;
//}
//
//// Part 2. hashing helper functions
//int hashTwo(int key)
//{
//	return key % 31;
//}
//void insertKeyQuadratic(int key, string line, map<int, string> &hashmap)
//{
//	int i = 0;
//	do
//	{
//		key = hashTwo(hashTwo(key) + i*i);
//		i++;
//	}while(hashmap[key] != "");
//	hashmap[key] = line;
//}

/* input.txt

18 Laguna Niguel
41 Mission Viejo
22 San Clemente
44 Irvine
Delete key 41
58 Lake Forest
32 San Diego
49 Anaheim
Delete key 58
31 Los Angeles
17 Orange
72 Palms Springs
41 Riverside
Delete key 72
19 Brea
60 Santa Ana
35 Tustin
103 Oceanside
11 La Jolla
18 Del Mar
22 Aliso Viejo
49 Laguna Beach
Delete key 41
42 Vista
49 San Diego
99 San Juan
29 Dana Point
88 El Segundo
41 San Clemente
62 Laguna Hills

 */
