//
//  75.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/2.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Sort Colors
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, red = 0, blue = (int) nums.size() - 1;
        while (i <= blue) {
            if (nums[i] == 0) {
                nums[i++] = nums[red];
                nums[red++] = 0;
            }
            else if (nums[i] == 2) {
                nums[i] = nums[blue];
                nums[blue--] = 2;
            }
            else {
                i++;
            }
        }
    }
};