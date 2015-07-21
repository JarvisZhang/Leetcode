//
//  230.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/12.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Kth Smallest Element in a BST
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    int leftCount, rightCount;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> nodes;
        while (root != NULL || !nodes.empty()) {
            while (root != NULL) {
                nodes.push(root);
                root = root -> left;
            }
            root = nodes.top();
            nodes.pop();
            if (--k == 0) {
                return root -> val;
            }
            root = root -> right;
        }
        return INT_MIN;
    }
    
    void buildTreeWithCount (TreeNode* root) {
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
                nodes.pop();
                visited.pop();
                root -> leftCount = root -> left == NULL ? 0 : root -> left -> leftCount + root -> left -> rightCount + 1;
                root -> rightCount = root -> right == NULL ? 0 : root -> right -> leftCount + root -> right -> rightCount + 1;
                root = NULL;
            }
            else {
                visited.top() = true;
                root = root -> right;
            }
        }
    }
};