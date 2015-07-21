//
//  215.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/8.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Kth Largest Element in an Array
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int nsize = (int) nums.size();
        if (k > nsize || k <= 0) {
            return INT_MIN;
        }
        if (nsize == 1) {
            return nums[k];
        }
        for (int current = 0; current <= (nsize - 1) / 2; current++) {
            for (int i = (nsize - 1) / 2; i >= current; i--) {
                int j = 2 * i + 1;
                if (j < nsize && nums[j] < nums[j+1]) {
                    j++;
                }
                if (nums[j] > nums[i]) {
                    swap(nums[i], nums[j]);
                }
            }
        }
        for (int i = nsize - 1; i >= nsize - k; i--) {
            int temp = nums[i], current = 1;
            nums[i] = nums[0];
            while (current < i) {
                if (nums[current] < nums[current+1]) {
                    current++;
                }
                if (nums[current] <= temp) {
                    break;
                }
                nums[(current-1)/2] = nums[current];
                current = current * 2 + 1;
            }
            nums[(current-1)/2] = temp;
        }
        return nums[nsize - k];
    }
    
    int findKthLargest_quick(vector<int>& nums, int k) {
        int start = 1, end = (int) nums.size() - 1, current = 0, target = k - 1, swapLoc = -1;
        if (target > end) {
            return INT_MIN;
        }
        while (swapLoc != target) {
            int i = start, j = end;
            while (i <= j) {
                while (i <= j && nums[i] >= nums[current]) {
                    i++;
                }
                while (i <= j && nums[j] < nums[current]) {
                    j--;
                }
                if (i < j) {
                    swap(nums[i], nums[j]);
                    i++; j--;
                }
            }
            swapLoc = i - 1;
            if (swapLoc != current) {
                swap(nums[swapLoc], nums[current]);
            }
            if (swapLoc > target) {
                end = swapLoc - 1;
            }
            else if (swapLoc < target) {
                current = swapLoc + 1;
                start = current + 1;
            }
        }
        return nums[swapLoc];
    }
};

class Test {
public:
    void sample() {
//        int input0[] = {}, length0 = 0, k0 = 4;
        int input1[] = {2, 1}, length1 = 2, k1 = 2;
        int input2[] = {3,2,1,5,6,4}, length2 = 6, k2 = 2;
        int input3[] = {1, 1}, length3 = 2, k3 = 2;
        int input4[] = {-1, 2, 0}, length4 = 3, k4 = 1;
        int input5[] = {1,2,3,4,5,6}, length5 = 6, k5 = 1;
//        runTest(input0, length0, k0);
        runTest(input1, length1, k1);
        runTest(input2, length2, k2);
        runTest(input3, length3, k3);
        runTest(input4, length4, k4);
        runTest(input5, length5, k5);
    }
    
private:
    void runTest(int input[], int length, int k) {
        Solution solution;
        vector<int> v(input, input + length);
        int result = solution.findKthLargest(v, k);
        cout << result << endl;
    }
};