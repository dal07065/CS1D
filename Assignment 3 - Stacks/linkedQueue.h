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
#endif  /* LINKEDDEQUE_H_ */
