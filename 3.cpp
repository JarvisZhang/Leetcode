//
//  3.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/12.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Longest Substring Without Repeating Characters 
//
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring_hash(string s) {
        if (s.empty()) {
            return 0;
        }
        int front = 0, rear = 0, maxLength = 0, currentLength = 0;
        unordered_set<char> currentStr;
        while (rear < s.length()) {
            char ch = s.at(rear);
            if (currentStr.find(ch) == currentStr.end()) {
                currentStr.insert(ch);
                rear++;
            }
            else {
                currentLength = rear - front;
                maxLength = (currentLength > maxLength) ? currentLength : maxLength;
                char frontCh;
                do {
                    frontCh = s.at(front);
                    currentStr.erase(frontCh);
                    front++;
                } while (frontCh != ch);
            }
        }
        currentLength = rear - front;
        maxLength = (currentLength > maxLength) ? currentLength : maxLength;
        return maxLength;
    }
    
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        int front = 0, rear = 0, maxLength = 0, currentLength = 0;
        int hash_table[256];
        for(int i = 0; i < 256; i++) {
            hash_table[i] = -1;
        }
        while(rear < s.length()) {
            if (hash_table[s[rear]] != -1) {
                currentLength = rear - front;
                maxLength = (currentLength > maxLength) ? currentLength : maxLength;
                while(front <= hash_table[s[rear]]) {
                    hash_table[s[front++]] = -1;
                }
            }
            hash_table[s[rear]] = rear;
            rear++;
        }
        currentLength = rear - front;
        maxLength = (currentLength > maxLength) ? currentLength : maxLength;
        return maxLength;
    }
};

class Test {
private:
    static void runTest(string str) {
        Solution s = Solution();
        int length = s.lengthOfLongestSubstring(str);
        cout << str << ": " << length << endl;
    }
    
public:
    void sample() {
        string s1("abcabcbb");
        string s2("bbbbb");
        string s3("fdabcabdcdbbc");
        string s4("c");
        string s5("au");
        string s6("aab");
        string s7("abb");
        runTest(s1);
        runTest(s2);
        runTest(s3);
        runTest(s4);
        runTest(s5);
        runTest(s6);
        runTest(s7);
    }
};
