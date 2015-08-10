//
//  165.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/26.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Compare Version Numbers
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int start1 = 0, start2 = 0, end1 = 0, end2 = 0, subVersion1 = 0, subVersion2 = 0;
        while (end1 < version1.size() && end2 < version2.size()) {
            if (version1[end1] == '.' && version2[end2] == '.') {
                if (subVersion1 == subVersion2) {
                    start1 = ++end1;
                    start2 = ++end2;
                    subVersion1 = 0;
                    subVersion2 = 0;
                }
                else {
                    return (subVersion1 > subVersion2) ? 1 : -1;
                }
            }
            else {
                if (version1[end1] != '.') {
                    subVersion1 *= 10;
                    subVersion1 += version1[end1++] - '0';
                }
                if (version2[end2] != '.') {
                    subVersion2 *= 10;
                    subVersion2 += version2[end2++] - '0';
                }
            }
        }
        while (end1 < version1.size()) {
            if (version1[end1] != '.') {
                subVersion1 *= 10;
                subVersion1 += version1[end1++] - '0';
            }
            else if (subVersion1 == subVersion2){
                end1++;
                subVersion1 = 0;
                subVersion2 = 0;
            }
            else {
                return (subVersion1 > subVersion2) ? 1 : -1;
            }
        }
        while (end2 < version2.size()) {
            if (version2[end2] != '.') {
                subVersion2 *= 10;
                subVersion2 += version2[end2++] - '0';
            }
            else if (subVersion1 == subVersion2) {
                end2++;
                subVersion1 = 0;
                subVersion2 = 0;
            }
            else {
                return (subVersion1 > subVersion2) ? 1 : -1;
            }
        }
        if (subVersion1 > subVersion2) {
            return 1;
        }
        else if (subVersion1 < subVersion2) {
            return -1;
        }
        else {
            return 0;
        }
        
    }
};

class Test {
public:
    void runTest(string version1, string version2) {
        Solution solution;
        cout << solution.compareVersion(version1, version2) << endl;
    }
    void sample() {
        string a1("1.0"), b1("1");
        string a2("1.9.9.9"), b2("1.10.0.0");
        runTest(a1, b1);
        runTest(a2, b2);
    }
};