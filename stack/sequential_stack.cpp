#include "sequential_stack.h"

template <typename T, int SIZE> 
Sequential_Stack<T, SIZE>::Sequential_Stack (): top_(-1)
{
	if (SIZE < 1) 
		throw "The SIZE should be not less than 1";
}

template <typename T, int SIZE>
void Sequential_Stack<T, SIZE>::clear ()
{
	top_ = -1;	
}

template <typename T, int SIZE> 
int Sequential_Stack<T, SIZE>::length () const
{
	return top_ + 1;
}

template <typename T, int SIZE> 
bool Sequential_Stack<T, SIZE>::push (const T& el)
{
	if (top_ >= SIZE - 1)
		return false;

	top_ = top_ + 1;
	elements_[top_] = el;
	return true;
	
}

template <typename T, int SIZE> 
T Sequential_Stack<T, SIZE>::pop ()
{
	if (top_ <= -1)
		throw "There is not element";
	
	return elements_[top_--];
}

template <typename T, int SIZE> 
T Sequential_Stack<T, SIZE>::get_top () const
{
	if (top_ <= -1)
		throw "There is not element";
	return elements_[top_];
}

template <typename T, int SIZE> 
inline bool Sequential_Stack<T, SIZE>::full () const
{
	return (top_ >= SIZE - 1) ? true : false;
}

template <typename T, int SIZE> 
inline bool Sequential_Stack<T, SIZE>::empty () const
{
	return (top_ <= -1) ? true : false;
}


