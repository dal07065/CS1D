/* ******************************************************
 * Assignment : 3 - Extendable Array
 * Name       : Lina Kang
 * Student ID : 1072568
 * CS1D       : MW 2:30 - 5:00
 * Due Date   : 09/21/20
 * ******************************************************
 * -------------------DESCRIPTION------------------------
 *

 *
 * ******************************************************
 * ----------------------OUTPUT-------------------------*/

#ifndef VECTOR_H_
#define VECTOR_H_

template<class T>
class vector
{
	vector();
//	vector(int n, T initialValue);
	int size();
	bool empty();
	int capacity();
	void pushback(T value);
};



#endif /* VECTOR_H_ */
