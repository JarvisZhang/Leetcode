//
//  132.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/17.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Palindrome Partitioning II
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int length = (int) s.size();
//        vector<vector<bool>> isPalindrom(length, vector<bool>(length, false));
        bool isPalindrom[length][length];
        int cut[length];
//        vector<int> cut(length);
        for (int i = 0; i < length; i++) {
            cut[i] = length - i - 1;
        }
        for (int i = length - 1; i >= 0; i--) {
            for (int j = i; j < length; j++) {
                isPalindrom[i][j] = (i == j) || ((i == j - 1 || isPalindrom[i+1][j-1]) && s[i] == s[j]);
                if (isPalindrom[i][j]) {
                    cut[i] = min((j == length - 1 ? 0 : cut[j+1] + 1), cut[i]);
                }
            }
        }
        return cut[0];
    }
};

class Test {
private:
    static void runTest(string s) {
        Solution solution;
        cout << solution.minCut(s) << endl;
    }
    
public:
    void sample() {
        string s1("aaabaa");
        runTest(s1);
    }
};