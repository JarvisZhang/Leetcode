//
//  17.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/30.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Letter Combinations of a Phone Number
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letters = vector<string>({
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    });
    vector<int> total = vector<int>({0,0,3,3,3,3,3,4,3,4});
    
    vector<string> letterCombinations(string digits) {
        vector<string> results;
        int length = (int) digits.size(), index = length - 1;
        vector<int> selected(length, 0);
        while (index >= 0) {
            string current;
            for (int i = 0; i < length; i++) {
                if (selected[i] < total[digits[i]-'0']) {
                    current.push_back(letters[digits[i]-'0'][selected[i]]);
                }
            }
            if (!current.empty()) {
                results.push_back(current);
            }
            index = length - 1;
            while (index >= 0) {
                if (selected[index] >= total[digits[index]-'0'] - 1) {
                    selected[index--] = 0;
                }
                else {
                    selected[index]++;
                    break;
                }
            }
        }
        return results;
    }
};

class Test {
public:
    void sample() {
        string s("6");
        Solution solution;
        vector<string> results = solution.letterCombinations(s);
        for (auto result : results) {
            cout << result << endl;
        }
    }
};