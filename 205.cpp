//
//  205.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/3.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Isomorphic Strings
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char sToTHash[256] = {0}, tToSHash[256] = {0};
        if (s.size() != t.size()) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            if (sToTHash[s[i]] == 0) {
                sToTHash[s[i]] = t[i];
            }
            else if (sToTHash[s[i]] != t[i]) {
                return false;
            }
            if (tToSHash[t[i]] == 0) {
                tToSHash[t[i]] = s[i];
            }
            else if (tToSHash[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};