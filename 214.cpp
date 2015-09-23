//
//  214.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/9/2.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Shortest Palindrome
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string insertedStr("^#");
        for (char ch: s) {
            insertedStr.push_back(ch);
            insertedStr.push_back('#');
        }
        insertedStr.push_back('$');
        size_t id = 1, mx = 2, length = insertedStr.size(), loc = 1;
        size_t palindLength[length];
        palindLength[1] = palindLength[0] = 1;
        for (int i = 2; i < length - 1; i++) {
            size_t j = 2 * id - i;
            palindLength[i] = mx > i ? min(palindLength[j], mx - i) : 1;
            while (insertedStr[i-palindLength[i]] == insertedStr[i+palindLength[i]]) {
                palindLength[i]++;
            }
            size_t currentMx = i + palindLength[i];
            if (currentMx > mx) {
                mx = currentMx;
                id = i;
            }
            if (i == palindLength[i]) {
                loc = i;
            }
        }
        size_t remain = s.size() - palindLength[loc] + 1;
        string prefix(s.rbegin(), s.rbegin() + remain);
        return prefix + s;
    }
};

class Test {
public:
    void sample() {
        string s("babcd");
        Solution solution;
        cout << solution.shortestPalindrome(s) << endl;
    }
};