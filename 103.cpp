//
//  103.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/12.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Binary Tree Zigzag Level Order Traversal
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        deque<TreeNode*> nodes;
        TreeNode *lastLevel;
        nodes.push_back(root);
        while (!nodes.empty()) {
            vector<int> temp;
            if (result.size() % 2) {
                lastLevel = nodes.front();
                do {
                    root = nodes.back();
                    nodes.pop_back();
                    temp.push_back(root -> val);
                    if (root -> right != NULL) {
                        nodes.push_front(root -> right);
                    }
                    if (root -> left != NULL) {
                        nodes.push_front(root -> left);
                    }
                } while (root != lastLevel);
            }
            else {
                lastLevel = nodes.back();
                do {
                    root = nodes.front();
                    nodes.pop_front();
                    temp.push_back(root -> val);
                    if (root -> left != NULL) {
                        nodes.push_back(root -> left);
                    }
                    if (root -> right != NULL) {
                        nodes.push_back(root -> right);
                    }
                } while (root != lastLevel);
            }
            result.push_back(temp);
            temp.clear();
        }
        return result;
    }
};