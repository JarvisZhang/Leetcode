//
//  88.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/17.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Merge Sorted Array
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, loc = m + n;
        nums1.resize(loc--);
        while (i >= 0 && j >= 0) {
            nums1[loc--] = (nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
        }
        while (j >= 0) {
            nums1[loc--] = nums2[j--];
        }
    }
};

class Test {
private:
    static void runTest(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i < nums1.size(); i++) {
            cout << nums1[i] << ", ";
        }
        cout << "-> ";
        Solution solution;
        solution.merge(nums1, (int) nums1.size(), nums2, (int) nums2.size());
        for (int i = 0; i < nums1.size(); i++) {
            cout << nums1[i] << ", ";
        }
        cout << endl;
    }
    
public:
    void sample() {
        vector<int> numsa1({1, 3, 5, 7}), numsb1({2, 4, 6, 8});
        vector<int> numsa2({2, 4, 6, 8}), numsb2({1, 3, 5, 7});
        vector<int> numsa3({}), numsb3({2});
        runTest(numsa1, numsb1);
        runTest(numsa2, numsb2);
        runTest(numsa3, numsb3);
    }
};