//
//  89.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/7.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Gray Code
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        int length = 1 << n;
        vector<int> result(length, 0);
        for (int i = 0; i < n; i++) {
            int highest = 1 << i, currentLen = highest << 1;
            for (int j = currentLen - 1; j >= highest; j--) {
                result[j] += result[currentLen-j-1] + highest;
            }
        }
        return result;
    }
    
    vector<int> grayCodeMath(int n) {
        int length = 1 << n;
        vector<int> result(length);
        for (int i = 0; i < length; i++) {
            result[i] = (i >> 1) ^ i;
        }
        return result;
    }
};

class Test {
public:
    void sample() {
        int n = 3;
        Solution solution;
        vector<int> result = solution.grayCode(n);
        for (int num: result) {
            cout << num << " ";
        }
    }
};