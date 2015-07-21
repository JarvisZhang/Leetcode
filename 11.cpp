//
//  11.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/1.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int front = 0, rear = (int) height.size() - 1, maxVol = 0, currentHeight = 0;
        while (front < rear) {
            if (height[front] <= currentHeight) {
                front++;
                continue;
            }
            if (height[rear] <= currentHeight) {
                rear--;
                continue;
            }
            maxVol = max(min(height[rear],height[front]) * abs(rear - front), maxVol);
            if (height[front] < height[rear]) {
                currentHeight = height[front];
                front++;
                
            }
            else if (height[front] > height[rear]) {
                currentHeight = height[rear];
                rear--;
            }
            else {
                currentHeight = height[front];
                front++;rear--;
            }
        }
        return maxVol;
    }
};
