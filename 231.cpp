//
//  231.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/25.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Power of Two
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
    
    bool isPowerOfTwoCount(int n) {
        if (n <= 0) {
            return false;
        }
        int count = 0;
        while (n > 0 && count <= 1) {
            if ((n & 1) == 1) {
                count++;
            }
            n >>= 1;
        }
        return count <= 1;
    }
};