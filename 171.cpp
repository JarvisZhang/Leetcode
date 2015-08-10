//
//  171.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/2.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Excel Sheet Column Number
//

#include <iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            result = result * 26 + s[i] - 'A' + 1;
        }
        return result;
    }
};