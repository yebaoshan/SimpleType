/**
 * @file sequential_stack.h
 * @brief The implementatation of sequential stack
 * @author BaoShan Ye <yebaoshan.scutech@gmail.com>
 */

#ifndef SEQUENTIAL_STACK_H
#define SEQUENTIAL_STACK_H

/**
 * @brief sequential stack class
 */
template <typename T, int SIZE>
class Sequential_Stack
{
public:
	Sequential_Stack ();

	/**
	 * @brief Clear all data function
	 */
	void clear ();

	/**
	 * @brief For length function
	 * @return Length of the stack
	 */
	int length () const;

	/**
	 *	@brief Push into stack function
	 * @param el The data of push into stack
	 * @return The state whether the data push into stack
	 */
	bool push (const T& el);

	/**
	 *	@brief Pop up stack function
	 * @return The data of poping up stack
	 */
	T pop ();

	/**
	 * @brief Get the top element function
	 * @return The data of the top element
	 */
	T get_top () const;

	/**
	 *	@brief Judge full function
	 * @return Judgement Booleam value
	 */
	bool full () const;

	/**
	 * @brief Judge empty function
	 * @return Judgement Booleam value
	 */
	bool empty () const;
protected:
	T elements_[SIZE];    ///< The array stores elements
	int top_;	          ///< The top element flag of the stack
};

#endif // SEQUENTIAL_STACK_H
