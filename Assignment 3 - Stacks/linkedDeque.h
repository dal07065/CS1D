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
