//
//  BinaryTree.hpp
//  7RebuildBinaryTree
//
//  Created by April Yang on 2020/2/1.
//  Copyright © 2020 April Yang. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <queue>

using namespace std;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    
    BinaryTreeNode(int value){m_nValue=value;m_pLeft=nullptr;m_pRight=nullptr;}
};

struct NodeData
{
    int value;
    bool isShow;
    NodeData(int v, bool show){value = v; isShow = show;}
};

/// 广度优先的顺序读去并创建一颗树
/// @param array 数据源
BinaryTreeNode *widthlyBinaryTree(vector<NodeData> *array);

/// 递归前序遍历
/// @param pHead 树的根节点
void preOrderReadBinaryTree1(BinaryTreeNode *pHead);

/// 递归中序遍历
/// @param pHead 树的根节点
void inOrderReadBinaryTree1(BinaryTreeNode *pHead);

/// 递归后序遍历
/// @param pHead 树的根节点
void backOrderReadBinaryTree1(BinaryTreeNode *pHead);

/// 循环前序遍&历
/// @param pHead 树的根节点
vector<int> preOrderReadBinaryTree2(BinaryTreeNode *pHead);

/// 循环中序遍历
/// @param pHead 树的根节点
vector<int> inOrderReadBinaryTree2(BinaryTreeNode *pHead);

/// 循环后序遍历
/// @param pHead 树的根节点
vector<int> backOrderReadBinaryTree2(BinaryTreeNode *pHead);


/// 打印向量 {1,2, 4, ...}
/// @param arr arr
void printVector(vector<int> &arr);

/// 向量是否一致
bool isVectorIsEqual(vector<int> &vec1, vector<int> &vec2);

BinaryTreeNode* CreateBinaryTreeNode(int value);
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);
void PrintTreeNode(const BinaryTreeNode* pNode);
void PrintTree(const BinaryTreeNode* pRoot);
void DestroyTree(BinaryTreeNode* pRoot);

// 从上到下,一层层打印
void treePrintFromTopToBottom(BinaryTreeNode *pRoot);

// 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行
void treePrintByLines(BinaryTreeNode *pRoot);

#endif /* BinaryTree_hpp */
