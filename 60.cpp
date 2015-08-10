//
//  60.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/30.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Permutation Sequence
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int total = 1;
        vector<bool> visited(n, false);
        string result;
        for (int i = 2; i <= n; i++) {
            total *= i;
        }
        while (n > 0) {
            total /= n--;
            int order = (k - 1) / total + 1, loc = -1;
            k -= (order - 1) * total;
            while (order > 0) {
                loc++;
                if (!visited[loc]) {
                    order--;
                }
            }
            visited[loc] = true;
            result.push_back('1' + loc);
        }
        return result;
    }
};

class Test {
public:
    void sample() {
        int n = 4, k = 1;
        Solution solution;
        cout << solution.getPermutation(n, k) << endl;
    }
};