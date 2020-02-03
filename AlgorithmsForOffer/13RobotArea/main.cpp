//
//  main.cpp
//  13RobotArea
//
//  Created by April Yang on 2020/2/3.
//  Copyright © 2020 April Yang. All rights reserved.
//  机器人的运动范围，回溯法

#include <iostream>
#include <vector>
using namespace std;

/*
 地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它每次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。但它不能进入方格(35, 38)，因为3+5+3+8=19，请问该机器人能够到达多少格子？
 */


/// 求数位和
/// @param num number
int getDigitSum(int num)
{
    int sum = 0;
    while (num%10>0) {
           sum+=num%10;
           num/=10;
    }
    return sum;
}

bool check(int rows, int cols, int k, int row, int col, bool *visited)
{
    if (row>=0 && col>=0 && k>0 && row<rows && col<cols
        && getDigitSum(col)+getDigitSum(row)<=k
        && !visited[row*cols+col])
    {
        return true;
    }
    return false;
}

int possibleGridCountCore(int rows, int cols, int k, int row, int col, bool *visited);

/// 计算机器人可以走的格子数
/// @param rows rows
/// @param cols cols
/// @param k threshold
unsigned possibleGridCount(int rows, int cols, int k)
{
    if (rows <=0 || cols <=0 || k <=0)
        return 0;
    
    bool *visited = new bool[rows*cols];
    memset(visited, false, rows*cols);
    
    int count = possibleGridCountCore(rows, cols, k, 0, 0, visited);
    
    for (int i=0; i<rows; i++)
    {
        printf("\n");
        for (int j=0; j<cols; j++)
            printf("%c\t", visited[cols*i+j] ? 'o' : 'x');
    }
    
    delete [] visited;
    
    return count;
}

int possibleGridCountCore(int rows, int cols, int k, int row, int col, bool *visited)
{
    int count = 0;
    if(check(rows, cols, k, row, col, visited))
    {
        visited[row*cols+col] = true;
        
//        printf("(%d, %d)\t", row, col);
        
        count = 1 + possibleGridCountCore(rows, cols, k, row, col+1, visited)
        + possibleGridCountCore(rows, cols, k, row, col-1, visited)
        + possibleGridCountCore(rows, cols, k, row+1, col, visited)
        + possibleGridCountCore(rows, cols, k, row-1, col, visited);
    }
    return count;
}

void Test(string testName, int rows, int cols, int k, unsigned expected)
{
    printf("------------------\n%s:", testName.c_str());
    if (possibleGridCount(rows, cols, k) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void test1()
{
    Test(__func__, 5, 5, 3, 10);
}

void test2()
{
    Test(__func__, 1, 5, 3, 4);
}

void test3()
{
    Test(__func__, 5, 1, 3, 4);
}

void test4()
{
    Test(__func__, 5, 1, -1, 0);
}


int main(int argc, const char * argv[]) {
    
    test1();
    test2();
    test3();
    test4();
    return 0;
}
