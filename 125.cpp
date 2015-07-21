//
//  125.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/16.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Valid Palindrome
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int front = 0, rear = (int) s.length() - 1;
        while (front < rear) {
            if (!isLegal(s[front])) {
                front++;
            }
            else if (!isLegal(s[rear])) {
                rear--;
            }
            else if (tolower(s[front]) == tolower(s[rear])) {
                front++; rear--;
            }
            else {
                return false;
            }
        }
        return true;
    }
    
private:
    static inline bool isLegal(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
    }
};

class Test {
private:
    static void runTest(string s) {
        Solution solution;
        bool result = solution.isPalindrome(s);
        cout << s << ": " << result << endl;
    }
public:
    void sample() {
        string s1 = "A man, a plan, a canal: Panama";
        string s2 = "race a car";
        string s3 = "";
        string s4 = "    ";
        string s5 = "1 1";
        runTest(s1);
        runTest(s2);
        runTest(s3);
        runTest(s4);
        runTest(s5);
    }
};
