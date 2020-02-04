//
//  main.cpp
//  18LinkedList
//
//  Created by April Yang on 2020/2/4.
//  Copyright © 2020 April Yang. All rights reserved.
//  链表考察

#include <iostream>
#include <vector>
using namespace std;

/*
 题目1: 在O(1)时间内删除链表节点。
 给定单向链表的头指针和一个节点指针，定义一个函数在O(1)时间内删除该节点。链表节点与函数的定义如下
 */

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
    
    ListNode(int value){m_nValue=value; m_pNext=nullptr;}
};

/// make list
ListNode * VecToList(vector<int> &arr)
{
    ListNode *header = nullptr;
    ListNode *last = nullptr;
    for (int i=0; i<arr.size(); i++)
    {
        ListNode *node = new ListNode(arr[i]);
        if (i == 0)
        {
            header = node;
            last = node;
        }
        else
        {
            last->m_pNext = node;
            last = node;
        }
    }
    
    return header;
}

/// 找节点
/// @param header header
/// @param value value
ListNode* findNode(ListNode *header, int value)
{
    if (header == nullptr)
        return nullptr;
    
    ListNode *node = header;
    while (node!=nullptr && node->m_nValue != value) {
        node = node->m_pNext;
    }
    
    return node;
}


/// 打印链表
/// @param header header
void printList(ListNode *header)
{
    if (header == nullptr)
        return;
    
//    printf("Begin print list:\n");
    ListNode *node = header;
    while (node != nullptr) {
        printf("%d\t", node->m_nValue);
        node = node->m_pNext;
    }
    printf("\n");
}

/// 假设被删除的节点一定存在
/// @param pToBeDeleted pToBeDeleted node
void DeleteNode(ListNode** pListHeader, ListNode *pToBeDeleted)
{
    if (pToBeDeleted == nullptr || pListHeader == nullptr)
        return;
    
    //如果被删除的节点在中间
    if (pToBeDeleted->m_pNext != nullptr)
    {
        ListNode *pNext = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue = pNext->m_nValue;
        pToBeDeleted->m_pNext = pNext->m_pNext;
        delete pNext;
    }
    else if (*pListHeader == pToBeDeleted)
    {
        // 只有一个节点
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        *pListHeader = nullptr;
    }
    else
    {
        // 被删除的节点被末尾
        ListNode *node = *pListHeader;
        while (node->m_pNext!=pToBeDeleted) {
               node = node->m_pNext;
        }
        node->m_pNext = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}

void Test(string testName, ListNode **pListHeader, ListNode *pTobeDeleted)
{
    printf("--------------\n%s:\n", testName.c_str());
    printf("Before:\t");
    printList(*pListHeader);
    if (pTobeDeleted == nullptr)
        printf("Deleted node: nullptr\n");
    else
        printf("Deleted node: %d\n", pTobeDeleted->m_nValue);
    DeleteNode(pListHeader, pTobeDeleted);
    printf("After:\t");
    printList(*pListHeader);
}

void test1()
{
    vector<int> arr = {1, 2, 3, 4};
    ListNode *header = VecToList(arr);
    
    ListNode *node = findNode(header, 3);
    
    Test(__func__, &header, node);
}

void test2()
{
    vector<int> arr = {1, 2, 3, 4};
    ListNode *header = VecToList(arr);
    
    ListNode *node = findNode(header, 4);
    
    Test(__func__, &header, node);
}

void test3()
{
    vector<int> arr = {1};
    ListNode *header = VecToList(arr);
    
    ListNode *node = findNode(header, 1);
    
    Test(__func__, &header, node);
}

void test4()
{
    vector<int> arr = {1, 2, 3, 4};
    ListNode *header = VecToList(arr);
    
    ListNode *node = findNode(header, 1);
    
    Test(__func__, &header, node);
}

void test5()
{
    vector<int> arr = {1, 2, 3, 4};
    ListNode *header = VecToList(arr);
    
    ListNode *node = findNode(header, 1);
    
    Test(__func__, nullptr, node);
}

void test6()
{
    vector<int> arr = {1, 2, 3, 4};
    ListNode *header = VecToList(arr);
    
    ListNode *node = findNode(header, 10);
    
    Test(__func__, &header, node);
}


/*
 题目2: 删除链表中重复的节点。
 在一个排序的链表中，如何删除重复的节点？
 例如：
 input: 1->2->3->3->4->4->5
 output: 1->2->5
 */

/// 删除重复节点
void DeleteDuplicatedNodes(ListNode **pHeader)
{
    if (pHeader==nullptr || *pHeader==nullptr)
        return;
    
    ListNode *pPreNode = nullptr;
    ListNode *pNode= *pHeader;
    
    while (pNode!=nullptr) {
        
        ListNode *pNext = pNode->m_pNext;
        bool needDelete = false;
        
        if (pNext!=nullptr && pNext->m_nValue==pNode->m_nValue)
            needDelete = true;
        
        if (!needDelete)
        {
            pPreNode = pNode;
            pNode = pNode->m_pNext;
        }
        else
        {
            int duplicateValue = pNode->m_nValue;
            ListNode *pToBeDel = pNode;
            while (pToBeDel!=nullptr && pToBeDel->m_nValue == duplicateValue) {
                pNode = pToBeDel->m_pNext;
                delete pToBeDel;
                pToBeDel = nullptr;
                
                pToBeDel = pNode;
            }
            if (pPreNode == nullptr)
                *pHeader = pNode;
            else
                pPreNode->m_pNext = pNode;
        }
    }
}

void TestDuplicate(string testName, ListNode **pListHeader)
{
    printf("--------------\n%s:\n", testName.c_str());
    printf("Before:\t");
    printList(*pListHeader);
    DeleteDuplicatedNodes(pListHeader);
    printf("After:\t");
    printList(*pListHeader);
}

void testDuplicate1()
{
    vector<int> arr = {1, 2, 3, 4};
    ListNode *header = VecToList(arr);
    
    TestDuplicate(__func__, &header);
}

void testDuplicate2()
{
    vector<int> arr = {1, 2, 3, 3, 4, 4, 4, 5};
    ListNode *header = VecToList(arr);
    
    TestDuplicate(__func__, &header);
}

void testDuplicate3()
{
    vector<int> arr = {3, 3, 4, 4, 4, 5, 1, 2};
    ListNode *header = VecToList(arr);
    TestDuplicate(__func__, &header);
}

void testDuplicate4()
{
    vector<int> arr = {1, 2, 3, 3, 4, 4, 4};
    ListNode *header = VecToList(arr);
    TestDuplicate(__func__, &header);
}

int main(int argc, const char * argv[]) {
    
//    test1();
//    test2();
//    test3();
//    test4();
////    test5();
//    test6();
    
    testDuplicate1();
    testDuplicate2();
    testDuplicate3();
    testDuplicate4();
    
    return 0;
}
