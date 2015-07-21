//
//  164.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/3.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Maximum Gap
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int maximum = INT_MIN, minimum = INT_MAX;
        for (int num : nums) {
            minimum = min(minimum, num);
            maximum = max(maximum, num);
        }
        int gap = (int) ceil((double) (maximum - minimum) / (nums.size() - 1));
        int bucketSize = (maximum - minimum) / gap + 1;
        vector<int> minBucket(bucketSize, INT_MAX), maxBucket(bucketSize, INT_MIN);
        for (int num : nums) {
            int loc = (num - minimum) / gap;
            minBucket[loc] = min(minBucket[loc], num);
            maxBucket[loc] = max(maxBucket[loc], num);
        }
        int result = 0, i = 1, j = 0;
        while (i < bucketSize) {
            if (minBucket[i] == INT_MAX) {
                i++;
            }
            else if (maxBucket[i] == INT_MIN) {
                j++;
            }
            else {
                result = max(minBucket[i] - maxBucket[j], result);
                j = i++;
            }
        }
        return result;
    }
};

class Test {
private:
    static void runTest(int input[], int length) {
        vector<int> nums(input, input+length);
        Solution solution;
        int result = solution.maximumGap(nums);
        cout << result << endl;
    }
    
public:
    void sample() {
        int input1[] = {1,10000000} ,length1 = 2;
        int input2[] = {1,1,1,1,1,5,5,5,5,5}, length2 = 10;
        runTest(input1, length1);
        runTest(input2, length2);
    }
};