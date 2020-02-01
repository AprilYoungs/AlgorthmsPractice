//
//  BinaryTree.cpp
//  7RebuildBinaryTree
//
//  Created by April Yang on 2020/2/1.
//  Copyright © 2020 April Yang. All rights reserved.
//

#include "BinaryTree.hpp"

using namespace std;


/// 广度优先的顺序读去并创建一颗树
/// @param array 数据源
BinaryTreeNode *widthlyBinaryTree(vector<NodeData> *array)
{
    if (array == nullptr)
        return nullptr;
    
    // 数据数量是否合理
    float layer = log2(array->size()+1);
    if (layer != round(layer))
        return nullptr;
    
    queue<BinaryTreeNode*> nodes;
    BinaryTreeNode *pHead = nullptr;
    for (int i=0; i<layer; i++)
    {
        for (int j=0; j<pow(2, i); j++)
        {
            NodeData data = (*array)[pow(2, i)-1+j];
            if (data.isShow == false)
            {
                nodes.push(nullptr);
                if (j%2==1)
                    nodes.pop();
                continue;
            }
            
            BinaryTreeNode *node = new BinaryTreeNode(data.value);
            nodes.push(node);
    
            if(pHead==nullptr)
                pHead = node;
            else
            {
                BinaryTreeNode *root = nodes.front();
                if (j%2==0)
                    root->m_pLeft = node;
                else
                {
                    root->m_pRight = node;
                    nodes.pop();
                }
            }
        }
    }
    
    return pHead;
};


/// 递归前序遍历
/// @param pHead 树的根节点
void preOrderReadBinaryTree1(BinaryTreeNode *pHead)
{
    if (pHead != nullptr)
    {
        printf("%d ", pHead->m_nValue);
        if (pHead->m_pLeft != nullptr)
            preOrderReadBinaryTree1(pHead->m_pLeft);
        if (pHead->m_pRight != nullptr)
            preOrderReadBinaryTree1(pHead->m_pRight);
    }
}

/// 递归中序遍历
/// @param pHead 树的根节点
void inOrderReadBinaryTree1(BinaryTreeNode *pHead)
{
    if (pHead != nullptr)
    {
        if (pHead->m_pLeft != nullptr)
            inOrderReadBinaryTree1(pHead->m_pLeft);
        printf("%d ", pHead->m_nValue);
        if (pHead->m_pRight != nullptr)
            inOrderReadBinaryTree1(pHead->m_pRight);
    }
}



/// 递归后序遍历
/// @param pHead 树的根节点
void backOrderReadBinaryTree1(BinaryTreeNode *pHead)
{
    if (pHead != nullptr )
    {
        if (pHead->m_pLeft != nullptr)
            backOrderReadBinaryTree1(pHead->m_pLeft);
        if (pHead->m_pRight != nullptr)
            backOrderReadBinaryTree1(pHead->m_pRight);
        printf("%d ", pHead->m_nValue);
    }
}

/// 循环前序遍历
/// @param pHead 树的根节点
vector<int> preOrderReadBinaryTree2(BinaryTreeNode *pHead)
{
    stack<BinaryTreeNode *> nodes;
    vector<int> values;
    
    while (pHead != nullptr) {
        values.push_back(pHead->m_nValue);
        nodes.push(pHead);
        if (pHead->m_pLeft != nullptr)
            pHead = pHead->m_pLeft;
        
        else
        {
            while (!nodes.empty() && nodes.top()->m_pRight==nullptr) {
                nodes.pop();
            }
            if (!nodes.empty())
            {
                BinaryTreeNode *top = nodes.top();
                nodes.pop();
                pHead = top->m_pRight;
            }
            else
            {
                pHead = nullptr;
            }
        }
    }
    
    printVector(values);
    return values;
}

/// 循环中序遍历
/// @param pHead 树的根节点
vector<int> inOrderReadBinaryTree2(BinaryTreeNode *pHead)
{
    stack<BinaryTreeNode *> nodes;
    vector<int> values;
    
    while (pHead != nullptr) {
        
        nodes.push(pHead);
        if (pHead->m_pLeft != nullptr)
            pHead = pHead->m_pLeft;
        else
        {
            while (!nodes.empty() && nodes.top()->m_pRight==nullptr) {
                values.push_back(nodes.top()->m_nValue);
                nodes.pop();
            }
            if (!nodes.empty())
            {
                pHead = nodes.top()->m_pRight;
                values.push_back(nodes.top()->m_nValue);
                nodes.pop();
            }
            else
            {
                pHead = nullptr;
            }
        }
    }
    
    printVector(values);
    return values;
}

/// 循环后序遍历
/// @param pHead 树的根节点
vector<int> backOrderReadBinaryTree2(BinaryTreeNode *pHead)
{
    stack<BinaryTreeNode *> nodes;
    vector<int> values;
    
    while (pHead != nullptr) {
        nodes.push(pHead);
        if (pHead->m_pLeft != nullptr)
            pHead = pHead->m_pLeft;
        else
        {
            while (!nodes.empty() && nodes.top()->m_pRight==nullptr) {
                values.push_back(nodes.top()->m_nValue);
                nodes.pop();
            }
            if (!nodes.empty())
            {
                pHead = nodes.top()->m_pRight;
                nodes.top()->m_pRight = nullptr;
            }
            else
            {
                pHead = nullptr;
            }
        }
    }
    
    printVector(values);
    return values;
}

void printVector(vector<int> &arr)
{
    cout<< "{";
    for (int i=0; i<arr.size(); i++)
        printf("%d%s", arr[i], i==arr.size()-1 ? "" :  ", ");
    
    cout << "}";
}

bool isVectorIsEqual(vector<int> &vec1, vector<int> &vec2)
{
    if (vec1.size() != vec2.size())
        return false;
    
    for (int i=0; i<vec1.size(); i++)
        if (vec1[i] != vec2[i])
            return false;
    
    return true;
}
