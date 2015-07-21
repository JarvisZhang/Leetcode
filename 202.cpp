//
//  202.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/17.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Happy Number
//

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> pastNum;
        int sum;
        do {
            sum = 0;
            while (n) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            if (pastNum.find(sum) != pastNum.end()) {
                return false;
            }
            n = sum;
            pastNum.insert(n);
        } while (n != 1);
        return true;
    }
};