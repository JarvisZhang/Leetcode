//
//  223.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/3.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Rectangle Area
//

#include <iostream>

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int result = (C - A) * (D - B) + (G - E) * (H - F);
        int xLeft = 0, xRight = 0, yTop = 0, yBottom = 0;
        if (A <= E && E <= C) {
            xLeft = E;
        }
        else if (E <= A && A <= G) {
            xLeft = A;
        }
        if (A <= G && G <= C) {
            xRight = G;
        }
        else if (E <= C && C <= G) {
            xRight = C;
        }
        if (B <= H && H <= D) {
            yTop = H;
        }
        else if (F <= D && D <= H) {
            yTop = D;
        }
        if (B <= F && F <= D) {
            yBottom = F;
        }
        else if (F <= B && B <= H) {
            yBottom = B;
        }
        return result - (xRight - xLeft) * (yTop - yBottom);
    }
};

class Test {
public:
    void sample() {
        Solution solution;
        int result = solution.computeArea(-2, -2, 2, 2, -2, -4, 2, -2);
        cout << result;
    }
};