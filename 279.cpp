//
//  279.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/9/10.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Perfect Squares
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int perfect[n+1];
        perfect[0] = 0; perfect[1] = 1;
        for (int i = 2; i <= n; i++) {
            perfect[i] = perfect[i-1] + 1;
            for (int j = 2; j * j <= i; j++) {
                perfect[i] = min(perfect[i], perfect[i-j*j] + 1);
            }
        }
        return perfect[n];
    }
};