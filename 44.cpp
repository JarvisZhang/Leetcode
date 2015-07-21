//
//  44.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/29.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Wildcard Matching
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        long lens = s.size(), lenp = p.size();
        vector<vector<bool>> matched(lens+1, vector<bool>(lenp+1, false));
        matched[0][0] = true;
        for (int i = 0; i <= lens; i++) {
            for (int j = 1; j <= lenp; j++) {
                if (p[j-1] != '*') {
                    matched[i][j] = i > 0 && matched[i-1][j-1] && (p[j-1] == '?' || p[j-1] == s[i-1]);
                }
                else {
                    matched[i][j] = matched[i][j-1] || (i > 0 && matched[i-1][j]);
                }
            }
        }
        return matched[lens][lenp];
    }
    
    bool isMatchBacktrack(string s, string p) {
        int i = 0, j = 0, star = -1, preLoc = -1;
        while (i < s.length()) {
            if (j < p.length() && (s[i] == p[j] || p[j] == '?')) {
                i++; j++;
            }
            else if (j < p.length() && p[j] == '*') {
                while (++j < p.length() && p[j] == '*') ;
                star = j - 1;
                preLoc = i;
            }
            else if (star != -1) {
                i = ++preLoc;
                j = star + 1;
            }
            else {
                return false;
            }
        }
        while (j < p.length() && p[j] == '*') j++;
        return j == p.length();
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
        string s1("ab"), p1("?*c");
        string s2("aab"), p2("c*a*b");
        string s3("aaa"), p3("ab*a");
        string s4("abcd"), p4("d*");
        string s5("aa"), p5("*");
        runTest(s1, p1);
        runTest(s2, p2);
        runTest(s3, p3);
        runTest(s4, p4);
        runTest(s5, p5);
    }
};