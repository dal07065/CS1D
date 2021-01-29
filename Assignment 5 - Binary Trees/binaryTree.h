#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Node
{
	int value;
	int level;
	Node * left;
	Node * right;
	Node * parent;
	Node() : value(0), level(0), left(NULL), right(NULL), parent(NULL) { }
};

//linked-list implementation
class NodeBinaryTree
{
public:
	NodeBinaryTree();
	int getsize() const;
	bool isempty() const;
	Node * getroot() const;

	void insert(int);
	void insert(int, Node*);

	bool isExternal(Node * v) const { return v->left == NULL && v->right == NULL; }
	bool isInternal(Node * v) const { return v->left != NULL || v->right != NULL; }

	void in_order(Node*) const;
	void post_order(Node*) const;
	void pre_order(Node*) const;
	void breadth_first(Node*) const;

	void printByLevel(Node *) const;
	void printRelation(Node *) const;

private:
	Node *root;
	Node *current;

	int size;
};
NodeBinaryTree::NodeBinaryTree()
{
	root = NULL;
	current = NULL;
	size = 0;
}
int NodeBinaryTree::getsize() const
{
	return size;
}
bool NodeBinaryTree::isempty() const
{
	return root == NULL ? true : false;
}
Node * NodeBinaryTree::getroot() const
{
	return root;
}
// insert function for ONLY root
void NodeBinaryTree::insert(int item)
{
  if(root!=NULL)
    insert(item, root);
  else
  {
	  Node * newNode = new Node;
	  root = newNode;
	  root->value=item;
	  root->left=NULL;
	  root->right=NULL;
	  size++;
  }
}
// insert function for descendants of root (recursive)
void NodeBinaryTree::insert(int item, Node * node)
{
	// compare the item to current node
	if(item < node->value)
	{
		//recursively repeat until an empty spot is found to insert
		if(node->left != NULL)
			insert(item, node->left);
		else
		{
			Node * newNode = new Node;

			node->left=newNode;

			newNode->value = item;
			newNode->left = NULL;
			newNode->right = NULL;
			newNode->parent = node;

			size++;
		}
	}
	else if(item >= node->value)
	{
		//recursively repeat until an empty spot is found to insert
		if(node->right != NULL)
			insert(item, node->right);
		else
		{
			Node * newNode = new Node;

			node->right = newNode;

			newNode->value = item;
			newNode->left = NULL;
			newNode->right = NULL;
			newNode->parent = node;

			size++;
		}
	}
}

// Prints the binary tree from leftmost node to rightmost node
// (the output is from smallest to largest in increasing order)
void NodeBinaryTree::in_order(Node * p) const
{
	if(p->left != NULL)
		in_order(p->left);
	cout << " " << p->value;
	if(p->right != NULL)
		in_order(p->right);
}

// Prints the binary tree where nodes are visited after its descendants
void NodeBinaryTree::post_order(Node * p) const
{
	if(p->left != NULL)
		post_order(p->left);
	if(p->right != NULL)
		post_order(p->right);
	cout << " " << p->value;
}

// Prints the binary tree where nodes are visited before its descendants
void NodeBinaryTree::pre_order(Node * p) const
{
	cout << " " << p->value;
	if(p->left != NULL)
		pre_order(p->left);
	if(p->right != NULL)
		pre_order(p->right);
}

// Prints the binary tree at a top-down approach visiting nodes by level
void NodeBinaryTree::breadth_first(Node * p) const
{
	Node * current;

	queue<Node *> que;						// utilize a queue to add nodes
	que.push(p);							// and add the descendants

	while(que.size() > 0)
	{
		// get first value from queue, print that value, pop the value
		current = que.front();
		que.pop();
		cout << " "<< current->value;

		// enqueue descendants if they exist
		if(current->left != NULL)
			que.push(current->left);
		if(current->right != NULL)
			que.push(current->right);
	}
}

// Prints the binary trees divided by levels and nodes within those levels
// (similar algorithm from breadth_first traversal)
void NodeBinaryTree::printByLevel(Node * p) const
{
	Node * current;

	queue<Node *> que;
	que.push(p);

	int level = 0;
	cout << "Level " << level << ": ";

	while(que.size() > 0)
	{
		current = que.front();
		que.pop();
		cout << current->value << " ";

		if(current->left != NULL)
		{
			// designate a level to each node
			// (since current->left is a child of current, their level is
			//  1 + current's level)
			current->left->level = current->level + 1;
			que.push(current->left);

		}
		if(current->right != NULL)
		{
			current->right->level = current->level + 1;
			que.push(current->right);
		}

		// to prevent the next if condition from bugging out when size == 0
		if(que.size() == 0)
			break;
		// if the next node in queue is starting at next level,
		// print a new line and print "Level"
		else if(current->level < que.front()->level )
		{
			level++;
			cout << endl << "Level " << level << ": ";
		}

	}
	cout << endl;
}
// Print the relationship of the nodes
// (same algorithm from in-order traversal)
void NodeBinaryTree::printRelation(Node * p) const
{
	if(p->left != NULL)
		printRelation(p->left);

	// -------- Output ----------
	cout << "Node: "  << p->value;

	if(p != root)
		cout << "\n - Parent: "   << p->parent->value;
	if(!isExternal(p))
	{
		cout << "\n - Children: ";
		if(p->left != NULL)
			cout << p->left->value << " ";
		if(p->right != NULL)
			cout << p->right->value;
	}
	cout << endl << endl;
	// ------ End Output --------

	if(p->right != NULL)
		printRelation(p->right);
}

#endif /* BINARYTREE_H_ */
