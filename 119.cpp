//
//  119.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/2.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Pascal's Triangle II
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1);
        result[0] = result[rowIndex] = 1;
        for (int i = 1; i <= rowIndex / 2; i++) {
            result[i] = result[rowIndex-i] = (int) ((long) result[i-1] *  (long) (rowIndex - i + 1) / i);
        }
        return result;
    }
};