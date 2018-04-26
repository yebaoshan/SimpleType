/**
 * @file faked_mutex.h
 * @brief No mutex class
 * @author Baoshan Ye <yebaoshan@gmail.com>
 */

#ifndef FAKED_MUTEX_H
#define FAKED_MUTEX_H

/**
 * @brief No mutex class
 */
class Faked_Mutex
{
public:
	/**
	 * @brief acquire read lock 
	 */
	bool acquire_read (){};

	/**
	 * @brief acquire write lock
	 */
	bool acquire_write (){};

	/**
	 * @brief release the lock
	 */
	bool release (){};
};

#endif // Faked_MUTEX_H
