//
//  110.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/11.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Balanced Binary Tree
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
    bool isBalanced(TreeNode* root) {
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
                if (root -> left == NULL && root -> right == NULL) {
                    root -> val = 1;
                }
                else {
                    int leftHeight = root -> left == NULL ? 0 : root -> left -> val;
                    int rightHeight = root -> right == NULL ? 0 : root -> right -> val;
                    if (abs(leftHeight - rightHeight) > 1) {
                        return false;
                    }
                    else {
                        root -> val = max(leftHeight, rightHeight) + 1;
                    }
                }
                root = NULL;
            }
            else {
                visited.top() = true;
                root = root -> right;
            }
        }
        return true;
    }
    
    int treeHeight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return max(treeHeight(root -> left), treeHeight(root -> right)) + 1;
    }
};

class Test {
public:
    void sample() {
        TreeNode *node1 = new TreeNode(1), *node2 = new TreeNode(2), *node3 = new TreeNode(3);
        node2 -> left = node1; node2 -> right = node3;
        Solution solution;
        solution.isBalanced(node2);
    }
};