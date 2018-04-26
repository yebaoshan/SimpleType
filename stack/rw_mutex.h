/**
 * @file rw_mutex.h
 * @brief Read-Write mutex
 * @author Baoshan Ye <yebaoshan@gmail.com>
 */

#ifndef RW_MUTEX_H
#define RW_MUTEX_H

#include <pthread.h>

/**
 * @brief Read-Write mutex
 */
class RW_Mutex
{
public:
	RW_Mutex ();

	/**
	 * @brief Acquire read mutex
	 */
	bool acquire_read ();

	/**
	 * @brief Acquire write lock
	 */
	bool acquire_write ();

	/**
	 * @brief Release the lock
	 */
	bool release ();
private:
	RW_Mutex (const RW_Mutex&);
	RW_Mutex operator = (const RW_Mutex&);

	pthread_rwlock_t lock_;  ///< Reader-Write mutex
};

#include "rw_mutex.inl"

#endif // RW_MUTEX_H
