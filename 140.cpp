//
//  140.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/15.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Word Break II
//

#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<vector<unordered_set<string>::iterator>> matched;
        for (int i = 0; i < s.size(); i++) {
            vector<unordered_set<string>::iterator> temp;
            for (int j = 0; j <= i; j++) {
                auto subStr = wordDict.find(s.substr(j, i-j+1));
                if ((j == 0 || !matched[j-1].empty()) && subStr != wordDict.end()) {
                    temp.push_back(subStr);
                }
            }
            matched.push_back(temp);
        }
        string current = "";
        vector<string> result;
        makeSentence(matched, current, result, matched.size()-1);
        return result;
    }
    
    void makeSentence(vector<vector<unordered_set<string>::iterator>> &matched, string current, vector<string> &result, long loc)
    {
        if (loc < 0) {
            if (!current.empty()) {
                result.push_back(current.erase(current.size()-1));
            }
            return;
        }
        for (auto it : matched[loc]) {
            makeSentence(matched, *it + " " + current, result, loc-(*it).size());
        }
    }
};

class Test {
private:
    static void runTest(string s, string dict[], int length) {
        unordered_set<string> wordDict(dict, dict+length);
        Solution solution;
        vector<string> result = solution.wordBreak(s, wordDict);
        for (auto str : result) {
            cout << str << endl;
        }
    }
    
public:
    void sample() {
        string s1("catsanddog");
        string dict1[] = {"cat","cats","and","sand","dog"};
        int length1 = 5;
        runTest(s1, dict1, length1);
    }
};