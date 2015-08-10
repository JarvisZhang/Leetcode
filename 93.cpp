//
//  93.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/3.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Restore IP Addresses
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> results;
        string current;
        restoreIpAddressesRecur(results, current, s, 0, 4);
        return results;
    }
    
    void restoreIpAddressesRecur(vector<string> &results, string &current, string s, int loc, int depth) {
        if (depth > s.size() - loc || 3 * depth < (s.size() - loc)) {
            return;
        }
        if (depth == 1) {
            int lastLength = (int) s.size() - loc;
            string last = s.substr(loc, lastLength);
            if (lastLength <= 3 && stoi(last) <= 255 && !(lastLength > 1 && s[loc] == '0')) {
                results.push_back(current.append(last));
                current.erase(current.end() - last.size(), current.end());
            }
            return;
        }
        for (int length = 1; length <= min(3, (int) s.size() - loc); length++) {
            if (length > 1 && s[loc] == '0') {
                break;
            }
            string segment = s.substr(loc, length);
            if (length < 3 || stoi(segment) <= 255) {
                current += segment + ".";
                restoreIpAddressesRecur(results, current, s, loc + length, depth - 1);
                current.erase(current.end() - length - 1, current.end());
            }
        }
    }
};

class Test {
public:
    void sample() {
        string s("010010");
        Solution solution;
        vector<string> results = solution.restoreIpAddresses(s);
        for (auto str: results) {
            cout << str << endl;
        }
    }
};