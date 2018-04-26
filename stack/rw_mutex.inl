inline RW_Mutex::RW_Mutex ()
{
	pthread_rwlock_init (&lock_, 0);
}

inline bool RW_Mutex::acquire_read ()
{
	return !pthread_rwlock_rdlock(&lock_);
}

inline bool RW_Mutex::acquire_write ()
{
	return !pthread_rwlock_wrlock(&lock_);
}

inline bool RW_Mutex::release ()
{
	return !pthread_rwlock_unlock (&lock_);
}
