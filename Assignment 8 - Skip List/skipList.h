////#ifndef SKIPLIST_H_
////#define SKIPLIST_H_
////
////#include <iostream>
////#include <vector>
////#include <time.h>
////
////using namespace std;
////
////const int MIN = 0;
////const int MAX = 100;
////
////struct Node
////{
////	int key;
////	string name;
////
////	Node * right;
////	Node * down;
////};
////
//////class S
//////{
//////public:
//////	S()
//////	{
//////		size = 2;
//////		S_list = new Node[50];
//////		S_list[0] = 0;
//////		S_list[50] = 100;
//////	}
//////	int getSize()
//////	{
//////		return size;
//////	}
//////	Node * S_list;
//////	int size;
//////private:
//////
//////};
////
////class skipList
////{
////public:
////	skipList();
////	Node* find(int);
////	void put(int, string);
////	void erase(int);
////	int getSize();
////private:
////	int size;
////	Node* top;
////	int levelHighest;
////	vector<vector<Node*>*> list;
////	vector<vector<Node*>*>::iterator p;
////};
////
////skipList::skipList()
////{
////	size = 0;
////	levelHighest = 0;
////	top = NULL;
////	list.push_back(new vector<Node *>);
////	p = list.begin();
////}
////void skipList::put(int key, string str)
////{
////	vector<Node *> * S_top;
////
////	Node * current = S_top[0];
////
////	for(int i = list.size(); i >= 0; i++)
////	{
////		S_top = list[i];
////		while()
////		{
////			if((*S_top)[i]->key > key)
////			{
////				S_top->push_back(current);
////				j = S_top->size();
////			}
////		}
////	}
////
////}
//
//#ifndef SKIPLIST_H_
//#define SKIPLIST_H_
//
//#include <iostream>
//#include <vector>
//#include <time.h>
//
//using namespace std;
//
//const int MIN = 0;
//const int MAX = 100;
//
//struct Node
//{
//	int key;
//	string name;
//
//	Node * next;
//	Node * below;
//};
//
//
//class skipList
//{
//public:
//	skipList();
//	Node* find(int);
//	void put(int, string);
//	void erase(int);
//	int getSize();
//private:
//	int size;
//	Node* top;
//	int levelHighest;
////	vector<Node *> list;
//};
//
//skipList::skipList()
//{
//	size = 0;
//	levelHighest = 0;
//	top = NULL;
//}
//void skipList::put(int key, string str)
//{
//	if(size == 0)
//	{
//		Node * item = list.front()->getHead();
//		item->key = key;
//		item->name = str;
//		item->below = NULL;
//		item->next = NULL;
//		item->prev = NULL;
//		list.front()->getTail() = item;
//
//		srand(time(NULL));
//
//		int random = rand() + 1;
//
//		while(random != 0)
//		{
//			item->above = new Node;
//			item->above->key = key;
//			item->above->name = str;
//			item->above->below = item;
//			item->above->next = NULL;
//			item->above->prev = NULL;
//
//			list.push_back(new S);
//			list.back()->getHead() = item->above;
//			list.back()->getTail() = item->above;
//			levelHighest++;
//
//			random = rand() + 1;
//		}
//
//	}
//	else
//	{
//		Node * current = list[levelHighest]->getHead();
//
//		while(current->key < key)
//		{
//			if(current->next != NULL)
//			{
//				current = current->next;
//			}
//			else if(current->below != NULL)
//				current = current->below;
//			else
//				break;
//		}
//
//		Node * next = current;
//		current = current->prev;
//
//		current->next = new Node;
//		current = current->next;
//		current->key = key;
//		current->name = str;
//		current->next = next;
//		current->below = NULL;
//
//		srand(time(NULL));
//
//		int random = rand() + 1;
//
//		while(random != 0)
//		{
//			current->above = new Node;
//			current->above->key = key;
//			current->above->name = str;
//			current->above->below = current;
//			current->above->next = NULL;
//			current->above->prev = NULL;
//
//			list[i]
//			list.back()->getHead() = current->above;
//			list.back()->getTail() = current->above;
//			levelHighest++;
//
//			random = rand() + 1;
//		}
//	}
//
//
//	Node * current = list.back()->getHead();
////////////////////////////////////////////////////////////////////////////
//	Node * item = find(key);
//
//	if(item != NULL)	// if node exists
//	{
//		item->name = str;
//		while(item->above != NULL)
//		{
//			item = item->above;
//			item->name = str;
//		}
//	}
//	else	// if node does not exist
//	{
//		item = head;
//		while(true)
//		{
//			item = item->next;
//			if(item->next->key > key && item->below == NULL)
//				break;
//			if(item->next > key)
//				item = item->below;
//		}
//		Node * nextptr = item->next;
//		item->next = new Node(key, str, item, nextptr, NULL, NULL, 1, 0, -1);
//		item = item->next;
//		nextptr->prev = item;
//
//		srand(time(NULL));
//		int random = rand() + 1;
//
//		for(int i = 0; i < random; i++)
//		{
//
//			item->above = new Node(key, str, item, nextptr, NULL, NULL, i+2, i+1, i);
//		}
//	}
//
//	// make a new key at the new location
//
//
//
//	// through randomized algorithm, add it to upper levels
//}
//
//
//
//#endif /* SKIPLIST_H_ */
//
////
////
////#ifndef SKIPLIST_H_
////#define SKIPLIST_H_
////
////#include <iostream>
////#include <vector>
////#include <time.h>
////
////using namespace std;
////
////class Node
////{
////public:
////	Node(int k, string namestr, Node * p, Node * n, Node * b, Node * a,
////			int u, int c, int d)
////	{
////		key = k;
////		name = namestr;
////		prev = p;
////		next = n;
////		below = b;
////		above = a;
////		up = u;
////		current = c;
////		down = d;
////	}
////	int key;
////	string name;
////	Node * prev;
////	Node * next;
////	Node * below;
////	Node * above;
////	int up;
////	int current;
////	int down;
////};
////
////class skipList
////{
////public:
////	skipList();
////	Node* find(int);
////	void put(int, string);
////	void erase(int);
////	int getSize();
////private:
////	int size;
////	Node* head;
////	int levelHighest;
////	vector<vector<Node *>> list;
////};
////
////skipList::skipList()
////{
////	size = 0;
////	head = new Node(0, "HEAD", NULL, NULL, NULL, NULL, 0, 0, -1);
////	list[0].push_back(head);
////}
////void skipList::put(int key, string str)
////{
////	Node * item = find(key);
////
////
////	// search for the most convenient spot Top -> Bottom
//////	Node * item = find(key);
//////
//////	if(item != NULL)	// if node exists
//////	{
//////		item->name = str;
//////		while(item->above != NULL)
//////		{
//////			item = item->above;
//////			item->name = str;
//////		}
//////	}
//////	else	// if node does not exist
//////	{
//////		item = head;
//////		while(true)
//////		{
//////			item = item->next;
//////			if(item->next->key > key && item->below == NULL)
//////				break;
//////			if(item->next > key)
//////				item = item->below;
//////		}
//////		Node * nextptr = item->next;
//////		item->next = new Node(key, str, item, nextptr, NULL, NULL, 1, 0, -1);
//////		item = item->next;
//////		nextptr->prev = item;
//////
//////		srand(time(NULL));
//////		int random = rand() + 1;
//////
//////		for(int i = 0; i < random; i++)
//////		{
//////
//////			item->above = new Node(key, str, item, nextptr, NULL, NULL, i+2, i+1, i);
//////		}
//////	}
////
////	// make a new key at the new location
////
////
////
////	// through randomized algorithm, add it to upper levels
////}
////
////
////
////#endif /* SKIPLIST_H_ */
