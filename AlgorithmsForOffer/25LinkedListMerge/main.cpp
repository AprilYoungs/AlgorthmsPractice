//
//  main.cpp
//  25LinkedListMerge
//
//  Created by April Yang on 2020/2/5.
//  Copyright © 2020 April Yang. All rights reserved.
//  合并两个排序的链表

#include <iostream>
#include "LinkedList.hpp"

/*
 输入两个递增排序的链表，合并这两个链表并使新链表中的点仍然是递增排序的。
 例如，
 input:
    1->3->5->7
    2->4->6->8
 output:
    1->2->3->4->5->6->7->8
 */

ListNode* mergeLinkedList(ListNode *pHead1, ListNode *pHead2)
{
    if (pHead1==nullptr)
        return pHead2;
    else if (pHead2==nullptr)
        return pHead1;
    
    ListNode *pNode = nullptr;
    if (pHead1->m_nkey < pHead2->m_nkey)
    {
        pHead1->m_pNext = mergeLinkedList(pHead1->m_pNext, pHead2);
        pNode = pHead1;
    }
    else
    {
        pHead2->m_pNext = mergeLinkedList(pHead1, pHead2->m_pNext);
        pNode = pHead2;
    }
    
    return pNode;
}

void Test(string testName, ListNode *pHead1, ListNode *pHead2)
{
    printf("----------\n %s:\n", testName.c_str());
    
    printf("input:\n");
    printList(pHead1);
//    printf("\n");
    printList(pHead2);
    
    ListNode *merged = mergeLinkedList(pHead1, pHead2);
   
    printf("output:\n");
    printList(merged);
}

void test1()
{
    vector<int> arr1{1, 3, 5, 7};
    vector<int> arr2{2, 4, 6, 8};
    ListNode *pHead1 = makeAList(arr1);
    ListNode *pHead2 = makeAList(arr2);
    Test(__func__, pHead1, pHead2);
}

void test2()
{
    vector<int> arr1{1, 3, 5, 7};
    vector<int> arr2{2, 4, 6, 8};
    ListNode *pHead1 = makeAList(arr1);
//    ListNode *pHead2 = makeAList(arr2);
    Test(__func__, pHead1, nullptr);
}

void test3()
{
    vector<int> arr1{1, 3, 5, 7};
    vector<int> arr2{2, 4, 6, 8};
//    ListNode *pHead1 = makeAList(arr1);
//    ListNode *pHead2 = makeAList(arr2);
    Test(__func__, nullptr, nullptr);
}

void test4()
{
    vector<int> arr1{1};
    vector<int> arr2{2, 4, 6, 8};
    ListNode *pHead1 = makeAList(arr1);
    ListNode *pHead2 = makeAList(arr2);
    Test(__func__, pHead1, pHead2);
}

void test5()
{
    vector<int> arr1{1};
    vector<int> arr2{2};
    ListNode *pHead1 = makeAList(arr1);
    ListNode *pHead2 = makeAList(arr2);
    Test(__func__, pHead1, pHead2);
}

void test6()
{
    vector<int> arr1{1, 3, 5, 7};
    vector<int> arr2{2, 4, 5, 6, 6, 7};
    ListNode *pHead1 = makeAList(arr1);
    ListNode *pHead2 = makeAList(arr2);
    Test(__func__, pHead1, pHead2);
}

int main(int argc, const char * argv[]) {
    
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    
    return 0;
}
