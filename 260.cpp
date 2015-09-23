//
//  260.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/9/9.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Single Number III
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int aXORb = 0;
        for (int &num: nums) {
            aXORb ^= num;
        }
        int last1Bit = (~(aXORb - 1)) & aXORb;
        int numA = 0;
        for (int &num: nums) {
            if (num & last1Bit) {
                numA ^= num;
            }
        }
        int numB = aXORb ^ numA;
        return vector<int>({numA, numB});
    }
};