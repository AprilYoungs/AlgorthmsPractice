//
//  main.cpp
//  7RebuildBinaryTree
//
//  Created by April Yang on 2020/2/1.
//  Copyright © 2020 April Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <queue>
#include "BinaryTree.hpp"

using namespace std;

/*
 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。
 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如，
 输入前序遍历序列{1, 2, 4, 7, 3, 5, 6, 8},
 中序遍历{4, 7, 2, 1, 5, 3, 8, 6},重建二叉树并输出它的头节点。
 */

/*
 三种遍历方式：前序遍历，中序遍历，后序遍历
 前序遍历：先访问根节点->左节点->右节点
 中序遍历：先访问左节点->根节点->右节点
 后序遍历：先访问左节点->右节点->根节点
 */


//void Test1(string testName, BinaryTreeNode *pHead)
//{
//    printf("----------------------\n%s: \n", testName.c_str());
//
//    cout<< "PreOrder: ";
//    preOrderReadBinaryTree1(pHead);
//    cout<< endl;
//    cout<< "inOrder: ";
//    inOrderReadBinaryTree1(pHead);
//    cout<< endl;
//
//    cout<< "BackOrder: ";
//    backOrderReadBinaryTree1(pHead);
//    cout<< endl;
//}

void Test(string testName, BinaryTreeNode *pHead)
{
    printf("----------------------\n%s: \n", testName.c_str());
    
    cout<< "PreOrder: ";
    preOrderReadBinaryTree2(pHead);
    cout<< endl;
    
    cout<< "inOrder: ";
    inOrderReadBinaryTree2(pHead);
    cout<< endl;
    
    cout<< "BackOrder: ";
    backOrderReadBinaryTree2(pHead);
    cout<< endl;
}


void test2()
{
    vector<NodeData> array = {
        NodeData(10, true),
        NodeData(6, true),
        NodeData(14, true),
        NodeData(4, true),
        NodeData(8, true),
        NodeData(12, true),
        NodeData(16, true)};
    
    BinaryTreeNode *pHead = widthlyBinaryTree(&array);
   
    Test(__func__, pHead);
}

void test3()
{
    vector<NodeData> array = {
    NodeData(1, true),
    NodeData(2, true),
    NodeData(3, true),
    NodeData(4, true),
    NodeData(0, false),
    NodeData(5, true),
    NodeData(6, true),
    NodeData(0, false),
    NodeData(7, true),
    NodeData(0, false),
    NodeData(0, false),
    NodeData(0, false),
    NodeData(0, false),
    NodeData(8, true),
    NodeData(0, false)};
    
    BinaryTreeNode *pHead = widthlyBinaryTree(&array);
   
    Test(__func__, pHead);
}


/// 截取数组元素
/// @param original 原始vector
/// @param loc 开始节点
/// @param len 长度
vector<int> subVector(vector<int> &original, int loc, int len)
{
    vector<int> arr;
    if (loc >= original.size() || (loc+len) > original.size())
        return arr;
    
    for (int i=loc; i<loc+len; i++)
    {
        arr.push_back(original[i]);
    }
    return arr;
}


/// 递归实现重构二叉树
/// @param preOrder 前序遍历数组
/// @param inOrder 后序遍历数组
BinaryTreeNode *rebuildTree(vector<int> &preOrder, vector<int> &inOrder)
{
    if (preOrder.size() != inOrder.size() || preOrder.size()==0)
        return nullptr;
    
    BinaryTreeNode *root = new BinaryTreeNode(preOrder[0]);
    
    int splitPoint = -1;
    for (int i=0; i<inOrder.size(); i++)
    {
        if (inOrder[i] == preOrder[0])
        {
            splitPoint = i;
            break;
        }
    }
    
    // 有问题的输入，找不到分界点
    if (splitPoint == -1)
        throw exception();
    
    // 获取分割后的数组
    vector<int> leftPreOrder = subVector(preOrder, 1, splitPoint);
    vector<int> rightPreOrder = subVector(preOrder, splitPoint+1, (int)inOrder.size()-splitPoint-1);
    
    
    vector<int> leftInOrder = subVector(inOrder, 0, splitPoint);
    vector<int> rightInOrder = subVector(inOrder, splitPoint+1, (int)inOrder.size()-splitPoint-1);
    
    if (leftPreOrder.size() > 0)
    {
        root->m_pLeft = rebuildTree(leftPreOrder, leftInOrder);
    }
    
    if (rightPreOrder.size() > 0)
    {
        root->m_pRight = rebuildTree(rightPreOrder, rightInOrder);
    }
    
    return root;
}


/// 测试重构二叉树
/// @param testName testName
/// @param preOrder preOrder vector
/// @param inOrder inOrder vector
/// @param expected expected vector
void TestRebuild(string testName,
                 vector<int> &preOrder,
                 vector<int> &inOrder,
                 vector<int> &expected)
{
    printf("----------------\n%s:\n", testName.c_str());
    
    BinaryTreeNode *rebuild = rebuildTree(preOrder, inOrder);
    vector<int> backOrder = backOrderReadBinaryTree2(rebuild);
    
    if (isVectorIsEqual(backOrder, expected))
    {
        printf("\nPassed.\n");
    }
    else
    {
        printf("\nFailed.\n");
    }
}

void testRebuild1()
{
    vector<int> preOrder = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> inOrder = {4, 7, 2, 1, 5, 3, 8, 6};
    vector<int> backOrder = {7, 4, 2, 5, 8, 6, 3, 1};
    
    TestRebuild(__func__, preOrder, inOrder, backOrder);
}

void testRebuild2()
{
    vector<int> preOrder = {10, 6, 4, 8, 14, 12, 16};
    vector<int> inOrder = {4, 6, 8, 10, 12, 14, 16};
    vector<int> backOrder = {4, 8, 6, 12, 16, 14, 10};
    
    TestRebuild(__func__, preOrder, inOrder, backOrder);
}

void testRebuild3()
{
    vector<int> preOrder = {10};
    vector<int> inOrder = {10};
    vector<int> backOrder = {10};
    
    TestRebuild(__func__, preOrder, inOrder, backOrder);
}

void testRebuild4()
{
    vector<int> preOrder = {1, 2, 3};
    vector<int> inOrder = {3, 2, 1};
    vector<int> backOrder = {3, 2, 1};
    
    TestRebuild(__func__, preOrder, inOrder, backOrder);
}

void testRebuild5()
{
    vector<int> preOrder = {1, 2, 3};
    vector<int> inOrder = {1, 2, 3};
    vector<int> backOrder = {3, 2, 1};
    
    TestRebuild(__func__, preOrder, inOrder, backOrder);
}

void testRebuild6()
{
    vector<int> preOrder = {1, 2, 3};
    vector<int> inOrder = {1, 2, 3, 4};
    vector<int> backOrder = {2, 3, 1};
    
    TestRebuild(__func__, preOrder, inOrder, backOrder);
}

void testRebuild7()
{
    vector<int> preOrder = {1, 2, 3};
    vector<int> inOrder = {1, 2, 4};
    vector<int> backOrder = {2, 3, 1};
    
    TestRebuild(__func__, preOrder, inOrder, backOrder);
}


int main(int argc, const char * argv[]) {
    
    test2();
    test3();
    
    testRebuild1();
    testRebuild2();
    testRebuild3();
    testRebuild4();
    testRebuild5();
    testRebuild6();
//    testRebuild7();
    
    cout << endl;
    return 0;
}
