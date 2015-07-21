//
//  104.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/10.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }
};