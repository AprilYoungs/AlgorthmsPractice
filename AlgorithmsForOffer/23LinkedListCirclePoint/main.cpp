//
//  main.cpp
//  23LinkedListCirclePoint
//
//  Created by April Yang on 2020/2/5.
//  Copyright © 2020 April Yang. All rights reserved.
//  链表中环的入口节点

#include <iostream>
#include "LinkedList.hpp"

/*
 如果一个链表中包含环，如何找出环的入口节点？例如，在如图3.8所示的链表中，环的入口节点是节点3.
 
        _________
       |        |
 1->2->3->4->5->6
 */

/// return the entry point if the linked list is has circle
/// @param pHeader pHeader
ListNode* findTheEntryPointOfCircle(ListNode *pHeader)
{
    if (pHeader == nullptr)
        return nullptr;
    
    // 1.判断是否是环形结构
    ListNode *pSlow = pHeader->m_pNext;
    if (pSlow == nullptr)
        return nullptr;
    
    ListNode *pFast = pSlow->m_pNext;
    while (pFast != nullptr
           && pFast->m_pNext != nullptr
           && pFast != pSlow ) {
        pFast = pFast->m_pNext->m_pNext;
        pSlow = pSlow->m_pNext;
    }
    
    // 没有重叠，没有环
    if (pFast!=pSlow)
        return nullptr;
    
    // 2.计算环的长度
    int circleLength = 0;
    ListNode *pBegin = pSlow;
    do {
        pSlow = pSlow->m_pNext;
        circleLength++;
    }
    while (pBegin != pSlow);
    
    // 3. 寻找交叉点
    ListNode *pAhead = pHeader;
    ListNode *pBehind = pHeader;
    while (circleLength-- > 0) {
        pAhead = pAhead->m_pNext;
    }
    while (pAhead != pBehind) {
        pAhead = pAhead->m_pNext;
        pBehind = pBehind->m_pNext;
    }
    
    return pBehind;
}


void Test(string testName, ListNode *pHeader, ListNode *expected)
{
    printf("%s begin: ", testName.c_str());
    
    if (findTheEntryPointOfCircle(pHeader) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void test1()
{
    vector<int> array{1, 2, 3, 4, 5};
    ListNode *pHead = makeAList(array);
    ListNode *pTail = findNode(pHead, 5);
    ListNode *expected = findNode(pHead, 3);
    pTail->m_pNext = expected;
    
    Test(__func__, pHead, expected);
    
}

void test2()
{
    vector<int> array{1, 2, 3, 4, 5};
    ListNode *pHead = makeAList(array);
//    ListNode *pTail = findNode(pHead, 5);
//    ListNode *expected = findNode(pHead, 3);
//    pTail->m_pNext = expected;
    
    Test(__func__, pHead, nullptr);
    
}

void test3()
{
    vector<int> array{1};
    ListNode *pHead = makeAList(array);
    pHead->m_pNext = pHead;
//    ListNode *pTail = findNode(pHead, 5);
//    ListNode *expected = findNode(pHead, 3);
//    pTail->m_pNext = expected;
    
    Test(__func__, pHead, pHead);
}

void test4()
{
    vector<int> array{1, 2, 3, 4, 5, 6, 7, 8};
    ListNode *pHead = makeAList(array);
    ListNode *pTail = findNode(pHead, 8);
    ListNode *expected = findNode(pHead, 3);
    pTail->m_pNext = expected;
    
    Test(__func__, pHead, expected);
    
}



int main(int argc, const char * argv[]) {
    
    test1();
    test2();
    test3();
    test4();
    
    return 0;
}
