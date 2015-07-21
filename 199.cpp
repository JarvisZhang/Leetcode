//
//  199.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/12.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Binary Tree Right Side View
//

#include <iostream>
#include <vector>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        TreeNode *lastLevel;
        deque<TreeNode*> nodes;
        if (root == NULL) {
            return result;
        }
        nodes.push_back(root);
        while (!nodes.empty()) {
            lastLevel = nodes.back();
            result.push_back(lastLevel -> val);
            do {
                root = nodes.front();
                nodes.pop_front();
                if (root -> left != NULL) {
                    nodes.push_back(root -> left);
                }
                if (root -> right != NULL) {
                    nodes.push_back(root -> right);
                }
            } while (root != lastLevel);
        }
        return result;
    }
};