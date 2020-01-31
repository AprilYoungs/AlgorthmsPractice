//
//  main.cpp
//  4MatrixArray
//
//  Created by April Yang on 2020/1/31.
//  Copyright © 2020 April Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

/*
 Search for an element in a matrix
 The matrix follow this rule, every row is asend from left to right,
 every column is asend from top to bottom.
 
 example：
 
 input：
 1  2   8   9
 2  4   9   12
 4  7   10  13
 6  8   11  15
  find 7
 
 output： true
 --------------------
 input：
 1  2   8   9
 2  4   9   12
 4  7   10  13
 6  8   11  15
  find 5
 
 output： false
 */

bool isContainNum(vector<vector<int>> &matrix, int num)
{
    if (matrix.size() < 1
        || matrix[0].size() < 1)
    {
        return false;
    }
    
    for (int i = 0; i < matrix[0].size(); i++)
    {
        if (matrix[0][i] == num)
        {
            return true;
        } // go right
        else if (matrix[0][i] < num)
            continue;
        else if (i > 0)
        {
            //go down
            for (int j=0; j<matrix.size(); j++)
            {
                if (matrix[j][i-1] == num)
                    return true;
                else if (matrix[j][i-1] < num)
                    continue;
                else
                    return false;
            }
        }
        else
            break;
    }
    
    return false;
}

void testCase(string testName, vector<vector<int>> &matrix, int num, bool expected)
{
    cout << testName;
    
    if (isContainNum(matrix, num) == expected)
    {
        printf(" Passed.\n");
    }
    else
    {
        printf(" Failed.\n");
    }
}

void test1()
{
    vector<vector<int>> matrix = {
           {1, 2, 8, 9},
           {2, 4, 9, 12},
           {4, 7, 10, 13},
           {6, 8, 11, 15}
       };

    testCase(__func__, matrix, 7, true);
}

void test2()
{
    vector<vector<int>> matrix = {
           {1, 2, 8, 9},
           {2, 4, 9, 12},
           {4, 7, 10, 13},
           {6, 8, 11, 15}
       };

    testCase(__func__, matrix, 5, false);
}

void test3()
{
    vector<vector<int>> matrix = {
           {1, 2, 8, 9},
           {2, 4, 9, 12},
           {4, 7, 10, 13},
           {6, 8, 11, 15}
       };

    testCase(__func__, matrix, -10, false);
}

void test4()
{
    vector<vector<int>> matrix = {
           {1, 2, 8, 9},
           {2, 4, 9, 12},
           {4, 7, 10, 13},
           {6, 8, 11, 15}
       };

    testCase(__func__, matrix, 20, false);
}

int main(int argc, const char * argv[]) {
    
    test1();
    test2();
    test3();
    test4();
    
    return 0;
}
