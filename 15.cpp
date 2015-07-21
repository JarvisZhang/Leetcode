//
//  15.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/2.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: 3Sum
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size()) {
            int target = -nums[i], start = i + 1, end = (int) nums.size() - 1;
            while (start < end) {
                int current = nums[start] + nums[end];
                if (current < target) {
                    start++;
                }
                else if (current > target) {
                    end--;
                }
                else {
                    result.push_back({nums[i], nums[start], nums[end]});
                    int currentStart = nums[start], currentEnd = nums[end];
                    start++; end--;
                    while (start < end && nums[start] == currentStart) {
                        start++;
                    }
                    while (start < end && nums[end] == currentEnd) {
                        end--;
                    }
                }
            }
            int j = i + 1;
            while (j < nums.size() && nums[j] == nums[i]) {
                j++;
            }
            i = j;
        }
        return result;
    }
    
    vector<vector<int>> threeSum_Hash(vector<int>& nums) {
        vector<vector<int>> result;
        unordered_map<int, int> locHash;
        if (nums.size() < 3) {
            return result;
        }
        for (int i = 0; i < nums.size(); i++) {
            locHash[nums[i]] = i;
        }
        for (int i = 0; i < nums.size() - 2; i++) {
            int target = -nums[i];
            for (int j = i + 1; j < nums.size() - 1; j++) {
                auto it = locHash.find(target - nums[j]);
                if (it != locHash.end() && it -> second > j) {
                    vector<int> triplet = {nums[i], nums[j], target - nums[j]};
                    sort(triplet.begin(), triplet.end());
                    if (find(result.begin(), result.end(), triplet) == result.end()) {
                        result.push_back(triplet);
                    }
                }
            }
        }
        return result;
    }
};

class Test {
public:
    void sample() {
        int input1[] = {}, length1 = 0;
        int input2[] = {-1, 0, 1, 2, -1, 4}, length2 = 6;
        int input3[] = {-14,-3,11,-3,12,-1,11,13,5,6,-11,-14,-6,11,-4,-15,3,-15,9,-10,13,-10,-9,-13,-12,12,-7,12,12,3,9,5,-14,-3,9,13,11,5,3,-6,-12,-1,-5,-3,-4,-2,-10,6,-10,14,3,-11,11,10,-9,7,-1,-9,4,-12,2,-2,8,3,3,-6,-7,-1,6,12,8,9,-12,10,-8,-1,-7,-3,12,-9,-12,1,-5,6,-12,-7,-2,2,-8,-13,5,9,-7,-10,-3,11,-1,-3,-13,-10,-14,11,6,-10,6,13,4,7,-13,-6,13,12,10,-15,4,13,-7,9,-8,0,4,4,-6,12,9,-2,0}, length3 = 127;

        runTest(input1, length1);
        runTest(input2, length2);
        runTest(input3, length3);
    }
    
private:
    static void runTest(int input[], int length) {
        vector<int> v(input, input + length);
        Solution* s = new Solution();
        vector<vector<int>> result = s -> threeSum(v);
        for (vector<int> triplet : result) {
            cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << endl;
        }
        cout << endl;
    }
};