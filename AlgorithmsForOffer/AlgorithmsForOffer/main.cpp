//
//  main.cpp
//  AlgorithmsTest
//
//  Created by April Yang on 2020/1/31.
//  Copyright © 2020 April Yang. All rights reserved.
//

#include <iostream>

class A{
private:
    int value;
    int b;
    
public:
    A(int n){value = n;}
    A(int n, int m){value = n; b = m;}
    
    //Copy constructor must pass its first argument by reference
//    A(A other){value = other.value;}
    A(A const&other){value = other.value;}
    
    void Print(){std::cout << value << " " << b << std::endl;}
};

int GetSize(int data[])
{
    // Sizeof on array function parameter will return size of 'int *' instead of 'int []'
    return sizeof(data);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    A a = 10;
    A b = a;
    a.Print();
    b.Print();
    
    A c = {10, 4};
    
    c.Print();
    
    int data1[] = {1,23,4567};
    int size1 = sizeof(data1);
    
    int *data2 = data1;
    int size2 = GetSize(data2);
    
    int size3 = GetSize(data1);
    
    printf("%d, %d, %d\n", size1, size2, size3);
    // 12, 8, 8
    
    return 0;
}
