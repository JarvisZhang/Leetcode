//
//  131.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/16.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Palindrome Partitioning
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> current;
        vector<vector<string>> result;
        partitionRecursive(current, result, s, 0, s.size()-1);
        return result;
    }
    
    void partitionRecursive (vector<string> &current, vector<vector<string>> &result, string s, long start, long end) {
        if (start > end) {
            result.push_back(current);
        }
        for (long i = start; i <= end; i++) {
            if (isPalidrome(s, start, i)) {
                current.push_back(s.substr(start, i-start+1));
                partitionRecursive(current, result, s, i+1, end);
                current.pop_back();
            }
        }
    }
    
    bool isPalidrome(string &s, long start, long end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};