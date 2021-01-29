/* ******************************************************
 * Assignment : 3 - Stacks Queue Deque
 * Name       : Lina Kang
 * Student ID : 1072568
 * CS1D       : MW 2:30 - 5:00
 * Due Date   : 09/09/20
 * ******************************************************
 * -------------------DESCRIPTION------------------------
 *
 * This assignment involves different practices of
 * stacks, queues, and deques, both STL and non-STL,
 * using push and pop methods
 *
 * ******************************************************
 * ----------------------OUTPUT-------------------------

******************************************************
* Assignment : 3 - Stacks Queue Deque
* Name       : Lina Kang
* Student ID : 1072568
* CS1D       : MW 2:30 - 5:00
* Due Date   : 09/09/20
******************************************************
This assignment involves different practices of
stacks, queues, and deques, both STL and non-STL,
using push and pop methods

------------------------------
Part A: Print Stack Top to Bottom
String Stack   Double Stack
------------------------------
Don            88.64
Mark           2019.1
JoAnn          123.123
Eric           200.12
Jordyn         888.55
Jennifer

------------------------------
Part B: Deletion of "Jordyn" and "123.123"
String Stack   Double Stack
------------------------------
Jennifer       200.12
               888.55

------------------------------
Part C: Implement a linked list stack
String Stack   Double Stack
------------------------------
Don            88.64
Mark           2019.1
JoAnn          123.123
Eric           200.12
Jordyn         888.55
Jennifer

------------------------------
Part C: Deletion of "Jordyn" and "123.123"
String Stack   Double Stack
------------------------------
Jennifer       200.12
               888.55

------------------------------
Part E: Implement Queue
String Queue   Double Queue
------------------------------
Jennifer       888.55
Jordyn         200.12
Eric           123.123
JoAnn          2019.1
Mark           88.64
Don

------------------------------
Part F: Deletion of "JoAnn" and "123.123"
String Queue   Double Queue
------------------------------
Mark           2019.1
Don            88.64

------------------------------
Part G: Implement Deque
String Deque   Double Deque
------------------------------
Jennifer       888.55
Jordyn         200.12
Eric           123.123
JoAnn          2019.1
Mark           88.64
Don

------------------------------
Part H: Deletion of "JoAnn" and "200.12"
String Deque   Double Deque
------------------------------
Jennifer       123.123
Jordyn         2019.1
               88.64

-------------------------------
Part I: Parentheses Match Check
-------------------------------
True: {2x+5}(6x+4)
True: (12x+6){2x-4}
True: (2x+7)(12x+6)
False: {{8x+5)-5x[9x+3]})
False: (((4x+8)-x[4x+3])))
True: [(5x-5)-4x[6x+2]]

 * ******************************************************/

#include <iomanip>
#include <stack>
#include "linkedStack.h"
#include "linkedQueue.h"
#include "linkedDeque.h"

//print Stack
void print(stack<string> str, stack<double> dob, string partDescription)
{
    cout << left;
    cout << "------------------------------" << endl << 
            "Part " << partDescription << endl;
    cout << setw(15) << "String Stack" << 
            setw(15) << "Double Stack" << endl <<
            "------------------------------" << endl;

    // Determine how many lines should be printed
    int loop = 6;
    if(dob.size() > str.size()) loop = dob.size();
    else loop = str.size();

    // Print whatever is remaining within the containers
    for(int i = 0; i < loop; i++)
    {
        if(!str.empty())
        {
            cout << setw(15) << str.top();
            str.pop();        
        }
        else // prints an empty column if container is emptied out
        {
            cout << setw(15) << " ";
        }
        if(!dob.empty())
        {
            cout << setw(15) << dob.top();
            dob.pop();
        }
        else // prints an empty column if container is emptied out
        {
            cout << setw(15) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//print LinkedStackType
void print(linkedStackType<string> str, linkedStackType<double> dob, string partDescription)
{
    cout << left;
    cout << "------------------------------" << endl << 
            "Part " << partDescription << endl;
    cout << setw(15) << "String Stack" << 
            setw(15) << "Double Stack" << endl <<
            "------------------------------" << endl;

    int loop = 6;
    if(dob.getSize() > str.getSize()) loop = dob.getSize();
    else loop = str.getSize();

    for(int i = 0; i < loop; i++)
    {
        if(!str.isEmptyStack())
        {
            cout << setw(15) << str.getTop();
            str.pop();        
        }
        else
        {
            cout << setw(15) << " ";
        }
        
        if(!dob.isEmptyStack())
        {
            cout << setw(15) << dob.getTop();
            dob.pop();
        }
        else
        {
            cout << setw(15) << " ";
        }
        
        cout << endl;
    }

    cout << endl;
}

//print QueueType
void print(linkedQueueType<string> str, linkedQueueType<double> dob, string partDescription)
{
    cout << left;
    cout << "------------------------------" << endl << 
            "Part " << partDescription << endl;
    cout << setw(15) << "String Queue" <<
            setw(15) << "Double Queue" << endl <<
            "------------------------------" << endl;

    nodeType<string> *currentStr = str.getFront();
    nodeType<double> *currentDob = dob.getFront();

    int loop = 6;
    if(dob.getSize() > str.getSize()) loop = dob.getSize();
    else loop = str.getSize();

    for(int i = 0; i < loop; i++)
    {
        if(currentStr != NULL)
        {
            cout << setw(15) << currentStr->info;
            currentStr = currentStr->link;
        }
        else
        {
            cout << setw(15) << " ";
        }
        
        if(currentDob != NULL)
        {
            cout << setw(15) << currentDob->info;
            currentDob = currentDob->link;
        }
        else
        {
            cout << setw(15) << " ";
        }
        
        cout << endl;
    }

    cout << endl;
}

//print Deque
void print(linkedDequeType<string> str, linkedDequeType<double> dob, string partDescription)
{
    cout << left;
    cout << "------------------------------" << endl <<
            "Part " << partDescription << endl;
    cout << setw(15) << "String Deque" <<
            setw(15) << "Double Deque" << endl <<
            "------------------------------" << endl;

    nodeDeque<string> *currentStr = str.getTop();
    nodeDeque<double> *currentDob = dob.getTop();

    int loop = 6;
    if(dob.getSize() > str.getSize()) loop = dob.getSize();
    else loop = str.getSize();

    for(int i = 0; i < loop; i++)
    {
        if(currentStr != NULL)
        {
            cout << setw(15) << currentStr->info;
            currentStr = currentStr->back;
        }
        else
        {
            cout << setw(15) << " ";
        }

        if(currentDob != NULL)
        {
            cout << setw(15) << currentDob->info;
            currentDob = currentDob->back;
        }
        else
        {
            cout << setw(15) << " ";
        }

        cout << endl;
    }

    cout << endl;
}

// Checks whether parentheses match on an equation using linkedStackType
bool ParenMatch(string X, int n)
{
	linkedStackType<char> S;

	//uses switch statements to cover 3 different types of grouping symbols
	for(int i = 0; i < n; i++)
	{
		switch(X[i])
		{
		case '(':
			S.push(X[i]);
			break;
		case '{':
			S.push(X[i]);
			break;
		case '[':
			S.push(X[i]);
			break;
		case ')':
			if(S.isEmptyStack())
				return false;
			else if(S.getTop() == '(')
				S.pop();
			else
				return false;
			break;
		case '}':
			if(S.isEmptyStack())
				return false;
			else if(S.getTop() == '{')
				S.pop();
			else
				return false;
			break;
		case ']':
			if(S.isEmptyStack())
				return false;
			else if(S.getTop() == '[')
				S.pop();
			else
				return false;
			break;
		default:
			break;
		}
	}
	return true;
}
int main()
{
    cout << "******************************************************\n"
    		"* Assignment : 3 - Stacks Queue Deque \n"
    		"* Name       : Lina Kang \n"
    		"* Student ID : 1072568 \n"
    		"* CS1D       : MW 2:30 - 5:00 \n"
    		"* Due Date   : 09/09/20 \n"
    		"******************************************************\n"
    		"This assignment involves different practices of \n"
    		"stacks, queues, and deques, both STL and non-STL, \n"
    		"using push and pop methods  \n\n";

    // A - Implement a Stack

    stack <string> stackString;
    stack <double> stackDouble;

    stackString.push("Jennifer");
    stackString.push("Jordyn");
    stackString.push("Eric");
    stackString.push("JoAnn");
    stackString.push("Mark");
    stackString.push("Don");

    stackDouble.push(888.55);
    stackDouble.push(200.12);
    stackDouble.push(123.123);
    stackDouble.push(2019.1);
    stackDouble.push(88.64);

    print(stackString, stackDouble,
    	  "A: Print Stack Top to Bottom");

    // B - Perform Deletion from a stack

    stackString.pop();
    stackString.pop();
    stackString.pop();
    stackString.pop();
    stackString.pop();
    
    stackDouble.pop();
    stackDouble.pop();
    stackDouble.pop();

    print(stackString, stackDouble,
    	  "B: Deletion of \"Jordyn\" and \"123.123\"");

    // C - Implement a non-STL stack

    linkedStackType<string> linkedString;
    linkedStackType<double> linkedDouble;

    linkedString.push("Jennifer");
    linkedString.push("Jordyn");
    linkedString.push("Eric");
    linkedString.push("JoAnn");
    linkedString.push("Mark");
    linkedString.push("Don");

    linkedDouble.push(888.55);
    linkedDouble.push(200.12);
    linkedDouble.push(123.123);
    linkedDouble.push(2019.1);
    linkedDouble.push(88.64);

    print(linkedString, linkedDouble,
    	  "C: Implement a linked list stack");
    
    // D - Perform Deletion from non-STL stack

    linkedString.pop();
    linkedString.pop();
    linkedString.pop();
    linkedString.pop();
    linkedString.pop();
    
    linkedDouble.pop();
    linkedDouble.pop();
    linkedDouble.pop();

    print(linkedString, linkedDouble,
    	  "C: Deletion of \"Jordyn\" and \"123.123\"");

    // E - Implement a non-STL queue

    linkedQueueType<string> queueString;
    linkedQueueType<double> queueDouble;

    queueString.addQueue("Jennifer");
    queueString.addQueue("Jordyn");
    queueString.addQueue("Eric");
    queueString.addQueue("JoAnn");
    queueString.addQueue("Mark");
    queueString.addQueue("Don");

    queueDouble.addQueue(888.55);
    queueDouble.addQueue(200.12);
    queueDouble.addQueue(123.123);
    queueDouble.addQueue(2019.1);
    queueDouble.addQueue(88.64);

    print(queueString, queueDouble, "E: Implement Queue");

    // F - Perform Deletion of queue

    queueString.deQueue();
    queueString.deQueue();
    queueString.deQueue();
    queueString.deQueue();

    queueDouble.deQueue();
    queueDouble.deQueue();
    queueDouble.deQueue();

    print(queueString, queueDouble,
    	  "F: Deletion of \"JoAnn\" and \"123.123\"");

    // G - Implement a non-STL deque

    linkedDequeType<string> dequeString;
    linkedDequeType<double> dequeDouble;

    dequeString.pushTop("Jennifer");
    dequeString.pushTop("Jordyn");
    dequeString.pushTop("Eric");
    dequeString.pushTop("JoAnn");
    dequeString.pushTop("Mark");
    dequeString.pushTop("Don");

    dequeDouble.pushTop(888.55);
    dequeDouble.pushTop(200.12);
    dequeDouble.pushTop(123.123);
    dequeDouble.pushTop(2019.1);
    dequeDouble.pushTop(88.64);

    print(dequeString, dequeDouble, "G: Implement Deque");

    // H - Perform Deletion from deque

    dequeString.popTop();
    dequeString.popTop();
    dequeString.popTop();
    dequeString.popTop();

    dequeDouble.popBottom();
    dequeDouble.popBottom();

    print(dequeString, dequeDouble,
    	  "H: Deletion of \"JoAnn\" and \"200.12\"");

    // I - Partheneses Match Algorithm

    cout << "-------------------------------"  << endl <<
    		"Part I: Parentheses Match Check" << endl <<
    		"-------------------------------"  << endl;

    string a = "{2x+5}(6x+4)";
    string b = "(12x+6){2x-4}";
    string c = "(2x+7)(12x+6)";
    string d = "{{8x+5)-5x[9x+3]})";
    string e = "(((4x+8)-x[4x+3])))";
    string f = "[(5x-5)-4x[6x+2]]";

    if(ParenMatch(a, a.length()))
    	cout << "True: " << a << endl;
    else
    	cout << "False: " << a << endl;

    if(ParenMatch(b, b.length()))
    	cout << "True: " << b << endl;
    else
    	cout << "False: " << b << endl;

    if(ParenMatch(c, c.length()))
    	cout << "True: " << c << endl;
    else
    	cout << "False: " << c << endl;

    if(ParenMatch(d, d.length()))
    	cout << "True: " << d << endl;
    else
    	cout << "False: " << d << endl;

    if(ParenMatch(e, e.length()))
    	cout << "True: " << e << endl;
    else
    	cout << "False: " << e << endl;

    if(ParenMatch(f, f.length()))
    	cout << "True: " << f << endl;
    else
    	cout << "False: " << f << endl;

}

// Header files - linkedStack.h, linkedQueue.h, linkedDeque.h

#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_

#include <iostream>
using namespace std;

template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};
template <class Type>
class linkedStackType
{
public:
    bool isEmptyStack();
    bool isFullStack();
    Type getTop();
    void push(const Type&newItem);
    void pop(Type & poppedElement);
    linkedStackType();
    linkedStackType(const linkedStackType<Type>& otherStack);
    ~linkedStackType();

    void pop();
    int getSize() const;

private:
    nodeType<Type> *top; //pointer to the stack};
    int size;
};

template <class Type>
bool linkedStackType<Type>::isEmptyStack()
{
    return(top==NULL);
}

template <class Type>
bool linkedStackType<Type>::isFullStack()
{
    return 0;
}

template <class Type>
Type linkedStackType<Type>::getTop()
{
    return top->info;
}

template<class Type>
void linkedStackType<Type>::push(const Type& newElement)
{
    nodeType<Type> *newNode;

    newNode = new nodeType<Type>;
    newNode->info = newElement;
    newNode->link = top;
    top = newNode;

    size++;
}

template <class Type>
void linkedStackType<Type>::pop()
{
    nodeType <Type> *temp;

    temp = top;
    top = top->link;
    delete temp;
    size--;
}
template <class Type>
void linkedStackType<Type>::pop(Type& poppedElement)
{
    nodeType <Type> *temp;
    poppedElement = top->info;

    temp = top;
    top = top->link;
    delete temp;
    size--;
}
template<class Type>
linkedStackType<Type>::linkedStackType()
{
    top = NULL;
    size = 0;
}

template<class Type>
linkedStackType<Type>::linkedStackType(const linkedStackType<Type>& otherStack)
{
    nodeType<Type> *newNode, *current, *last;

    if(otherStack.top == NULL)
        top = NULL;
    else
    {
        current = otherStack.top;

        top = new nodeType<Type>;
        top->info = current->info;
        top->link = NULL;

        last = top;

        current = current->link;

        while(current != NULL)
        {
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = NULL;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }

    }
    size = otherStack.getSize();

}

template <class Type>
linkedStackType<Type>::~linkedStackType()
{
    nodeType<Type> *temp;

    while(top != NULL)
    {
        temp = top;
        top = top->link;
        delete temp;
    }
}
template <class Type>
int linkedStackType<Type>::getSize() const
{
    return size;
}

#endif /* LINKEDSTACK_H_ */

#ifndef LINKEDQUEUE_H_
#define LINKEDQUEUE_H_

#include <iostream>
using namespace std;

template <class Type>
class linkedQueueType
{
public:
    bool isEmptyQueue();
    void addQueue(const Type &newElement);
    void deQueue();
    linkedQueueType();
    linkedQueueType(const linkedQueueType<Type> &otherQueue);
    ~linkedQueueType();

    nodeType<Type>* getFront();
    int getSize() const;
private:
    nodeType<Type> *front;
    nodeType<Type> *rear;
    int size;
};

template <class Type>
bool linkedQueueType<Type>::isEmptyQueue()
{
    return (front == NULL);
}
template <class Type>
void linkedQueueType<Type>::addQueue(const Type &newElement)
{
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;
    newNode->info = newElement;
    newNode->link = NULL;
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->link = newNode;
        rear = rear->link;
    }
    size++;
}

template <class Type>
void linkedQueueType<Type>::deQueue()
{
    nodeType<Type> *temp;
    temp = front;
    front = front->link;
    delete temp;
    if (front == NULL)
        rear = NULL;
    size--;
}
template <class Type>
linkedQueueType<Type>::linkedQueueType()
{
    front = NULL;
    rear = front;
    size = 0;
}
template <class Type>
linkedQueueType<Type>::linkedQueueType(const linkedQueueType<Type> &otherQueue)
{
	front = NULL;
	rear = NULL;
	size = 0;

    nodeType<Type> *current;
    current = otherQueue.front;
    while(current != NULL)
    {
    	addQueue(current->info);
    	current = current->link;
    }
}
template <class Type>
linkedQueueType<Type>::~linkedQueueType()
{
    nodeType<Type> *temp;
    while (front != NULL)
    {
        temp = front;
        front = front->link;
        delete temp;
    }
    rear = NULL;
}
template <class Type>
nodeType<Type>* linkedQueueType<Type>::getFront()
{
    return front;
}
template <class Type>
int linkedQueueType<Type>::getSize() const
{
    return size;
}
#endif /* LINKEDQUEUE_H_ */

#ifndef LINKEDDEQUE_H_
#define LINKEDDEQUE_H_

template <class Type>
struct nodeDeque
{
    Type info;
    nodeDeque<Type> *front;
    nodeDeque<Type> *back;
};

template <class Type>
class linkedDequeType
{
public:
	bool isEmptyDeque();
	void pushTop(Type);
	void pushBottom(Type);
	void popTop();
	void popBottom();
	linkedDequeType();
	linkedDequeType(const linkedDequeType<Type> &);
	~linkedDequeType();

	nodeDeque<Type>* getTop();
	nodeDeque<Type>* getBottom();
	int getSize() const;

private:
	nodeDeque<Type> *top;
	nodeDeque<Type> *bottom;
	nodeDeque<Type> *temp;
	int size;
};
template <class Type>
linkedDequeType<Type>::linkedDequeType()
{
	top = NULL;
	bottom = NULL;
	temp = NULL;
	size = 0;
}
template <class Type>
linkedDequeType<Type>::linkedDequeType(const linkedDequeType<Type>& otherDeque)
{
	top = NULL;
	bottom = NULL;
	size = 0;

    temp = otherDeque.top;
    while(temp != NULL)
    {
    	pushTop(temp->info);
    	temp = temp->back;
    }
}
template <class Type>
linkedDequeType<Type>::~linkedDequeType()
{
    while(top != NULL)
    {
        temp = top;
        top = top->back;
        delete temp;
    }
}
template <class Type>
bool linkedDequeType<Type>::isEmptyDeque()
{
	if(top == NULL && bottom == NULL)
		return true;
	return false;
}
template <class Type>
void linkedDequeType<Type>::pushTop(Type item)
{
	nodeDeque<Type> *newNode = new nodeDeque<Type>;
	newNode->info = item;
	if(top != NULL)
	{
		top->front = newNode;
		newNode->back = top;
		newNode->front = NULL;
		top = newNode;
	}
	else
	{
		top = newNode;
		bottom = newNode;
		top->front = NULL;
		top->back = bottom;
		bottom->front = newNode;
		bottom->back = NULL;
	}
	size++;
}
template <class Type>
void linkedDequeType<Type>::pushBottom(Type item)
{
	nodeDeque<Type> *newNode = new nodeDeque<Type>;
	newNode->info = item;
	if(top != NULL)
	{
		bottom->back = newNode;
		newNode->front = bottom;
		newNode->back = NULL;
		bottom = newNode;
	}
	else
	{
		top = newNode;
		bottom = newNode;
		top->front = NULL;
		top->back = bottom;
		bottom->front = newNode;
		bottom->back = NULL;
	}
	size++;
}
template <class Type>
void linkedDequeType<Type>::popTop()
{
	temp = top;
	top = top->back;
	top->front = NULL;
	delete temp;
	size--;
}
template <class Type>
void linkedDequeType<Type>::popBottom()
{
	temp = bottom;
	bottom = bottom->front;
	bottom->back = NULL;
	delete temp;
	size--;
}
template <class Type>
nodeDeque<Type>* linkedDequeType<Type>::getTop()
{
	return top;
}
template <class Type>
nodeDeque<Type>* linkedDequeType<Type>::getBottom()
{
	return bottom;
}
template <class Type>
int linkedDequeType<Type>::getSize() const
{
    return size;
}

#endif /* LINKEDDEQUE_H_ */
