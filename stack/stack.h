/**
 * @file stack.h
 * @brief Stack wrapper class
 * @author Baoshan Ye <yebaoshan.scutech@gmail.com>
 */

#ifndef STACK_H
#define STACK_H

/**
 * @brief Stack wrapper class
 */
template <typename T, typename IMPL, typename MUTEX>
class Stack
{
public:
	Stack();

	/**
	 * @brief Clear all data function
	 */
	virtual void clear();

	/**
	 * @brief For length function
	 * @return Length of the stack
	 */
	virtual int length() const;

	/**
	 * @brief Judge full function
	 * @return Judgement Booleam value
	 */
	virtual bool full() const;

	/**
	 * @brief Judge empty function
	 * @return Judgement Booleam value
	 */
	virtual bool empty() const;

	/**
	 * @brief Push into stack function
	 * @param el The data of push into stack
	 * @return The state whether the data press into stack
	 */
	virtual bool push(const T& el);

	/**
	 * @brief Pop up stack function
	 * @return The data of poping up stack
	 */
	virtual T pop();

	/**
 	 * @brief Get the top element function
	 * @return The data of the top element
	 */
	virtual T get_top() const;
private:
	// Disable shadow/deep copy
	Stack (const Stack&);
	Stack operator = (const Stack&);
	mutable MUTEX mutex_;   ///< RW_Mutex class or Faked_Mutex class variable
	IMPL impl_;             ///< The Sequential_Stack class or Linked_Stack class variable
};

#include "stack.inl"

#endif  // STACK_H
