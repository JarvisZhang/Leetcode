//
//  5.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/15.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Longest Palindromic Substring
//

#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string insertedStr("^");
        for (char ch : s) {
            insertedStr.push_back('#');
            insertedStr.push_back(ch);
        }
        insertedStr.append("#$");
        int mx = 1, id = 1, length = (int) insertedStr.length();
        int palindLength[length];
        palindLength[id] = 1;
        for (int i = 2; i < length - 1; i++) {
            int j = 2 * id - i;
            palindLength[i] = (mx > i) ? min(palindLength[j], mx - i) : 1;
            while (insertedStr[i - palindLength[i]] == insertedStr[i + palindLength[i]]) {
                palindLength[i]++;
            }
            if (i + palindLength[i] > mx) {
                mx = palindLength[i] + i;
                id = i;
            }
        }
        for (int i = 2; i < length - 1; i++) {
            if (palindLength[i] > palindLength[id]) {
                id = i;
            }
        }
        return s.substr((id - palindLength[id]) / 2, palindLength[id] -1);
    }
};

class Test {
private:
    static void runTest(string s) {
        Solution solution;
        string result = solution.longestPalindrome(s);
        cout << s << ": " << result << endl;
    }
    
public:
    void sample() {
        string s1("dabbac");        //abba
        string s2("sabacc");        //aba
        string s3("acdefefedca");   //acdefefedca
        string s4("adbcbddaadd");   //ddaadd
        string s5("aaaa");          //aaaa
        string s6("szzdknk");       //knk
        runTest(s1);
        runTest(s2);
        runTest(s3);
        runTest(s4);
        runTest(s5);
        runTest(s6);
    }
};
