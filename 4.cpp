//
//  4.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/24.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Median of Two Sorted Arrays
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    static double findKthInSortedArrays(vector<int>& nums1, vector<int>& nums2, int start1, int length1, int start2, int length2, int k) {
        if (length2 < length1) {
            return findKthInSortedArrays(nums2, nums1, start2, length2, start1, length1, k);
        }
        if (!length1) {
            return (double) nums2[start2 + k - 1];;
        }
        if (k == 1) {
            return min(nums1[start1], nums2[start2]);
        }
        int step1 = min(k / 2, length1), step2 = k - step1;
        int middle1 = start1 + step1 - 1, middle2 = start2 + step2 - 1;
        if (nums1[middle1] < nums2[middle2]) {
            return findKthInSortedArrays(nums1, nums2, middle1 + 1, length1 - step1, start2, length2, k - step1);
        }
        else if (nums1[middle1] > nums2[middle2]) {
            return findKthInSortedArrays(nums1, nums2, start1, length1, middle2 + 1, length2 - step2, k - step2);
        }
        else {
            return (double) nums1[middle1];
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length1 = (int) nums1.size(), length2 = (int) nums2.size();
        if ((length1 + length2) % 2) {
            return findKthInSortedArrays(nums1, nums2, 0, length1, 0, length2, (length1 + length2) / 2 + 1);
        }
        else {
            double median1 = findKthInSortedArrays(nums1, nums2, 0, length1, 0, length2, (length1 + length2) / 2);
            double median2 = findKthInSortedArrays(nums1, nums2, 0, length1, 0, length2, (length1 + length2) / 2 + 1);
            return (median1 + median2) / 2.0;
        }
    }
};

class Test {
private:
    static void runTest(int input1[], int input2[], int length1, int length2) {
        vector<int> nums1(input1, input1 + length1), nums2(input2, input2 + length2);
        Solution solution;
        double result = solution.findMedianSortedArrays(nums1, nums2);
        cout << result << endl;
    }
    
public:
    void sample() {
        int inputa1[] = {1, 3, 5}, inputb1[] = {2, 4}, lengtha1 = 3, lengthb1 = 2;
        int inputa2[] = {2}, inputb2[] = {1}, lengtha2 = 1, lengthb2 = 1;
        int inputa3[] = {3}, inputb3[] = {1, 2, 4}, lengtha3 = 1, lengthb3 = 3;
        runTest(inputa1, inputb1, lengtha1, lengthb1);
        runTest(inputa2, inputb2, lengtha2, lengthb2);
        runTest(inputa3, inputb3, lengtha3, lengthb3);
    }
};