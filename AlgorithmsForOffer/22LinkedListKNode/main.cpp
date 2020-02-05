//
//  main.cpp
//  22LinkedListKNode
//
//  Created by April Yang on 2020/2/5.
//  Copyright © 2020 April Yang. All rights reserved.
//  链表中倒数第K个节点

#include <iostream>
#include "LinkedList.hpp"

/*
 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。链表节点定义如下：
 */

ListNode* findTheBackwardKNode(ListNode *pHeader, int k)
{
    if (pHeader == nullptr && k < 1)
        return nullptr;
    
    // 3 k=2
    // ahead 2 behind 1
    ListNode *pAhead = pHeader;
    ListNode *pBehind = pHeader;
    for (int i=0; i < k-1; i++)
        if (pAhead->m_pNext != nullptr)
            pAhead = pAhead->m_pNext;
        else
            return nullptr;
    
    while (pAhead->m_pNext!=nullptr) {
        pAhead = pAhead->m_pNext;
        pBehind = pBehind->m_pNext;
    }
    
    return pBehind;
}

void Test(string testName, ListNode *pHeader, int k, ListNode *expected)
{
    printf("%s begin: ", testName.c_str());
    
    if (findTheBackwardKNode(pHeader, k) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void test1()
{
    vector<int> array{1, 2, 3, 4, 5};
    ListNode *pHead = makeAList(array);
    ListNode *expected = findNode(pHead, 4);
    int k = 2;
    Test(__func__, pHead, k, expected);
    
    destroyList(&pHead);
}

void test2()
{
    vector<int> array{1, 2, 3, 4, 5};
    ListNode *pHead = makeAList(array);
//    ListNode *expected = findNode(pHead, 4);
    int k = 10;
    Test(__func__, pHead, k, nullptr);
    
    destroyList(&pHead);
}

void test3()
{
    vector<int> array{1, 2, 3, 4, 5};
    ListNode *pHead = makeAList(array);
    ListNode *expected = findNode(pHead, 5);
    int k = 1;
    Test(__func__, pHead, k, expected);
    
    destroyList(&pHead);
}

void test4()
{
    vector<int> array{1};
    ListNode *pHead = makeAList(array);
    ListNode *expected = findNode(pHead, 1);
    int k = 1;
    Test(__func__, pHead, k, expected);
    
    destroyList(&pHead);
}


int main(int argc, const char * argv[]) {
    
    test1();
    test2();
    test3();
    test4();
    
    return 0;
}
