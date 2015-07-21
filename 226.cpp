//
//  226.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/12.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Invert Binary Tree
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> nodes;
        stack<bool> visited;
        TreeNode *result = root;
        while (root != NULL || !nodes.empty()) {
            while (root != NULL) {
                nodes.push(root);
                visited.push(false);
                root = root -> left;
            }
            root = nodes.top();
            if (visited.top()) {
                nodes.pop();
                visited.pop();
                TreeNode *temp = root -> left;
                root -> left = root -> right;
                root -> right = temp;
                root = NULL;
            }
            else {
                visited.top() = true;
                root = root -> right;
            }
        }
        return result;
    }
};