//
//  main.cpp
//  12FindMatrixPath
//
//  Created by April Yang on 2020/2/2.
//  Copyright © 2020 April Yang. All rights reserved.
//  矩阵中的路径，回溯法

#include <iostream>

/*
 请设计一个函数， 用来判断在一个矩阵中是否存在一条包含某字符串所在字符的路径。
 路径可以从矩阵中的任意一格开始，每步可以在矩阵中向左、右、上、下移动一格。
 如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如下面的3x4的矩阵中
 包含一条字符串“bfce”的路径。 但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b
 占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
 
 a b t g
 c f c s
 j d e h
 */
bool hasPathCore(const char* matrix, int rows, int cols, int row,
                 int col, const char* str, int &pathLength, bool* visited)
{
    if (str[pathLength] == '\0')
        return true;
    
    bool hasPath = false;
    
    // 没有访问过并且相同
    if (row>=0 && row<rows
        && col>=0 && col<cols
        && str[pathLength]==matrix[cols*row+col]
        && !visited[cols*row+col])
    {
        pathLength++;
        visited[cols*row+col] = true;
        
        hasPath = hasPathCore(matrix, rows, cols, row-1, col, str, pathLength, visited)
        || hasPathCore(matrix, rows, cols, row+1, col, str, pathLength, visited)
        || hasPathCore(matrix, rows, cols, row, col-1, str, pathLength, visited)
        || hasPathCore(matrix, rows, cols, row, col+1, str, pathLength, visited);
        
        if(!hasPath)
        {
            pathLength--;
            visited[cols*row+col] = false;
        }
        else
        {
            printf("(%d, %d) ", row, col);
        }
    }
    
    return hasPath;
}

bool hasPath(char *matrix, int rows, int cols, char *str)
{
    if (matrix==nullptr || rows<=0 || cols<=0 || str==nullptr)
        return false;
    
    
    bool *visited = new bool[rows*cols];
    memset(visited, 0, rows*cols);
    
    int pathLength = 0;
    for (int i=0; i<rows; i++)
        for (int j=0; j<cols; j++)
        {
            if (hasPathCore(matrix, rows, cols, i, j, str, pathLength, visited))
                return true;
        }
    
    delete [] visited;
    
    return false;
}

void Test(std::string testName, char *matrix, int rows, int cols, char *str, bool expected)
{
    printf("------------------\n%s: ", testName.c_str());
    
    try {
        bool result = hasPath(matrix, rows, cols, str);
        result == expected ? printf("Passed.\n") : printf("Failed.\n");
    } catch (...) {
        printf("Invalid input!");
    }
}

void test1()
{
    char matrix[12] = {
        'a', 'b', 't', 'g',
        'c', 'f', 'c', 's',
        'j', 'd', 'e', 'h'
    };
    
    char *str = "bfce";
    Test(__func__, matrix, 3, 4, str, true);
}

void test2()
{
    char matrix[12] = {
        'a', 'b', 't', 'g',
        'c', 'f', 'c', 's',
        'j', 'd', 'e', 'h'
    };
    
    char *str = "bfcej";
    Test(__func__, matrix, 3, 4, str, false);
}

void test3()
{
    char matrix[12] = {
        'a', 'b', 't', 'g'
    };
    
    char *str = "bt";
    Test(__func__, matrix, 4, 1, str, true);
}

void test4()
{
    char matrix[12] = {
        'a', 'b', 't', 'g'
    };
    
    char *str = "bt";
    Test(__func__, matrix, 1, 4, str, true);
}

void test5()
{
    char matrix[12] = {
        'a', 'a', 'a', 'a',
        'a', 'a', 'a', 'a',
        'a', 'a', 'a', 'a'
    };
    
    char *str = "aaaaa";
    Test(__func__, matrix, 3, 4, str, true);
}

void test6()
{

    Test(__func__, nullptr, 1, 1, nullptr, false);
}

int main(int argc, const char * argv[]) {
    
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    
    return 0;
}
