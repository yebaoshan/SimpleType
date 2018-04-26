#include "linked_stack.h"

template <typename T>
Linked_Stack<T>::Linked_Stack (): top_(NULL)
{
}

template <typename T>
Linked_Stack<T>::~Linked_Stack ()
{
	clear();
}

template <typename T> 
void Linked_Stack<T>::clear ()
{	
	Node<T> *p;
	while (top_)
	{
		p = top_;
		top_ = top_->next;
		delete p;
	}
}

template <typename T> 
int Linked_Stack<T>::length () const
{
	int n = 0;
	Node<T> *p = top_;
	while (p)
	{
		n++;
		p = p->next;
	}
	return n;
}

template <typename T>
T Linked_Stack<T>::pop ()
{
	T el;
	Node<T> *p = top_;
	if (!top_)
		throw "There is not element";

	el = top_->value;
	top_ = top_->next;
	delete p;
	return el;
}

template <typename T>
T Linked_Stack<T>::get_top () const
{
	if (!top_)
		throw "There is not element";
	return top_->value;
}

template <typename T>
bool Linked_Stack<T>::push (const T& el)
{
	Node<T>* p;
	p = new Node<T>;
	p->value = el;
	p->next = top_;
	top_ = p;
	return true;
}

template <typename T>
bool Linked_Stack<T>::full () const
{
	return false;
}

template <typename T> 
bool Linked_Stack<T>::empty () const
{
	return top_ ? false : true;
}
