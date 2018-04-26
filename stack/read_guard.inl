template <typename T>
inline Read_Guard<T>::Read_Guard (T& mutex): mutex_(mutex)
{
	mutex_.acquire_read ();
}

template <typename T>
inline Read_Guard<T>::~Read_Guard ()
{
	mutex_.release ();
}
