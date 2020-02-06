//
//  main.cpp
//  31StackPopAndPush
//
//  Created by April Yang on 2020/2/6.
//  Copyright © 2020 April Yang. All rights reserved.
//  栈的压入、弹出序列

#include <iostream>
#include <stack>
using namespace std;

/*
 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
 假设压入栈的所有数字均不相等。例如，序列{ 1, 2, 3, 4, 5} 是某栈的压栈序列，
 序列{4, 5, 3, 2, 1}是该压栈序列对应的一个弹出序列，
 但{4, 3, 5, 1, 2}就不可能是该压栈序列的弹出序列。
 */

bool isPopOrder(const int* pPush, const int* pPop, int nLength)
{
    if (pPush == nullptr || pPop == nullptr || nLength <= 0)
        return false;
    
    stack<int> m_data{};
    int indexPush = 0;
    int indexPop = 0;
    
    while (indexPush < nLength && indexPop < nLength) {
        
        // 入栈
        while (indexPush < nLength
               && indexPop < nLength
               && pPush[indexPush] != pPop[indexPop]) {
            
            m_data.push(pPush[indexPush]);
            indexPush++;
        }
        if (pPush[indexPush] == pPop[indexPop])
        {
            m_data.push(pPush[indexPush]);
            indexPush++;
        }else
            break;
        
        // 出栈
        while (!m_data.empty()
               && indexPop < nLength
               && m_data.top() == pPop[indexPop]) {
            m_data.pop();
            indexPop++;
        }
    }
    
    return (indexPop == nLength) && m_data.empty();
}


// ====================���Դ���====================
void Test(const char* testName, const int* pPush, const int* pPop, int nLength, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(isPopOrder(pPush, pPop, nLength) == expected)
        printf("Passed.\n");
    else
        printf("failed.\n");
}

void Test1()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 5, 3, 2, 1};
    
    Test("Test1", push, pop, nLength, true);
}

void Test2()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 2, 1};
    
    Test("Test2", push, pop, nLength, true);
}

void Test3()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 3, 5, 1, 2};
    
    Test("Test3", push, pop, nLength, false);
}

void Test4()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 1, 2};
    
    Test("Test4", push, pop, nLength, false);
}

// push��pop����ֻ��һ������
void Test5()
{
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {2};

    Test("Test5", push, pop, nLength, false);
}

void Test6()
{
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {1};

    Test("Test6", push, pop, nLength, true);
}

void Test7()
{
    Test("Test7", nullptr, nullptr, 0, false);
}
 
int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}
