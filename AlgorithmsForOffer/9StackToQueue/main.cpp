//
//  main.cpp
//  9StackToQueue
//
//  Created by April Yang on 2020/2/2.
//  Copyright © 2020 April Yang. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

/*
 用两个栈实现一个队列
 */
template<typename T> class CQueue
{
public:
    CQueue(void){stack1={}; stack2={};};
    ~CQueue(void){};
    
    
    T top()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        
        if (stack2.empty())
            throw exception();
        
        T top = stack2.top();
        return top;
    };
    
    void appendTail(const T& node)
    {
        stack1.push(node);
    };
    T deleteHead()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        
        if (stack2.empty())
            throw exception();
        
        T top = stack2.top();
        stack2.pop();
        return top;
    };
    
private:
    stack<T> stack1;
    stack<T> stack2;
};

/*
 用两个队列实现栈
 */
template<typename T> class CStack
{
    public:
        CStack(void){queue1={}; queue2={};};
        ~CStack(void){};
        
        
        void append(const T& node)
        {
            if(queue2.empty())
                queue1.push(node);
            else
                queue2.push(node);
        };
        T deleteTail()
        {
            if (queue2.empty() && queue1.empty())
                throw exception();
            
            T tail;
            if (!queue2.empty() && queue1.empty())
            {
                queue<T> temp = queue1;
                queue1 = queue2;
                queue2 = temp;
            }
            
            while (queue1.size()>1) {
                T top = queue1.front();
                queue1.pop();
                queue2.push(top);
            }
            tail = queue1.front();
            queue1.pop();
            
            return tail;
        };
        
    private:
        queue<T> queue1;
        queue<T> queue2;
};

void testQueue()
{
    cout << __func__ << endl;
    
    CQueue<int> que{};
    
    que.appendTail(1);
    cout << que.deleteHead() << endl;
    que.appendTail(2);
    que.appendTail(3);
    que.appendTail(4);
    cout << que.top() << endl;
    que.appendTail(5);
    cout << que.deleteHead() << endl;
    cout << que.deleteHead() << endl;
    cout << que.deleteHead() << endl;
    cout << que.deleteHead() << endl;
    
}

void testStack()
{
    cout << __func__ << endl;
    
    CStack<int> sta{};
    sta.append(1);
    cout << sta.deleteTail() << endl;
    sta.append(2);
    sta.append(3);
    sta.append(4);
    cout << sta.deleteTail() << endl;
    sta.append(5);
    sta.append(6);
    cout << sta.deleteTail() << endl;
    cout << sta.deleteTail() << endl;
    cout << sta.deleteTail() << endl;
    cout << sta.deleteTail() << endl;
}

int main(int argc, const char * argv[]) {
    
    testQueue();
    cout << endl;
    cout << endl;
    cout << endl;
    testStack();
    
    return 0;
}
