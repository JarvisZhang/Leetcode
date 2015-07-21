//
//  135.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/29.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Candy
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:    
    int candy(vector<int>& ratings) {
        if (ratings.empty()) {
            return 0;
        }
        int result = 1, preCandy = 1, extremum = 1, current = 1;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] < ratings[i-1]) {
                if (preCandy == 1) {
                    ++current;
                    if (current < extremum) {
                        result += current;
                    }
                    else {
                        result += ++extremum;
                    }
                }
                else {
                    preCandy = 1;
                    result += 1;
                    current = 1;
                }
            }
            else if (ratings[i] > ratings[i-1]) {
                result += ++preCandy;
                extremum = preCandy;
                current = 1;
            }
            else {
                preCandy = 1;
                extremum = 1;
                result += 1;
                current = 1;
            }
        }
        return result;
    }
};