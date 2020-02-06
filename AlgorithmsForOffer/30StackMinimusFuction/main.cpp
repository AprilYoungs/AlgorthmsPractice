//
//  main.cpp
//  30StackMinimusFuction
//
//  Created by April Yang on 2020/2/6.
//  Copyright © 2020 April Yang. All rights reserved.
//  包含min函数的栈

#include <iostream>
#include <stack>
#include <assert.h>

using namespace std;

/*
 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min函数。
 在该栈中，调用min、push及pop的时间复杂度都是O(1)。
 */

template <typename T> class MinStack {
    
    stack<T> m_data;
    stack<T> m_min;
    
public:
    MinStack(){m_data={}; m_min={};}
    
    void push(const T& value)
    {
        m_data.push(value);
        if(m_min.empty() || value < m_min.top())
            m_min.push(value);
        else
            m_min.push(m_min.top());
    }
    
    T pop()
    {
        assert(!m_data.empty());
    
        
        T value = m_data.top();
        m_data.pop();
        m_min.pop();
        return value;
    }
    
    T min(){
        return  m_min.top();
    }
};


int main(int argc, const char * argv[]) {
    
    MinStack<int> myStack{};
    myStack.push(3);
    myStack.push(4);
    cout << myStack.min() << endl;
    myStack.push(5);
//    cout << myStack.pop() << endl;
    myStack.push(1);
    cout << myStack.min() << endl;
    myStack.push(2);
    cout << myStack.pop() << endl;
    myStack.push(2);
    cout << myStack.pop() << endl;
    cout << myStack.pop() << endl;
    cout << myStack.min() << endl;
    cout << myStack.pop() << endl;
//    cout << myStack.pop() << endl;
//    cout << myStack.pop() << endl;
//    cout << myStack.pop() << endl;
    
    
    return 0;
}
