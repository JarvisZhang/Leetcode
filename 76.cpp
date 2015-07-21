//
//  76.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/13.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Minimum Window Substring
//

#include <iostream>

using namespace std;

class Solution {
public:
    string minWindow_origin(string s, string t) {
        if (s.empty() || t.empty()) {
            return "";
        }
        int tHashtable[256] = {0}, countHashtable[256] = {0};
        int minSize = 0, leftBorder = 0, rightBorder = 0;
        int front = 0, rear = 0;
        long count = t.length();
        for (int i = 0; i < t.length(); i++) {
            tHashtable[t[i]]++;
        }
        int first = 0;
        while (!tHashtable[s[first]] && first < s.length()) {
            first++;
        }
        front = first; rear = first;
        while (rear < s.length()) {
            if (!tHashtable[s[rear]]) {
                rear++;
                continue;
            }
            if (countHashtable[s[rear]] < tHashtable[s[rear]]) {
                count--;
            }
            countHashtable[s[rear]]++;
            
            if (!count) {
                int currentSize = rear - front + 1;
                if (!minSize || currentSize < minSize) {
                    minSize = currentSize;
                    leftBorder = front;
                    rightBorder = rear;
                }
                front = findNextFront(s, front, tHashtable, countHashtable);
                count++;
            }
            else if (front != rear && s[rear] == s[front] && countHashtable[s[rear]] > tHashtable[s[rear]])
            {
                front = findNextFront(s, front, tHashtable, countHashtable);
            }
            rear++;
        }
        if (minSize) {
            return s.substr(leftBorder, minSize);
        }
        else {
            return "";
        }
    }
    
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) {
            return "";
        }
        int tHashtable[256] = {0}, countHashtable[256] = {0};
        int minSize = INT32_MAX, leftBorder = 0, rightBorder = 0;
        int front = 0, rear = 0;
        long count = t.length();
        for (int i = 0; i < t.length(); i++) {
            tHashtable[t[i]]++;
        }
        for (rear = 0; rear < s.length(); rear++) {
            if (!tHashtable[s[rear]]) {
                continue;
            }
            if (countHashtable[s[rear]] < tHashtable[s[rear]]) {
                count--;
            }
            countHashtable[s[rear]]++;
            if (count <= 0) {
                while (tHashtable[s[front]] == 0 || countHashtable[s[front]] > tHashtable[s[front]]) {
                    if (countHashtable[s[front]] > tHashtable[s[front]]) {
                        countHashtable[s[front]]--;
                    }
                    front++;
                }
                int currentSize = rear - front + 1;
                if (currentSize < minSize) {
                    minSize = currentSize;
                    leftBorder = front;
                    rightBorder = rear;
                }
            }
        }
        return (minSize == INT32_MAX) ? "" : s.substr(leftBorder, minSize);
    }
    
private:
    static int findNextFront(string s, int front, int tHashtable[], int countHashtable[]) {
        countHashtable[s[front]]--;
        front++;
        do {
            if (!tHashtable[s[front]]) {
                front++;
                continue;
            }
            if (countHashtable[s[front]] <= tHashtable[s[front]]) {
                break;
            }
            countHashtable[s[front]]--;
            front++;
        } while (front < s.length());
        return front;
    }
};

class Test {
private:
    static void runTest(string s, string t) {
        Solution solution = Solution();
        string result = solution.minWindow(s, t);
        cout << "\"" << result << "\"" << endl;
    }
    
public:
    void sample() {
        string s1("ADOBECODEBANC"), t1("ABC");  //"BANC"
        string s2("ADO"), t2("ABCW");           //""
        string s3("BCDCACB"), t3("ABCD");       //"BCDCA"
        string s4("CBF"), t4("F");              //"F"
        string s5("aa"), t5("aa");              //"aa"
        string s6("bcbb"), t6("bb");            //"bb"
        string s7("bdcbcb"), t7("cbb");         //"bcb"
        string s8("ab"), t8("b");               //"b"
        runTest(s1, t1);
        runTest(s2, t2);
        runTest(s3, t3);
        runTest(s4, t4);
        runTest(s5, t5);
        runTest(s6, t6);
        runTest(s7, t7);
        runTest(s8, t8);
    }
};