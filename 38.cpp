//
//  38.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/16.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Count and Say
//

#include <iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string countNum("1"), sayNum("11");
        if (n == 1) {
            return countNum;
        }
        for (int i = 2; i < n; i++) {
            int count = 1;
            countNum = sayNum;
            sayNum.clear();
            for (int j = 0; j < countNum.length() - 1; j++) {
                if (countNum[j] == countNum[j + 1]) {
                    count++;
                }
                else {
                    sayNum.push_back('0' + count);
                    sayNum.push_back(countNum[j]);
                    count = 1;
                }
            }
            sayNum.push_back('0' + count);
            sayNum.push_back(countNum[countNum.length() - 1]);
        }
        return sayNum;
    }
};

class Test {
private:
    static void runTest(int n) {
        Solution solution;
        string result = solution.countAndSay(n);
        cout << result << endl;
    }
    
public:
    void sample() {
        for(int i = 1; i < 10; i++) {
            runTest(i);
        }
    }
};
