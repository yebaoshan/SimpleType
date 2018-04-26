/**
 * @file write_guard.h
 * @brief It guards acquiring write lock and releasing it.
 * @author Baoshan Ye <yebaoshan@gmail.com> 
 */

#ifndef WRITE_GUARD_H
#define WRITE_GUARD_H

/**
 * @brief Guards write lock
 */
template <class T>
class Write_Guard
{
public:
	/**
	 * @brief Acquiring the write lock
	 * @param mutex class variable
	 */
	Write_Guard (T& mutex);
	~Write_Guard ();
protected:
	T& mutex_;    ///< mutex class variable
};

#include "write_guard.inl"

#endif // WRITE_GUARD_H
