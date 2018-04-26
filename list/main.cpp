#include "list.h"
#include "type.h"
#include <iostream>
#include <string>

using std::string;

typedef struct tagTest
{
    s32 m_nNum;
    s8 m_chLetter;
    string m_str;
} TTest;

void Print(CList<s32>& list);
void PrintTest(CList<TTest>& list);

s32 main()
{
    CList<s32> list;
    list.Insert(list.Begin(), 1);
    list.Insert(list.End(), 2);
    list.Insert(list.End(), 4);
    list.Insert((--(list.End())), 3);
    Print(list);

    list.Erase(++(list.Begin()));
    list.Erase(list.Begin());
    Print(list);

    std::cout << "Front=" << list.Front() << std::endl;
    std::cout << "Back=" << list.Back() << std::endl;

    // test struct
    TTest tStructA = {1, 'a', "test1"};
    TTest tStructB = {2, 'b', "test2"};
    TTest tStructC = {3, 'c', "test3"};

    CList<TTest> tList;
    tList.Insert(tList.Begin(), tStructA);
    tList.Insert(tList.End(), tStructB);
    tList.Insert(tList.End(), tStructC);
    PrintTest(tList);

    tList.Erase(++(tList.Begin()));
    tList.Erase(tList.Begin());
    PrintTest(tList);

    return 0;
}

void Print(CList<s32>& list)
{
    for (CList<s32>::TIterator it = list.Begin(); it != list.End(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
}

void PrintTest(CList<TTest>& list)
{
    for (CList<TTest>::TIterator it = list.Begin(); it != list.End(); ++it)
    {
        std::cout << (*it).m_nNum << " " << (*it).m_chLetter << " " << (*it).m_str << std::endl;
    }

    std::cout << std::endl;
}
