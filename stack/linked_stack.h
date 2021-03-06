/**
 * @file linked_stack.h
 * @brief The implementatation of linked stack
 * @author BaoShan Ye <yebaoshan.scutech@gmail.com>
 */

#ifndef LINKED_STACK_H
#define LINKED_STACK_H

/**
 * @brief The definition of the node on the Linked stack
 */
template <typename T>
struct Node
{
	T value;                ///< Storing value of th node 
	Node* next;            ///< Pointing to the next node pointer
};

/**
 * @brief Linked stack class
 */
template <typename T>
class Linked_Stack
{
public:
	Linked_Stack ();
	~Linked_Stack ();

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
	 * @brief Pop up stack function
	 * @return The data of poping up stack
	 */
	T pop ();

	/**
	 *	@brief Get the top element function
	 * @return The data of the top element
	 */
	T get_top () const;

	/**
	 * @brief Push into stack function
	 * param el The data of push into stack
	 * @return The state whether the data push into stack
	 */
	bool push (const T& el);

	/**
	 * @brief Judge full function
	 * @return Judgement Booleam value
	 */
	bool full () const;

	/**
	 * @brief Judge empty function
	 * @return Judgement Booleam value
	 */
	bool empty () const;
protected:
	Node<T>* top_;   ///< The top element flag of the stack
};

#endif // LINKED_STACK_H
