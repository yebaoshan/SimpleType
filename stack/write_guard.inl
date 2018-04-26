template <typename T>
inline Write_Guard<T>::Write_Guard (T& mutex): mutex_(mutex)
{
	mutex_.acquire_write();
}

template <typename T>
inline Write_Guard<T>::~Write_Guard ()
{
	mutex_.release();
}
