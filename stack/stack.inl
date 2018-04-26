#include "read_guard.h"
#include "write_guard.h"

template <typename T, typename IMPL, typename MUTEX>
inline Stack<T, IMPL, MUTEX>::Stack ()
{
}

template <typename T, typename IMPL, typename MUTEX>
inline void Stack<T, IMPL, MUTEX>::clear ()
{
	Write_Guard<MUTEX> guard (mutex_);
	return impl_.clear ();
}

template <typename T, typename IMPL, typename MUTEX>
inline int Stack<T, IMPL, MUTEX>::length () const
{
	Read_Guard<MUTEX> guard (mutex_);
	return impl_.length ();	
}

template <typename T, typename IMPL, typename MUTEX>
inline bool Stack<T, IMPL, MUTEX>::full () const
{
	Read_Guard<MUTEX> guard (mutex_);
	return impl_.full ();
}

template <typename T, typename IMPL, typename MUTEX>
inline bool Stack<T, IMPL, MUTEX>::empty () const
{
	Read_Guard<MUTEX> guard (mutex_);
	return impl_.empty ();
}

template <typename T, typename IMPL, typename MUTEX>
inline bool Stack<T, IMPL, MUTEX>::push (const T& el)
{
	Write_Guard<MUTEX> guard (mutex_);
	return impl_.push (el);
}

template <typename T, typename IMPL, typename MUTEX>
inline T Stack<T, IMPL, MUTEX>::pop ()
{
	Write_Guard<MUTEX> guard (mutex_);
	return impl_.pop();	
}

template <typename T, typename IMPL, typename MUTEX>
inline T Stack<T, IMPL, MUTEX>::get_top () const
{
	Read_Guard<MUTEX> guard (mutex_);
  	return impl_.get_top();
}
