//
//  145.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/11.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> traversal;
        stack<TreeNode*> nodes;
        stack<bool> visited;
        while (root != NULL || !nodes.empty()) {
            while (root != NULL) {
                nodes.push(root);
                visited.push(false);
                root = root -> left;
            }
            root = nodes.top();
            if (visited.top()) {
                traversal.push_back(root -> val);
                nodes.pop();
                visited.pop();
                root = NULL;
            }
            else {
                visited.top() = true;
                root = root -> right;
            }
        }
        return traversal;
    }
};