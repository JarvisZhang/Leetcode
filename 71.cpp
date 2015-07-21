//
//  71.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/30.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Simplify Path
//

#include <iostream>
#include <deque>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        deque<string> pathUnit;
        int start = 0, end = 0;
        while (start < path.length()) {
            while (++start < path.length() && path[start] == '/') ;
            end = start;
            while (++end < path.length() && path[end] != '/') ;
            if (start != path.length()) {
                string unit = path.substr(start, end - start);
                if (unit.compare("..") == 0) {
                    if (!pathUnit.empty()) {
                        pathUnit.pop_back();
                    }
                }
                else if (unit.compare(".") != 0) {
                    pathUnit.push_back("/" + unit);
                }
            }
            start = end;
        }
        if (pathUnit.empty()) {
            return "/";
        }
        else {
            string result;
            for (string s : pathUnit) {
                result.append(s);
            }
            return result;
        }
    }
};

class Test {
private:
    static void runTest(string path) {
        Solution solution;
        string result = solution.simplifyPath(path);
        cout << result << endl;
    }
    
public:
    void sample() {
        string p1("/.");
        string p2("/..");
        runTest(p1);
        runTest(p2);
    }
};