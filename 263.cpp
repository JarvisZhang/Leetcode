//
//  263.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/9/8.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        int factors[] = {2, 3, 5};
        if (num < 1) {
            return false;
        }
        for (int &factor: factors) {
            while (num % factor == 0) {
                num /= factor;
            }
        }
        return num == 1;
    }
};