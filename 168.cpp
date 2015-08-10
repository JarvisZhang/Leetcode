//
//  168.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/2.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Excel Sheet Column Title
//

#include <iostream>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string title;
        while (n != 0) {
            n--;
            title.push_back('A' + n % 26);
            n /= 26;
        }
        reverse(title.begin(), title.end());
        return title;
    }
};