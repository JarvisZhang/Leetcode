//
//  108.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/11.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Convert Sorted Array to Binary Search Tree
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTRecrusive(nums, 0, (int) nums.size());
    }
    
    TreeNode* sortedArrayToBSTRecrusive(vector<int> &nums, int start, int end) {
        if (start == end) {
            return NULL;
        }
        int middle = start + (end - start) / 2;
        TreeNode *rootNode = new TreeNode(nums[middle]);
        TreeNode *leftNode = sortedArrayToBSTRecrusive(nums, start, middle);
        TreeNode *rightNode = sortedArrayToBSTRecrusive(nums, middle+1, end);
        rootNode -> left = leftNode;
        rootNode -> right = rightNode;
        return rootNode;
    }
};