//
//  main.cpp
//  24LinkListRevesed
//
//  Created by April Yang on 2020/2/5.
//  Copyright © 2020 April Yang. All rights reserved.
//  反转链表

#include <iostream>
#include "LinkedList.hpp"

/*
 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。链表节点定义如下：

 */

// 假设链表是直的
 ListNode* reverseLinkedList(ListNode *pHead)
{
    if (pHead == nullptr)
        return nullptr;
    
    ListNode *preNode = nullptr;
    ListNode *pNode = pHead;

    while (pNode != nullptr) {
        
        ListNode *pNext = pNode->m_pNext;
        pNode->m_pNext = preNode;
        preNode = pNode;
        pNode = pNext;
        
    }
    
    return preNode;
}

void Test(string testName, ListNode *pHead)
{
    printf("----------\n %s:\n", testName.c_str());
    
    printf("Original: ");
    printList(pHead);
    
    ListNode *reversed = reverseLinkedList(pHead);
   
    printf("Reversed: ");
    printList(reversed);
}

void test1()
{
    vector<int> arr{1, 2, 3, 4, 5, 6};
    ListNode *pHead = makeAList(arr);
    Test(__func__, pHead);
}

void test2()
{
    vector<int> arr{1};
    ListNode *pHead = makeAList(arr);
    Test(__func__, pHead);
}

void test3()
{
//    vector<int> arr{1};
//    ListNode *pHead = makeAList(arr);
    Test(__func__, nullptr);
}


int main(int argc, const char * argv[]) {
    
    test1();
    test2();
    test3();
    
    return 0;
}
