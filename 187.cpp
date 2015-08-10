//
//  187.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/9.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Repeated DNA Sequences
//

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> results;
        unsigned int eraser20 = 0xFFFFF;
        unsigned int current = 0;
        if (s.size() < 11) {
            return results;
        }
        unordered_set<int> unique, dnaResult;
        unordered_map<char, int> dna{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        for (int i = 0; i < 10; i++) {
            current = (current << 2) + dna[s[i]];
        }
        unique.insert(current);
        for (int i = 10; i < s.size(); i++) {
            current = ((current << 2) + dna[s[i]]) & eraser20;
            if (!unique.insert(current).second && dnaResult.insert(current).second) {
                results.push_back(s.substr(i - 9, 10));
            }
        }
        return results;
    }
};

class Test {
public:
    void sample() {
        string s("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
        Solution solution;
        vector<string> result = solution.findRepeatedDnaSequences(s);
        for (auto &str: result) {
            cout << str << endl;
        }
    }
};