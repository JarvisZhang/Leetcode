//
//  236.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/13.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Lowest Common Ancestor of a Binary Tree
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> nodes;
        vector<bool> visited;
        vector<TreeNode*> path;
        bool findFirst = false;
        while (root != NULL || !nodes.empty()) {
            while (root != NULL) {
                nodes.push_back(root);
                visited.push_back(false);
                root = root -> left;
            }
            root = nodes.back();
            if (visited.back()) {
                if (root == p || root == q) {
                    if (findFirst) {
                        return path.back();
                    }
                    else {
                        findFirst = true;
                        path.assign(nodes.begin(), nodes.end());
                    }
                }
                if (!path.empty() && path.back() == root) {
                    path.pop_back();
                }
                nodes.pop_back();
                visited.pop_back();
                root = NULL;
            }
            else {
                root = root -> right;
                visited.back() = true;
            }
        }
        return root;
    }
    
    TreeNode* lowestCommonAncestorRecursive(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }
        if (root == p || root == q) {
            return root;
        }
        TreeNode *inLeft = lowestCommonAncestorRecursive(root -> left, p, q);
        TreeNode *inRight = lowestCommonAncestorRecursive(root -> right, p, q);
        if (inLeft != NULL && inRight != NULL) {
            return root;
        }
        return inLeft != NULL ? inLeft : inRight;
    }
};

class Test {
public:
    void sample() {
        TreeNode *node_1 = new TreeNode(-1);
        TreeNode *node0 = new TreeNode(0);
        TreeNode *node3 = new TreeNode(3);
        TreeNode *node_2 = new TreeNode(-2);
        TreeNode *node4 = new TreeNode(4);
        TreeNode *node8 = new TreeNode(8);
        node_1 -> left = node0;
        node_1 -> right = node3;
        node0 -> left = node_2;
        node0 -> right = node4;
        node_2 -> left = node8;
        Solution solution;
        TreeNode *result = solution.lowestCommonAncestor(node_1, node_1, node_2);
        cout << result -> val;
    }
};