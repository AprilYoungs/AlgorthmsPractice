//
//  main.cpp
//  6PrintLinkedList
//
//  Created by April Yang on 2020/1/31.
//  Copyright © 2020 April Yang. All rights reserved.
//

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
        return;
    
    ListNode *node = header;
    while (node != nullptr) {
        cout << node->m_nkey << " ";
        node = node->m_pNext;
    }
    cout << endl;
}

// recursive
void reversePrintList(ListNode *header)
{
    if (header!=nullptr )
    {
        if (header->m_pNext != nullptr)
        {
            reversePrintList(header->m_pNext);
        }
        cout << header->m_nkey << " ";
    }
}

// stack
void reversePrintList2(ListNode *pHead)
{
    if (pHead == nullptr) return;
    
    stack<ListNode *> nodes;
    ListNode *pNode = pHead;
    while (pNode != nullptr) {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }
    
    while (!nodes.empty()) {
        pNode = nodes.top();
        cout << pNode->m_nkey << " ";
        nodes.pop();
    }
    cout << endl;
}

void Test(string testName, ListNode *pHead)
{
    cout << testName << endl;
    printList(pHead);
    cout << "recursive" << endl;
    reversePrintList(pHead);
    cout << endl << "Stack" << endl;
    reversePrintList2(pHead);
    cout << endl;
}

void Test1()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8};
       
    ListNode *pHead = makeAList(arr);
    
    Test(__func__, pHead);
    
    destroyList(&pHead);
}

void Test2()
{
    vector<int> arr{1};
       
    ListNode *pHead = makeAList(arr);
    
    Test(__func__, pHead);
    
    destroyList(&pHead);
}

void Test3()
{
//    vector<int> arr{1};
//
//    ListNode *pHead = makeAList(arr);
    
    Test(__func__, nullptr);
}



int main(int argc, const char * argv[]) {
    
    Test1();
    Test2();
    Test3();
    
    return 0;
}
