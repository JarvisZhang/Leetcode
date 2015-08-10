//
//  190.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/2.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Reverse Bits
//

#include <iostream>

using namespace std;

class Solution {
public:
    int referance[16] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0, last4 = 0;
        for (int i = 0; i < 8; i++) {
            last4 = 0xF & n;
            n >>= 4;
            result <<= 4;
            result |= referance[last4];
        }
        return result;
    }
};

class Test {
public:
    void sample() {
        uint32_t n = 1;
        Solution solution;
        cout << solution.reverseBits(n) << endl;
    }
};