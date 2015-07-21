//
//  151.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/18.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title:  Reverse Words in a String
//
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int rear = (int) s.length() - 1;
        string result;
        while (rear >= 0) {
            if (s[rear] != ' ') {
                int front = rear;
                while (front >= 0 && s[--front] != ' ') ;
                for (int i = front + 1; i <= rear; i++) {
                    result.push_back(s[i]);
                }
                result.push_back(' ');
                rear = front;
            }
            else {
                rear--;
            }
        }
        s = result.substr(0, result.length() - 1);
    }
};

class Test {
private:
    static void runTest(string &s) {
        Solution solution;
        cout << "\"" << s << "\"" << " -> ";
        solution.reverseWords(s);
        cout << "\"" << s << "\"" << endl;
    }
    
public:
    void sample() {
        string s1("the sky is blue");
        string s2("  ");
        string s3("");
        string s4("  hello   world   ");
        string s5("hello");
        runTest(s1);
        runTest(s2);
        runTest(s3);
        runTest(s4);
        runTest(s5);
    }
};
