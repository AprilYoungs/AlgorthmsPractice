//
//  main.cpp
//  5ReplaceBlank
//
//  Created by April Yang on 2020/1/31.
//  Copyright © 2020 April Yang. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 Replace the blank in the string with %20
 
 example:
 input: "We are happy"
 output: "We%20are%20happy"
 
 */
void ReplaceBlank(char string[], int length)
{
    if (string == nullptr || length <= 0)
        return;
    
    int contentLen = 0;
    int blankCount = 0;
    while (string[contentLen] != '\0') {
        if (string[contentLen] == ' ')
            blankCount++;
        contentLen++;
    }
   
    
    int indexOfOriginal = contentLen;
    
    // length when replace the blank with %20
    int indexOfNew = contentLen+blankCount*2;
    
    if (indexOfNew > length)
        return;
    
    while (indexOfOriginal >=0 && indexOfNew > indexOfOriginal) {
        
        if (string[indexOfOriginal] == ' ')
        {
            string[indexOfNew--] = '0';
            string[indexOfNew--] = '2';
            string[indexOfNew--] = '%';
        }
        else
        {
            string[indexOfNew--] = string[indexOfOriginal];
        }
        
        indexOfOriginal--;
        
    }
    
}

void Test(string testName, char string[], int len, char expected[])
{
    cout << testName << ":";
    ReplaceBlank(string, len);
    
    if (string == nullptr && expected == nullptr)
    {
        printf("Passed.\n");
    }
    else if (string != nullptr && expected == nullptr)
    {
        printf("Failed.\n");
    }
    else if (string == nullptr && expected != nullptr)
    {
        printf("Failed.\n");
    }
    else if (strcmp(string, expected) == 0)
    {
        printf("Passed.\n");
    }
    else
    {
        printf("Failed.\n");
    }
}

void test1()
{
    char str[50] = "We are happy";
    char expected[] = "We%20are%20happy";
    Test(__func__, str, 50, expected);
}

void test2()
{
    char str[50] = "Hi Angie How are you";
    char expected[] = "Hi%20Angie%20How%20are%20you";
    Test(__func__, str, 50, expected);
}

void test3()
{
    char str[50] = "Hi ";
    char expected[] = "Hi%20";
    Test(__func__, str, 50, expected);
}

void test4()
{
    char str[50] = "HiAngieHowareyou";
    char expected[] = "HiAngieHowareyou";
    Test(__func__, str, 50, expected);
}

void test5()
{
//    char str[50] = "HiAngieHowareyou";
    char expected[] = "HiAngieHowareyou";
    Test(__func__, nullptr, 50, expected);
}

/*
 Relative questions
 
 Merge two asend array, A and B, A have enough space to merge B.
 after merge A still is asend
 
 example：
 input：
 A = {1, 3, 5}
 B = {2, 4, 6}
 output:
 A = {1, 2, 3, 4, 5, 6}
 
 */
void mergeArr(int a[], int fullLength, int aLen, int b[], int bLen)
{
    int indexOfNew = aLen + bLen - 1;
    int indexOfA = aLen-1;
    int indexOfB = bLen-1;
    
    if (aLen + bLen > fullLength)
        return;
    
    while (indexOfA >= 0
           && indexOfB >= 0)
    {
        if (a[indexOfA] > b[indexOfB])
        {
            a[indexOfNew] = a[indexOfA--];
        }
        else
        {
            a[indexOfNew] = b[indexOfB--];
        }
        indexOfNew--;
    }
}

void printArr(int a[], int len)
{
    for (int i=0; i<len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}


int main(int argc, const char * argv[]) {
        
    test1();
    test2();
    test3();
    test4();
    test5();
    
    int a[10] = {1, 3, 5};
    int b[] = {2, 4, 6};
    
    mergeArr(a, 10, 3, b, 3);
    printArr(a, 10);
    
    return 0;
}
