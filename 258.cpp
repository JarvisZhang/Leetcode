//
//  258.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/9/8.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Add Digits
//

#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};