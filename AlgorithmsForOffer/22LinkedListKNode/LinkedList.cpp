//
//  LinkedList.cpp
//  22LinkedListKNode
//
//  Created by April Yang on 2020/2/5.
//  Copyright © 2020 April Yang. All rights reserved.
//

#include "LinkedList.hpp"


/*
 print the value of a linked list reversely
 
 */
ListNode* makeAList(vector<int> &array)
{
    ListNode *header = nullptr;
    ListNode *lastNode = nullptr;
    
    for (int i=0; i<array.size(); i++)
    {
        ListNode *newNode = new ListNode(array[i]);
        
        if (lastNode == nullptr)
        {
            header = newNode;
        }
        else
        {
            lastNode->m_pNext = newNode;
        }
       
        lastNode = newNode;
    }
    
    return header;
}

// 不能摧毁环形结构
void destroyList(ListNode **pHead)
{
    ListNode *pNode = *pHead;
    while (pNode!=nullptr) {
        *pHead = (*pHead)->m_pNext;
        delete pNode;
        pNode = (*pHead);
    }
    *pHead = nullptr;
}

void printList(ListNode *header)
{
    if (header==nullptr)
    {
        printf("\n");
        return;
    }
    
    ListNode *node = header;
    while (node != nullptr) {
        cout << node->m_nkey << " ";
        node = node->m_pNext;
    }
    cout << endl;
}

/// 找节点
/// @param header header
/// @param value value
ListNode* findNode(ListNode *header, int value)
{
    if (header == nullptr)
        return nullptr;
    
    ListNode *node = header;
    while (node!=nullptr && node->m_nkey != value) {
        node = node->m_pNext;
    }
    
    return node;
}
