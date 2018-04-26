#include "list.h"

template <typename T>
TListIterator<T>::TListIterator()
{
}

template <typename T>
TListIterator<T>::TListIterator(PTLinkType ptNode): m_ptNode(ptNode)
{
}

template <typename T>
TListIterator<T>::TListIterator(const TIterator& tIterator):
     m_ptNode(tIterator.m_ptNode)
{
}

template <typename T>
bool TListIterator<T>::operator==(const TIterator& tIterator) const
{
    return m_ptNode == tIterator.m_ptNode;
}

template <typename T>
bool TListIterator<T>::operator!=(const TIterator& tIterator) const
{
    return m_ptNode != tIterator.m_ptNode;
}

template <typename T>
T& TListIterator<T>::operator*() const
{
    return m_ptNode->m_tData;
}

template <typename T>
T* TListIterator<T>::operator->() const
{
    return &(operator*());
}

template <typename T>
typename TListIterator<T>::TIterator& TListIterator<T>::operator++()
{
    m_ptNode = m_ptNode->m_ptNext;
    return *this;
}

template <typename T>
typename TListIterator<T>::TIterator TListIterator<T>::operator++(int)
{
    T tmp = *this;
    ++*this;
    return tmp;
}

template <typename T>
typename TListIterator<T>::TIterator& TListIterator<T>::operator--()
{
    m_ptNode = m_ptNode->m_ptPrev;
}

template <typename T>
typename TListIterator<T>::TIterator TListIterator<T>::operator--(int)
{
    T tmp = *this;
    --*this;
    return tmp;
}

// CList<T>
template <typename T>
CList<T>::CList()
{
    m_ptNode = new TListNode<T>();
    m_ptNode->m_ptNext = m_ptNode;
    m_ptNode->m_ptPrev = m_ptNode;
}

template <typename T>
CList<T>::~CList<T>()
{
    PTLinkType cur = m_ptNode->m_ptNext;
    while (cur != m_ptNode)
    {
        PTLinkType tmp = cur;
        cur = cur->m_ptNext;
        delete tmp;
    }

    delete m_ptNode;
}

template <typename T>
typename CList<T>::TIterator CList<T>::Begin()
{
   return m_ptNode->m_ptNext;
}

template <typename T>
typename CList<T>::TIterator CList<T>::End()
{
    return m_ptNode;
}

template <typename T>
T CList<T>::Front()
{
    return *Begin();
}

template <typename T>
T CList<T>::Back()
{
    return *(--End());
}

template <typename T>
typename CList<T>::TIterator CList<T>::Insert(TIterator tPosition, const T& Vaule)
{
    PTLinkType tmp = new TListNode<T>();
    tmp->m_tData = Vaule;
    tmp->m_ptNext = tPosition.m_ptNode;
    tmp->m_ptPrev = tPosition.m_ptNode->m_ptPrev;
    tPosition.m_ptNode->m_ptPrev->m_ptNext = tmp;
    tPosition.m_ptNode->m_ptPrev = tmp;

    return tmp;
}

template <typename T>
typename CList<T>::TIterator CList<T>::Erase(TIterator tPosition)
{
    tPosition.m_ptNode->m_ptPrev->m_ptNext = tPosition.m_ptNode->m_ptNext;
    tPosition.m_ptNode->m_ptNext->m_ptPrev = tPosition.m_ptNode->m_ptPrev;

    delete tPosition.m_ptNode;
}
