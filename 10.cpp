//
//  10.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/16.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Regular Expression Matching
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        const long lens = s.size(), lenp = p.size();
        vector<vector<bool>> matched(lens+1, vector<bool>(lenp+1, false));
        matched[0][0] = true;
        for (int i = 0; i <= lens; i++) {
            for (int j = 1; j <= lenp; j++) {
                if (p[j-1] != '*') {
                    matched[i][j] = i > 0 && matched[i-1][j-1] && (p[j-1] == '.' || s[i-1] == p[j-1]);
                }
                else {
                    matched[i][j] = matched[i][j-2] || (i > 0 && (matched[i-1][j] && (p[j-2] == '.' || s[i-1] == p[j-2])));
                }
            }
        }
        return matched[lens][lenp];
    }
};

class Test {
private:
    static void runTest(string s, string p) {
        Solution solution;
        cout << solution.isMatch(s, p) << endl;
    }
    
public:
    void sample() {
        string s1("ab"), p1(".*c");
        string s2("aab"), p2("c*a*b");
        string s3("aaa"), p3("ab*a");
        string s4("abcd"), p4("d*");
        runTest(s1, p1);
        runTest(s2, p2);
        runTest(s3, p3);
        runTest(s4, p4);
    }
};