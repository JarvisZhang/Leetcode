//
//  67.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/1.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Add Binary
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int carry = 0, i = (int) a.size() - 1, j = (int) b.size() - 1;
        while (i >= 0 || j >= 0) {
            int current = carry;
            if (i >= 0) {
                current += a[i--] - '0';
            }
            if (j >= 0) {
                current += b[j--] - '0';
            }
            result += '0' + current % 2;
            carry = current / 2;
        }
        if (carry != 0) {
            result += '1';
        }
        reverse(result.begin(), result.end());
        return result;
    }
};