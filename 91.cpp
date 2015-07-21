//
//  91.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/20.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Decode Ways
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        int decode[s.size()];
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                if (i >= 1 && (s[i-1] == '1' || s[i-1] == '2')) {
                    decode[i] = i >= 2 ? decode[i-2] : 1;
                }
                else {
                    return 0;
                }
            }
            else {
                if (i >= 1 && (s[i-1] == '1' || (s[i-1] == '2' && '1' <= s[i] && s[i] <= '6'))) {
                    decode[i] = decode[i-1] + (i >= 2 ? decode[i-2] : 1);
                }
                else {
                    decode[i] = i >= 1 ? decode[i-1] : 1;
                }
            }
        }
        return decode[s.size()-1];
    }
};