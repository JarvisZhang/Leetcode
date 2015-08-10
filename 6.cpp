//
//  6.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/26.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: ZigZag Conversion
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        if (numRows <= 1) {
            return s;
        }
        for (int i = 0; i < numRows; i++) {
            int j = i, step = 2 * (numRows - i - 1);
            while (j < s.size()) {
                result += s[j];
                if (0 < i && i < numRows - 1 && j + step < s.size()) {
                    result += s[j+step];
                }
                j += 2 * (numRows - 1);
            }
        }
        return result;
    }
};

class Test {
private:
    void runTest(string s, int numRows) {
        Solution solution;
        cout << solution.convert(s, numRows) << endl;
    }
    
public:
    void sample() {
        string s1("ABCD");
        string s2("PAYPALISHIRING");
        int n1 = 3;
        int n2 = 3;
        runTest(s1, n1);
        runTest(s2, n2);
    }
};