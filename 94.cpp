//
//  94.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/11.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        stack<TreeNode*> nodes;
        while (root != NULL || !nodes.empty()) {
            while (root != NULL) {
                nodes.push(root);
                root = root -> left;
            }
            root = nodes.top();
            nodes.pop();
            traversal.push_back(root -> val);
            root = root -> right;
        }
        return traversal;
    }
    
    void inorderTraversalRecrusive(TreeNode* root, vector<int> &traversal) {
        if (root == NULL) {
            return;
        }
        inorderTraversalRecrusive(root -> left, traversal);
        traversal.push_back(root -> val);
        inorderTraversalRecrusive(root -> right, traversal);
    }
};