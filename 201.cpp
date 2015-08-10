//
//  201.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/10.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Bitwise AND of Numbers Range
//

#include <iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int postfixDiff = 0;
        while (m ^ n) {
            m >>= 1;
            n >>= 1;
            postfixDiff++;
        }
        return m << postfixDiff;
        
    }
};