//
//  204.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/3.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Count Primes
//

#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        bool isPrime[n];
        memset(isPrime, 1, sizeof(bool) * n);
        int index = 2;
        while (index <= sqrt(n)) {
            if (!isPrime[index]) {
                index++;
                continue;
            }
            for (int i = index; i <= n / index; i++) {
                isPrime[i*index] = false;
            }
            index++;
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;
            }
        }
        return count;
    }
};