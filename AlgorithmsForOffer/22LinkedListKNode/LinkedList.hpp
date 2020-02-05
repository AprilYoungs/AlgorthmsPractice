//
//  LinkedList.hpp
//  22LinkedListKNode
//
//  Created by April Yang on 2020/2/5.
//  Copyright © 2020 April Yang. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode
{
public:
    int m_nkey;
    ListNode *m_pNext;
    
    ListNode(int value){m_nkey=value;m_pNext=nullptr;}
    
    ListNode()
    {
        m_pNext=nullptr;
    };
};

/*
 print the value of a linked list reversely
 
 */
ListNode* makeAList(vector<int> &array);
void destroyList(ListNode **pHead);
void printList(ListNode *header);

/// 找节点
/// @param header header
/// @param value value
ListNode* findNode(ListNode *header, int value);

#endif /* LinkedList_hpp */
