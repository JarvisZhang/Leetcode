//
//  278.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/9/9.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: First Bad Version
//

#include <iostream>

using namespace std;

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long start = 0, end = (long) n + 1;
        while (start < end) {
            int middle = (int) (start + ((end - start) >> 1));
            if (isBadVersion(middle)) {
                end = middle;
            }
            else {
                start = middle + 1;
            }
        }
        return (int) end;
    }
};