#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <vector>
#include <iostream>

using namespace std;

struct node
{
	string city = "";
	int key = -1;
	int index = -1;
};

class hashmap
{
public:
	hashmap(int);
	~hashmap();

	// Double Hashing Algorithm
	void hashingDouble();
	int hashOne(int key, int i);
	void insertDouble(int key, string line);
	void eraseDouble(int key);

	// Quadratic Hashing Algorithm
	void hashingQuadratic();
	int hashTwo(int key, int i);
	void insertQuadratic(int key, string line);
	void eraseQuadratic(int key);

	void print();

private:
	node *map;
	int size;
};

hashmap::hashmap(int n)
{
	size = n;
	map = new node[n];
}
hashmap::~hashmap()
{
	delete [] map;
}

// Part 1. Double Hashing

void hashmap::hashingDouble()
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
			input.ignore(100,'\n');

			eraseDouble(key);
		}
		else	// insert key and its info
		{
			key = stoi(line);
			input.ignore(100, ' ');
			getline(input, line);

			insertDouble(key, line);
		}
	}

	print();
}

int hashmap::hashOne(int key, int i)
{
	return ( key % size + i*( 13- key % 13) ) % size;
}

void hashmap::insertDouble(int key, string line)
{
	int i = 0;
	int index = 0;

	// 1. Run it through hash function
	index = hashOne(key,i);

	// 2. If index is EMPTY or has SAME KEY, insert/replace element
	if(map[index].city == "" || key == map[index].key)
	{
		map[index].city = line;
		map[index].key = key;
		map[index].index = index;
	}
	// 3. If index is occupied...
	else
	{
		// 4. Until an EMPTY index or element with SAME KEY is found...
		while(map[index].city != "" && map[index].key != key)
		{
			i++;
			index = hashOne(key, i);
		}
		map[index].city = line;
		map[index].key = key;
		map[index].index = index;
	}

}

void hashmap::eraseDouble(int key)
{
	int i = 0;
	int index = 0;

	// Run until element with SAME KEY is found
	do
	{
		index = hashOne(key, i);
		i++;
	}while(map[index].key != key && i < size);
	// i < size to prevent infinite loop

	if(map[index].key == key)
	{
		map[index].city = "";
		map[index].key = -1;
		map[index].index = -1;
	}
}

// Part 2. Quadratic Hashing

void hashmap::hashingQuadratic()
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
			input.ignore(100,'\n');

			eraseQuadratic(key);
		}
		else	// insert key and its info
		{
			key = stoi(line);
			input.ignore(100, ' ');
			getline(input, line);

			insertQuadratic(key, line);
		}
	}
	print();
}

int hashmap::hashTwo(int key, int i)
{
	return (key % size + i*i) % size;
}

void hashmap::insertQuadratic(int key, string line)
{
	int i = 0;
	int index = 0;

	// 1. Run it through hash function
	index = hashTwo(key,i);

	// 2. If index is EMPTY or has SAME KEY, insert/replace element
	if(map[index].city == "" || key == map[index].key)
	{
		map[index].city = line;
		map[index].key = key;
		map[index].index = index;
	}
	// 3. If index is occupied...
	else
	{
		// 4. Until an EMPTY index or element with SAME KEY is found...
		while(map[index].city != "" && map[index].key != key)
		{
			i++;
			index = hashTwo(key, i);
		}
		map[index].city = line;
		map[index].key = key;
		map[index].index = index;
	}
}

void hashmap::eraseQuadratic(int key)
{
	int i = 0;
	int index = 0;

	// Run until element with SAME KEY is found
	do
	{
		index = hashTwo(key, i);
		i++;
	}while(map[index].key != key && i < size);
	// i < size to prevent infinite loop

	if(map[index].key == key)
	{
		map[index].city = "";
		map[index].key = -1;
		map[index].index = -1;
	}
}

void hashmap::print()
{
	// print the map
	for(int i = 0; i < size; i++)
	{
		cout << i;
		if(map[i].city != "")
			cout << " ---> ( " << map[i].key << ", " <<
				map[i].city << " )";
		cout << endl;
	}
}

#endif /* HASHTABLE_H_ */
