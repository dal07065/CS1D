#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
#include <vector>
#include <time.h>

using namespace std;

const int MIN = 0;		// sentinel values
const int MAX = 150;	// sentinel values

struct Node
{
	int key;
	string name;

	Node * next;
	Node * below;
};


class skipList
{
public:
	skipList();

	void put(int, string);
	Node* find(int);
	void erase(int);
	bool empty();
	int getSize();

	void printLevels();
	void printDictionary();
	void generateRandom();	// for randomized algorithm

private:
	int size;

	Node * top;				// points to top-left sentinel value
	Node * topLast;			// points to top-right sentinel value

	int randomNumbers[50];	// for randomized algorithm
	int randomCurr;			// for randomized algorithm

};

// skiplist constructor
skipList::skipList()
{
	top = new Node;
	top->key = MIN;
	top->name = "MIN";
	top->below = NULL;

	topLast = new Node;
	topLast->key = MAX;
	topLast->name = "MAX";
	topLast->below = NULL;

	top->next = topLast;
	topLast->next = NULL;

	randomCurr = 0;
	size = 0;
}

// insert an element into the skiplist
void skipList::put(int key, string name)
{
	// list of nodes before the inserting item to update their "next" pointers
	vector<Node *> nodesToUpdate;

	Node * current = top;

	// find the most appropriate location to insert the element
	while(current != NULL)
	{
		if(current->next->key > key)
		{
			nodesToUpdate.push_back(current);
			if(current->below == NULL)
				break;
			else
				current = current->below;
		}
		else
		{
			current = current->next;
		}
	}

//	srand(time(NULL));

	// insert the element and update all "next" pointers that stand before it
	int random = 1;							// random starts with 1 in order-
	int i = nodesToUpdate.size() - 1;		// -to insert the item at least once
	while(random == 1 && i >= 0)
	{
		Node * tempNext = nodesToUpdate[i]->next;
		nodesToUpdate[i]->next = new Node;
		nodesToUpdate[i]->next->key = key;
		nodesToUpdate[i]->next->name = name;
		nodesToUpdate[i]->next->next = tempNext;

		if(i == nodesToUpdate.size() -1)
			nodesToUpdate[i]->next->below = NULL;
		else
			nodesToUpdate[i]->next->below = nodesToUpdate[i+1]->next;

		i--;
		random = randomNumbers[randomCurr];	// get 0or1 from the randomized list
		randomCurr++;
	}

	// If current level of element has exceeded beyond highest level AND
	// random number is still "heads", continue to add until "tails" or 0 comes
	current = nodesToUpdate[0]->next;
	while(random == 1)
	{
		Node * tempBelow = current;
		current = new Node;

		Node * topCurrent = new Node;
		topCurrent->below = top;
		topCurrent->next = current;
		topCurrent->key = MIN;
		topCurrent->name = "MIN";

		Node * topLastCurrent = new Node;
		topLastCurrent->below = topLast;
		topLastCurrent->next = NULL;
		topLastCurrent->key = MAX;
		topLastCurrent->name = "MAX";

		current->next = topLastCurrent;
		current->below = tempBelow;
		current->key = key;
		current->name = name;

		top = topCurrent;
		topLast = topLastCurrent;

		random = randomNumbers[randomCurr];
		randomCurr++;
	}
	size++;
}

// returns a Node that contains the "key"
Node* skipList::find(int key)
{
	Node * current = top;
	bool found = false;

	while(current != NULL)
	{
		if(current->next->key > key) 		// go down a level
		{
			if(current->below == NULL)
				break;
			else
				current = current->below;
		}
		else if(current->next->key == key)	// if key is found
		{
			found = true;
			break;
		}
		else								// keep going to the right
		{
			current = current->next;
		}
	}

	if(found)
		return current->next;
	return NULL;
}

// removes an element with the indicated key
void skipList::erase(int key)
{
	vector<Node *> nodesToUpdate;			// list of nodes that stand right
											// before the key element(s)
											// for the purpose of updating
											// their "next" pointers
	Node * current = top;

	while(current != NULL)
	{
		if(current->next->key > key)		// go down a level
		{
			if(current->below == NULL)
				break;
			else
				current = current->below;
		}
		else if(current->next->key == key)	// if key is found
		{
			nodesToUpdate.push_back(current);
			if(current->below == NULL)
				break;
			else
				current = current->below;
		}
		else								// keep going to the right
		{
			current = current->next;
		}
	}

	// update "next" pointers of nodes that stood before the deleted element
	int i = nodesToUpdate.size() - 1;
	while(i >= 0)
	{
		Node * tempNext = nodesToUpdate[i]->next->next;
		Node * tempDelete = nodesToUpdate[i]->next;

		nodesToUpdate[i]->next = tempNext;

		i--;
		delete tempDelete;
	}
	size--;
}

// determines whether the list is empty or not
bool skipList::empty()
{
	if(size <= 0)
	{
		return true;
	}
	return false;
}

// returns the number of elements in the skip list
int skipList::getSize()
{
	return size;
}

// prints the skiplist by levels
void skipList::printLevels()
{
	Node * current = top->next;
	Node * topCurrent = top;

	int level = 0;

	cout << left << "Level: " << level << endl;
	while(current != NULL)
	{
		cout << current->name << " " << current->key;

		if(current->next->key == 150 && current->below == NULL)
		{
			break;
		}
		if(current->next->key == 150)
		{
			current = topCurrent->below;
			topCurrent = current;
			current = current->next;
			level++;
			cout << endl << endl << "Level: " << level << endl;
		}
		else
		{
			current = current->next;
			cout << " -> ";
		}
	}
}

// prints the values and the keys within the skiplist
void skipList::printDictionary()
{
	Node * current = top;

	while(current->below != NULL)
	{
		current = current->below;
	}
	current = current->next;
	while(current->next != NULL)
	{
		cout << current->name << " " << current->key << endl;
		current = current->next;
	}
}

// generate a list of randomized 0's and 1's
// (using srand(time(NULL)) and rand() in one go tends to show same results)
//  everytime)
void skipList::generateRandom()
{
	srand(time(NULL));
	for(int i = 0; i < 50; i++)
	{
		randomNumbers[i] = rand() % 2;
	}
}

#endif /* HEADER_H_ */
