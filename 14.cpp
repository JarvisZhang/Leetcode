//
//  14.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/1.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Longest Common Prefix
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int border = 0;
        bool flag = true;
        string result("");
        if (strs.empty()) {
            return result;
        }
        while (flag && border < strs[0].length()) {
            char ch = strs[0][border];
            for (int i = 1; i < strs.size(); i++) {
                if (border >= strs[i].length() || strs[i][border] != ch) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                result.push_back(ch);
            }
            border++;
        }
        return result;
    }
};