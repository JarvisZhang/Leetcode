//
//  69.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/5.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Sqrt(x)
//

#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0) {
            return 0;
        }
        int left = 1, right = min(x / 2 + 1, (int) sqrt(INT_MAX));
        while (left <= right) {
            int middle = (left + right) / 2;
            int current = middle * middle;
            if (current < x) {
                left = middle + 1;
            }
            else if (current > x) {
                right = middle - 1;
            }
            else {
                return middle;
            }
        }
        return left - 1;
    }
};