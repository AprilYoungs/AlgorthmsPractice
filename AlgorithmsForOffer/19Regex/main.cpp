//
//  main.cpp
//  19Regex
//
//  Created by April Yang on 2020/2/4.
//  Copyright © 2020 April Yang. All rights reserved.
//  正则表达式匹配

#include <iostream>

/*
 请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
 而'*'表示它前面的字符可以出现任意次(含0次)。
 在本题中，匹配是指字符串的所有字符匹配整个模式。
 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。
 */


/// 自定义正则匹配
/// @param pattern pattern
/// @param str str
bool MyRegex1(char *pattern, char *str)
{
    if (pattern == nullptr || str == nullptr)
        return false;
    
    int stringLen = (int)strlen(str);
    int patternLen = (int)strlen(pattern);
    
    // 空字符串的情况
    if (stringLen == 0)
    {
        if ((patternLen&1)==1)
            return false;
        else
        {
            for (int i=1; i<patternLen; i+=2)
            {
                if (pattern[i] != '*')
                    return false;
            }
            return true;
        }
    }
    
    int patternIndex = 0;
    for (int i=0; i<stringLen; i++)
    {
        if(patternIndex<patternLen &&
           ( pattern[patternIndex] == '.'
            || pattern[patternIndex] == str[i] ))
        {
            patternIndex++;
            continue;
        }
        else if (patternIndex < patternLen
                 && pattern[patternIndex]=='*'
                 && patternIndex-1 >= 0
                 && pattern[patternIndex-1]==str[i])
        {
            // 遇到重复字符的时候
            continue;
        }
        else if (patternIndex < patternLen
                 && pattern[patternIndex]=='*')
        {
            // 不同，后面是*，比如"a*",跳过这个模式
            patternIndex ++;
            i--;
            continue;
        }
        else if (patternIndex+1 < patternLen
                 && pattern[patternIndex+1]=='*')
        {
            // 不同，后面是*，比如"a*",跳过这个模式
            patternIndex += 2;
            i--;
            continue;
        }
        else
        {
            return false;
        }
    }
    
    if (patternIndex != patternLen)
        return false;
    
    return true;
}

/// final solution
bool matchCore(char *pattern, char *str)
{
    if (*pattern=='\0' && *str=='\0')
        return true;
    
    if (*pattern=='\0' && *str!='\0')
        return false;
    
    if(*(pattern+1)=='*')
    {
        if (*pattern==*str || (*pattern=='.' && *str!='\0'))
            // current state
            return matchCore(pattern, str+1)
            // moving state
            || matchCore(pattern+2, str+1)
            // ignore a*
            || matchCore(pattern+2, str);
        else
            // ignore a*
            return matchCore(pattern+2, str);
    }
    if (*pattern==*str || (*pattern=='.' && *str!='\0'))
        return matchCore(pattern+1, str+1);
    
    return false;
}

bool MyRegex(char *pattern, char *str)
{
    if (pattern==nullptr || str==nullptr)
        return false;
    return matchCore(pattern, str);
}


void Test(std::string testName, char *str, char *pattern, bool expected)
{
    printf("-----------------\n%s: ", testName.c_str());
    
    if (MyRegex(pattern, str) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

int main(int argc, const char * argv[]) {
    
    Test("Test01", "", "", true);
    Test("Test02", "", ".*", true);
    Test("Test03", "", ".", false);
    Test("Test04", "", "c*", true);
    Test("Test05", "a", ".*", true);
    Test("Test06", "a", "a.", false);
    Test("Test07", "a", "", false);
    Test("Test08", "a", ".", true);
    Test("Test09", "a", "ab*", true);
    Test("Test10", "a", "ab*a", false);
    Test("Test11", "aa", "aa", true);
    Test("Test12", "aa", "a*", true);
    Test("Test13", "aa", ".*", true);
    Test("Test14", "aa", ".", false);
    Test("Test15", "ab", ".*", true);
    Test("Test16", "ab", ".*", true);
    Test("Test17", "aaa", "aa*", true);
    Test("Test18", "aaa", "aa.a", false);
    Test("Test19", "aaa", "a.a", true);
    Test("Test20", "aaa", ".a", false);
    Test("Test21", "aaa", "a*a", true);
    Test("Test22", "aaa", "ab*a", false);
    Test("Test23", "aaa", "ab*ac*a", true);
    Test("Test24", "aaa", "ab*a*c*a", true);
    Test("Test25", "aaa", ".*", true);
    Test("Test26", "aab", "c*a*b", true);
    Test("Test27", "aaca", "ab*a*c*a", true);
    Test("Test28", "aaba", "ab*a*c*a", false);
    Test("Test29", "bbbba", ".*a*a", true);
    Test("Test30", "bcbbabab", ".*a*a", false);
    
    return 0;
}
