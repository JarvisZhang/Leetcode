//
//  30.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/14.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Substring with Concatenation of All Words
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) {
            return result;
        }
        unordered_map<string, int> wordsMap;
        long count = 0, length = words[0].length();
        if (s.length() < words.size() * length) {
            return result;
        }
        for (string &i : words) {
            if (wordsMap.find(i) == wordsMap.end()) {
                wordsMap.insert({i, 1});
            }
            else {
                wordsMap[i]++;
            }
        }
        for (int front = 0; front < length; front++) {
            unordered_map<string, int> stringMap;
            count = 0;
            for (int i = front; i < s.length(); i += length) {
                string current = s.substr(i, length);
                if (wordsMap.find(current) == wordsMap.end()) {
                    stringMap.clear();
                    count = 0;
                    continue;
                }
                count++;
                if (stringMap.find(current) == stringMap.end()) {
                    stringMap.insert({current, 1});
                }
                else {
                    stringMap[current]++;
                }
                while (stringMap[current] > wordsMap[current]) {
                    string frontStr = s.substr(i - length * (count - 1), length);
                    stringMap[frontStr]--;
                    count--;
                }
                if (count == words.size()) {
                    int leftBorder = (int) (i - length * (count - 1));
                    result.push_back(leftBorder);
                    string frontStr = s.substr(leftBorder, length);
                    stringMap[frontStr]--;
                    count--;
                }
            }
        }
        return result;
    }
};

class Test {
private:
    static void runTest(string s, vector<string> words) {
        Solution solution = Solution();
        vector<int> result = solution.findSubstring(s, words);
        cout << "[";
        for (int indice : result) {
            cout << indice << ",";
        }
        cout << "]" << endl;;
    }
    
public:
    void sample() {
        string s1("dbarfoothefoobarman"); vector<string> w1 = {"foo", "bar"};   //[1, 10]
        string s2("dbarfoofoobarman"); vector<string> w2 = {"foo", "bar"};      //[1, 7]
        string s3("cdbobcbob"); vector<string> w3 = {"bob", "obc"};             //[3]
        string s4("aa"); vector<string> w4 = {"a"};                             //[0, 1]
        string s5("aaa"); vector<string> w5 = {"a", "a"};                       //[0, 1]
        string s6("abababab"); vector<string> w6 = {"a", "b", "a"};             //[0, 4, 2]
        string s7("abaababbaba"); vector<string> w7 = {"ba","ab","ab"};         //[1, 3]
        string s8("aaabbbc"); vector<string> w8 = {"a","a","b","b","c"};        //[]
        runTest(s1, w1);
        runTest(s2, w2);
        runTest(s3, w3);
        runTest(s4, w4);
        runTest(s5, w5);
        runTest(s6, w6);
        runTest(s7, w7);
        runTest(s8, w8);
    }
};