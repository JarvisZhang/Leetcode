//
//  179.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/3.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Largest Number
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    static inline bool cmpStr(int a, int b) {
        string stra = to_string(a), strb = to_string(b);
        return (stra + strb) > (strb + stra);
    }
    
    static bool cmp(int a, int b) {
        int num1 = a, num2 = b;
        long top1 = 10, top2 = 10;
        while (a >= 10) {
            a /= 10;
            top1 *= 10;
        }
        while (b >= 10) {
            b /= 10;
            top2 *= 10;
        }
        long aAppendB = num1 * top2 + num2, bAppendA = num2 * top1 + num1;
        return aAppendB > bAppendA;
    }

public:
    string largestNumber(vector<int>& nums) {
        string result;
        sort(nums.begin(), nums.end(), cmp);
        for (int num : nums) {
            result.append(to_string(num));
        }
        if (result[0] == '0') {
            return "0";
        }
        return result;
    }
};

class Test {
private:
    static void runTest(int input[], int length) {
        vector<int> inputVec(input, input+length);
        Solution solution;
        string result = solution.largestNumber(inputVec);
        cout << result << endl;
    }
    
public:
    void sample() {
        int input1[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, length1 = 100;
        int input2[] = {98, 926}, length2 = 2;
        runTest(input1, length1);
        runTest(input2, length2);
    }
};