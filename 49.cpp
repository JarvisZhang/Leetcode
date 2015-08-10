//
//  49.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/3.
//  Copyright (c) 2015年 ;. All rights reserved.
//
//  Title: Anagrams
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> results;
        unordered_map<string, int> anagramsMap;
        for (int i = 0; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            if (anagramsMap.find(key) == anagramsMap.end()) {
                anagramsMap[key] = i;
            }
            else {
                results.push_back(strs[i]);
                if (anagramsMap[key] != -1) {
                    results.push_back(strs[anagramsMap[key]]);
                    anagramsMap[key] = -1;
                }
            }
        }
        return results;
    }
};

class Test {
public:
    void sample() {
        vector<string> strs({"", "b", ""});
        Solution solution;
        vector<string> results = solution.anagrams(strs);
        for (auto str : results) {
            cout << str << endl;
        }
    }
};