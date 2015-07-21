//
//  102.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/11.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> traveral;
        deque<TreeNode*> nodes;
        TreeNode *lastLevel, *current;
        vector<int> temp;
        if (root == NULL) {
            return traveral;
        }
        nodes.push_back(root);
        while (!nodes.empty()) {
            lastLevel = nodes.back();
            do {
                current = nodes.front();
                nodes.pop_front();
                temp.push_back(current -> val);
                if (current -> left != NULL) {
                    nodes.push_back(current -> left);
                }
                if (current -> right != NULL) {
                    nodes.push_back(current -> right);
                }
            } while (lastLevel != current);
            traveral.push_back(temp);
            temp.clear();
        }
        return traveral;
    }
};