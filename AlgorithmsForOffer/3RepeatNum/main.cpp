//
//  main.cpp
//  3RepeatNum
//
//  Created by April Yang on 2020/1/31.
//  Copyright © 2020 April Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;
/**
 Find out one repeat number in an array
 range(0~n-1)
 example
 
 input: {2, 3, 1, 0, 2, 5, 3}
 output: 2 or 3
 
 return: -1 means not found
 */


// 1. compare one by one O(n^2)

int repeatNum(vector<int> &array)
{
    if (array.size() < 2)
    {
        return -1;
    }
    
    for (int i = 1; i < array.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[i] == array[j])
            {
                return array[i];
            }
        }
    }
    
    return -1;
}

// 2. sorted array O(nlogn)

// 3. hashmap
int repeatNum3(vector<int> &array)
{
    
    set<int> temp{};
    
    for (int i=0; i<array.size(); i++)
    {
        if (temp.count(array[i])==0)
        {
            temp.insert(array[i]);
        }
        else
        {
            return array[i];
        }
    }
    
    return -1;
}

//4. sorted and swap elements
int repeatNum4(vector<int> &array)
{
    if (array.size() < 2)
    {
        return -1;
    }
    
    for (int i=0; i<array.size(); i++)
    {
        if (array[i] < 0 || array[i] >= array.size())
        {
            return -1;
        }
    }
    
    for (int i=0; i<array.size(); i++)
    {
        while (array[i] != i) {
            if (array[i] == array[array[i]])
            {
                return array[i];
            }
            
            // swap
            int temp = array[i];
            array[i] = array[temp];
            array[temp] = temp;
        }
    }
    
    return -1;
}

/**
 There's at least one repeat element in the array
 element range(1, n)
 
 Find out a duplicate number without edit the array
 
 example:
 input: {2, 3, 5, 4, 3, 2, 6, 7}
 outputL 2 or 3
 */
// 5. divide and conquer
int countRange(vector<int> &array, int start, int end)
{
    if (start > end
        || array.size() == 0)
    {
        return 0;
    }
    
    int count = 0;
    for (int i = 0; i < array.size(); i++)
        if (array[i] >= start && array[i] <= end)
            count++;
    
    return count;
}
int repeatNum5(vector<int> &array)
{
    if (array.size() < 2)
    {
        return -1;
    }
    
    int start = 1;
    int end = (int)array.size()-1;
    int count = 0;
    
    while (end >= start) {
        int middle = (start+end)/2;
        
        count = countRange(array, start, middle);
        
        cout << start << " " << middle << " " << end << " " << count << endl;
        
        if (start == end)
        {
            if (count > 1)
            {
                return start;
            }
            else
                break;
        }
        
        if (count>(middle-start+1))
            end = middle;
        else
            start = middle+1;
    }
    
    return -1;
}



int main(int argc, const char * argv[]) {
    
    vector<int> array1 = {2, 3, 1, 0, 2, 5, 3};
    vector<int> array2 = {2, 3, 1, 0, 2, 5, 3, 10};
    cout << repeatNum(array1) << endl;
    
//    vector<int> array1 = {2, 3, 1, 0, 2, 5, 3};
    cout << repeatNum3(array1) << endl;
    
    
    cout << repeatNum4(array2) << endl;
    
    vector<int> array3 = {2, 3, 5, 4, 3, 2, 6, 7};
    cout << repeatNum5(array3) << endl;
    
    
    return 0;
}
