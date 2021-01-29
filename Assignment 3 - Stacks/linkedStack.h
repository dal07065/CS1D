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

#endif  /* LINKEDDEQUE_H_ */
