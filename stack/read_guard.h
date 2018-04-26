/**
 * @file read_guard.h
 * @brief It guards acquiring read lock and releasing it.
 * @author Baoshan Ye <yebaoshan@gmail.com>
 */

#ifndef READ_GUARD_H
#define READ_GUARD_H

/**
 * @brief Guards read lock 
 */
template <typename T>
class Read_Guard
{
public:
	/**
	 * @brief Acquiring the read lock
	 * @param mutex class variable
	 */
	Read_Guard(T& mutex);
	~Read_Guard();
protected:
	T& mutex_;      ///< mutex class variable
};

#include "read_guard.inl"

#endif // READ_GUARD_H
