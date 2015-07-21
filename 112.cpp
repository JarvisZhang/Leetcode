//
//  112.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/9.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Path Sum
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
            return false;
        }
        if (!root -> left && !root -> right) {
            return sum == root -> val;
        }
        return hasPathSum(root -> left, sum - root -> val) || hasPathSum(root -> right, sum - root -> val);
    }
};