//
//  242.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/3.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Valid Anagram
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            count[s[i]-'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            count[t[i]-'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i]) {
                return false;
            }
        }
        return true;
    }
};