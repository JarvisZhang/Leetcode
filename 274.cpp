//
//  274.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/9/9.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: H-Index
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int paperNum = (int) citations.size();
        vector<int> papers(paperNum + 1, 0);
        for (int cite: citations) {
            if (cite > paperNum) {
                cite = paperNum;
            }
            papers[cite]++;
        }
        int result = 0;
        for (int i = 1; i <= paperNum; i++) {
            paperNum -= papers[i-1];
            result = max(result, min(i, paperNum));
        }
        return result;
    }
};