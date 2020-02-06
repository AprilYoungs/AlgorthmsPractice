//
//  main.cpp
//  29ClockwisePrintMatrix
//
//  Created by April Yang on 2020/2/6.
//  Copyright © 2020 April Yang. All rights reserved.
//  顺时针打印矩阵

#include <iostream>

/*
 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。例如，如果输入如下矩阵：
 
 input:
 1  2   3   4
 5  6   7   8
 9  10  11  12
 13 14  15  16
 
 output:
 1 2 3 4 8 12 16 15 14  13  9   5   6   7   11  10
 */

// 把矩阵当成一个个嵌套的圈
void printMatrixClockwisely(int **numbers, int columns, int rows);
// 打印一个圈
void printCircleClockwisely(int **numbers, int columns, int rows, int start);

void printMatrixClockwisely(int **numbers, int columns, int rows)
{
    if (numbers == nullptr || columns <= 0 || rows <= 0)
        return;
    int start = 0;
    while (start*2 < columns && start*2 < rows) {
        printCircleClockwisely(numbers, columns, rows, start++);
    }
}

void printCircleClockwisely(int **numbers, int columns, int rows, int start)
{
    int endX = columns - start - 1;
    int endY = rows - start - 1;
    
    // 往右
    for (int i=start; i<=endX; i++)
    {
        printf("%d\t", numbers[start][i]);
    }
    
    // 往下 1*2
    if (endY > start)
    {
        for (int i=start+1; i<=endY; i++)
        {
            printf("%d\t", numbers[i][endX]);
        }
    }
    
    // 往左 2*2
    if (endX > start && endY > start)
    {
        for (int i=endX-1; i>=start; i--)
        {
            printf("%d\t", numbers[endY][i]);
        }
    }
    
    // 往上 3*2
    if (endX > start && endY-start > 1)
    {
        for (int i=endY-1; i>start; i--)
        {
            printf("%d\t", numbers[i][start]);
        }
    }
}

// ====================���Դ���====================
void Test(int columns, int rows)
{
    printf("Test Begin: %d columns, %d rows.\n", columns, rows);

    if(columns < 1 || rows < 1)
        return;

    int** numbers = new int*[rows];
    for(int i = 0; i < rows; ++i)
    {
        numbers[i] = new int[columns];
        for(int j = 0; j < columns; ++j)
        {
            numbers[i][j] = i * columns + j + 1;
        }
    }

    printMatrixClockwisely(numbers, columns, rows);
    printf("\n");

    for(int i = 0; i < rows; ++i)
        delete[] (int*)numbers[i];

    delete[] numbers;
}

int main(int argc, char* argv[])
{
    /*
    1
    */
    Test(1, 1);

    /*
    1    2
    3    4
    */
    Test(2, 2);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    */
    Test(4, 4);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    21   22   23   24   25
    */
    Test(5, 5);

    /*
    1
    2
    3
    4
    5
    */
    Test(1, 5);

    /*
    1    2
    3    4
    5    6
    7    8
    9    10
    */
    Test(2, 5);

    /*
    1    2    3
    4    5    6
    7    8    9
    10   11   12
    13   14   15
    */
    Test(3, 5);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    17   18   19   20
    */
    Test(4, 5);

    /*
    1    2    3    4    5
    */
    Test(5, 1);

    /*
    1    2    3    4    5
    6    7    8    9    10
    */
    Test(5, 2);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14    15
    */
    Test(5, 3);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    */
    Test(5, 4);

    return 0;
}
