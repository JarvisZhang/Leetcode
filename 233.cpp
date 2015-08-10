//
//  233.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/28.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Number of Digit One
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int result = 0;
        for (long scale = 1; scale <= n; scale *= 10) {
            int prefix = n / scale, postfix = n % scale;
            result += (prefix + 8) / 10 * scale + (prefix % 10 == 1) * (postfix + 1);
        }
        return result;
    }
};