//
//  264.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/9/8.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Ugly Number II
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> allUglyNumbers(n);
        int it2 = 0, it3 = 0, it5 = 0;
        allUglyNumbers[0] = 1;
        for (int i = 1; i < n; i++) {
            int next2 = allUglyNumbers[it2] * 2;
            int next3 = allUglyNumbers[it3] * 3;
            int next5 = allUglyNumbers[it5] * 5;
            allUglyNumbers[i] = min(next2, min(next3, next5));
            if (allUglyNumbers[i] == next2) {
                it2++;
            }
            if (allUglyNumbers[i] == next3) {
                it3++;
            }
            if (allUglyNumbers[i] == next5) {
                it5++;
            }
        }
        return allUglyNumbers.back();
    }
};