//
//  235.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/13.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Lowest Common Ancestor of a Binary Search Tree
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *smaller = p -> val < q -> val ? p : q;
        TreeNode *bigger = p -> val > q -> val ? p : q;
        while (root != NULL) {
            if (root -> val < smaller -> val) {
                root = root -> right;
            }
            else if (root -> val > bigger -> val) {
                root = root -> left;
            }
            else {
                break;
            }
        }
        return root;
    }
};