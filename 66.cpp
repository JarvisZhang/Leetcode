//
//  66.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/27.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Plus One
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = (int) digits.size() - 1; i >= 0 && carry; i--) {
            int current = digits[i] + carry;
            carry = current / 10;
            digits[i] = current % 10;
        }
        if (carry) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};