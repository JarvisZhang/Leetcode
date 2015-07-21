//
//  129.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/8.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Sum Root to Leaf Numbers
//

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int result = 0;
        queue<TreeNode*> nodes;
        if (root != NULL) {
            nodes.push(root);
        }
        while (!nodes.empty()) {
            TreeNode* node = nodes.front();
            if (!node -> left && !node -> right) {
                result += node -> val;
            }
            if (node -> left) {
                node -> left -> val += node -> val * 10;
                nodes.push(node -> left);
            }
            if (node -> right) {
                node -> right -> val += node -> val * 10;
                nodes.push(node -> right);
            }
            nodes.pop();
        }
        return result;
    }
};