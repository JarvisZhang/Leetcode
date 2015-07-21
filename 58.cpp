//
//  58.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/16.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Length of Last Word
//

#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) {
            return 0;
        }
        int end = (int) s.length() - 1;
        while (end != 0 && s[end] == ' ') {
            end--;
        }
        int start = end;
        while (start >= 0 && s[start] != ' ') {
            start--;
        }
        return end - start;
    }
};

class Test {
private:
    static void runTest(string s) {
        Solution solution;
        int result = solution.lengthOfLastWord(s);
        cout << s << ": " << result << endl;
    }
    
public:
    void sample() {
        string s1 = "Hello World";
        string s2 = " Hello ";
        string s3 = "  ";
        string s4 = "";
        runTest(s1);
        runTest(s2);
        runTest(s3);
        runTest(s4);
    }
};