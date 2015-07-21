//
//  124.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/13.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Binary Tree Maximum Path Sum
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        maxPathSumRecursive(root, result);
        return result;
    }
    
    int maxPathSumRecursive(TreeNode* root, int &result) {
        if (root == nullptr) {
            return 0;
        }
        int leftSum = maxPathSumRecursive(root -> left, result);
        int rightSum = maxPathSumRecursive(root -> right, result);
        int current = max(root -> val, max(leftSum, rightSum) + root -> val);
        result = max(result, max(current, leftSum + rightSum + root -> val));
        return current;
    }
};