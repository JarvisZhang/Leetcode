//
//  144.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/11.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> traversal;
        stack<TreeNode*> nodes;
        while (root != NULL || !nodes.empty()) {
            while (root != NULL) {
                traversal.push_back(root -> val);
                nodes.push(root);
                root = root -> left;
            }
            root = nodes.top();
            nodes.pop();
            root = root -> right;
        }
        return traversal;
    }
};