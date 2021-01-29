// Lina Kang
// CS1D MW 2:30 - 5:00 PM
// 09/23/2020
// This program explores the concept of binary tree and
// tests out its abilities through inserting items,
// in-order, pre-order, post-order, breadth-first traversals
// and hierarchical relationships

// -------------- OUTPUT -----------------
/*
 Lina Kang
 CS1D MW 2:30 - 5:00 PM
 09/23/2020
 This program explores the concept of binary tree and
 tests out its abilities through inserting items,
 in-order, pre-order, post-order, breadth-first traversals
 and hierarchical relationships


**In-Order Traversal**

 5 12 13 18 19 24 25 29 33 44 49 55 59 77 89 109 118 288 1001

**Pre-Order Traversal**

 89 59 19 13 5 12 18 25 24 33 29 44 55 49 77 288 109 118 1001

**Post-Order Traversal**

 12 5 18 13 24 29 49 55 44 33 25 19 77 59 118 109 1001 288 89

**Breadth-First Traversal**

 89 59 288 19 77 109 1001 13 25 118 5 18 24 33 12 29 44 55 49

**Print By Level**

Level 0: 89
Level 1: 59 288
Level 2: 19 77 109 1001
Level 3: 13 25 118
Level 4: 5 18 24 33
Level 5: 12 29 44
Level 6: 55
Level 7: 49

**Print Relationships of Nodes**

Node: 5
 - Parent: 13
 - Children: 12

Node: 12
 - Parent: 5

Node: 13
 - Parent: 19
 - Children: 5 18

Node: 18
 - Parent: 13

Node: 19
 - Parent: 59
 - Children: 13 25

Node: 24
 - Parent: 25

Node: 25
 - Parent: 19
 - Children: 24 33

Node: 29
 - Parent: 33

Node: 33
 - Parent: 25
 - Children: 29 44

Node: 44
 - Parent: 33
 - Children: 55

Node: 49
 - Parent: 55

Node: 55
 - Parent: 44
 - Children: 49

Node: 59
 - Parent: 89
 - Children: 19 77

Node: 77
 - Parent: 59

Node: 89
 - Children: 59 288

Node: 109
 - Parent: 288
 - Children: 118

Node: 118
 - Parent: 109

Node: 288
 - Parent: 89
 - Children: 109 1001

Node: 1001
 - Parent: 288
*/
// -------------- END OUTPUT -----------------

#include "binaryTree.h"

int main()
{
	// Input & Initialization
	NodeBinaryTree binaryTree;

	binaryTree.insert(89);

	Node * root = binaryTree.getroot();

	binaryTree.insert(59, root);
	binaryTree.insert(288, root);
	binaryTree.insert(19, root);
	binaryTree.insert(13, root);
	binaryTree.insert(5, root);
	binaryTree.insert(109, root);
	binaryTree.insert(12, root);
	binaryTree.insert(118, root);
	binaryTree.insert(25, root);
	binaryTree.insert(33, root);
	binaryTree.insert(1001, root);
	binaryTree.insert(18, root);
	binaryTree.insert(44, root);
	binaryTree.insert(77, root);
	binaryTree.insert(55, root);
	binaryTree.insert(24, root);
	binaryTree.insert(49, root);
	binaryTree.insert(29, root);



	// Output & Processing
	cout << " Lina Kang\n"
			" CS1D MW 2:30 - 5:00 PM\n"
			" 09/23/2020\n"
			" This program explores the concept of binary tree and\n"
			" tests out its abilities through inserting items,\n"
			" in-order, pre-order, post-order, breadth-first traversals\n"
			" and hierarchical relationships \n\n";

	cout << "\n**In-Order Traversal**\n\n";

	binaryTree.in_order(root);

	cout << "\n\n**Pre-Order Traversal**\n\n";

	binaryTree.pre_order(root);

	cout << "\n\n**Post-Order Traversal**\n\n";

	binaryTree.post_order(root);

	cout << "\n\n**Breadth-First Traversal**\n\n";

	binaryTree.breadth_first(root);

	cout << "\n\n**Print By Level**\n\n";

	binaryTree.printByLevel(root);

	cout << "\n**Print Relationships of Nodes**\n\n";

	binaryTree.printRelation(root);
}


