#ifndef LIST_H
#define LIST_H

template <typename T>
struct TListNode
{
    TListNode<T> *m_ptNext;
    TListNode<T> *m_ptPrev;
    T m_tData;
};
template <typename T> struct TListIterator {
    typedef TListIterator<T> TIterator;
    typedef TListNode<T> *PTLinkType;

    PTLinkType m_ptNode;

    TListIterator(PTLinkType ptNode);
    TListIterator();
    TListIterator(const TIterator& tIterator);

    bool operator==(const TIterator& tIterator) const;
    bool operator!=(const TIterator& tIterator) const;

    T& operator*() const;
    T* operator->() const;

    TIterator& operator++();
    TIterator operator++(int);
    TIterator& operator--();
    TIterator operator--(int);
};

template <typename T>
class CList
{
public:
    typedef TListIterator<T> TIterator;
    typedef TListNode<T> *PTLinkType;

    CList();
    ~CList();

    TIterator Begin();
    TIterator End();

    T Front();
    T Back();

    TIterator Insert(TIterator tPosition, const T& Value);
    TIterator Erase(TIterator tPosition);

private:
    PTLinkType m_ptNode;
};

#include "list.inl"
#endif /* LIST_H */
