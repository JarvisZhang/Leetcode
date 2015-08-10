//
//  114.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/10.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: 
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
    void flatten(TreeNode* root) {
        while (root != NULL) {
            if (root -> left != NULL) {
                TreeNode *leftTail = root -> left;
                while (leftTail -> right != NULL) {
                    leftTail = leftTail -> right;
                }
                leftTail -> right = root -> right;
                root -> right = root -> left;
                root -> left = NULL;
            }
            root = root -> right;
        }
    }
    
    TreeNode* flattenRecrusive(TreeNode* current) {
        if (current == NULL || (current -> left == NULL && current -> right == NULL)) {
            return current;
        }
        TreeNode *leftTail = flattenRecrusive(current -> left);
        TreeNode *rightTail = flattenRecrusive(current -> right);
        if (leftTail != NULL) {
            leftTail -> right = current -> right;
            current -> right = current -> left;
        }
        current -> left = NULL;
        if (rightTail != NULL) {
            return rightTail;
        }
        else {
            return leftTail;
        }
    }
};