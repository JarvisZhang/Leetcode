//
//  98.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/5.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Validate Binary Search Tree
//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isBST(root, NULL, NULL);
    }
    
    bool isBST(TreeNode* node, TreeNode* leftBorder, TreeNode* rightBorder) {
        if (node == NULL) {
            return true;
        }
        if (node -> left && (node -> left -> val >= node -> val || (leftBorder && node -> left -> val <= leftBorder -> val)))
        {
            return false;
        }
        if (node -> right && (node -> right -> val <= node -> val || (rightBorder && node -> right -> val >= rightBorder -> val))) {
            return false;
        }
        return isBST(node -> left, leftBorder, node) && isBST(node -> right, node, rightBorder);
    }
};