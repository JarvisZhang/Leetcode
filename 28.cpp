//
//  28.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/28.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.length() < needle.length()) {
            return -1;
        }
        for (int i = 0; i <= haystack.length() - needle.length(); i++) {
            int j = 0, loc = i;
            while (j < needle.length() && haystack[loc] == needle[j]) {
                loc++;
                j++;
            }
            if (j == needle.length()) {
                return i;
            }
        }
        return -1;
    }
};

class Test {
private:
    static void runTest(string haystack, string needle) {
        Solution solution;
        int result = solution.strStr(haystack, needle);
        cout << haystack << ", " << needle << ": " << result << endl;
    }
    
public:
    void sample() {
        string h1("mississippi"), n1("mississippii");
        string h2(""), n2("");
        runTest(h1, n1);
        runTest(h2, n2);
    }
};