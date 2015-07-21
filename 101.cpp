//
//  101.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/8.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title:
//

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        queue<TreeNode*> leftTrees, rightTrees;
        leftTrees.push(root -> left);
        rightTrees.push(root -> right);
        while (!leftTrees.empty() && !rightTrees.empty()) {
            TreeNode* leftTree = leftTrees.front();
            TreeNode* rightTree = rightTrees.front();
            leftTrees.pop(); rightTrees.pop();
            if (leftTree != NULL && rightTree != NULL && leftTree -> val == rightTree -> val) {
                leftTrees.push(leftTree -> left); leftTrees.push(leftTree -> right);
                rightTrees.push(rightTree -> right); rightTrees.push(rightTree -> left);
            }
            else if (!(leftTree == NULL && rightTree == NULL)) {
                return false;
            }
        }
        if (leftTrees.empty() && rightTrees.empty()) {
            return true;
        }
        return false;
    }
};