//
//  139.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/14.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Word Break
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        string formattedS = "#" + s;
        long length = formattedS.size();
        vector<bool> matched(length, false);
        matched[0] = true;
        for(int i = 1; i < length; i++) {
            for (int j = 0; j < i; j++) {
                if (matched[j] && wordDict.find(formattedS.substr(j+1, i-j)) != wordDict.end()) {
                    matched[i] = true;
                    break;
                }
            }
        }
        return matched.back();
    }
};