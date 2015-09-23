//
//  275.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/9/9.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: H-Index II
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int paperNum = (int) citations.size(), start = 0, end = paperNum;
        while (start < end) {
            int middle = start + ((end -start) >> 1), goodPaper = paperNum - middle;
            if (goodPaper > citations[middle]) {
                start = middle + 1;
            }
            else if (goodPaper < citations[middle]) {
                end = middle;
            }
            else {
                return goodPaper;
            }
        }
        return paperNum - start;
    }
};