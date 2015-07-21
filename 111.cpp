//
//  111.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/10.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        deque<TreeNode*> nodes;
        TreeNode *last, *current;
        int depth = 0;
        nodes.push_back(root);
        while (root != NULL && !nodes.empty()) {
            last = nodes.back();
            depth++;
            do {
                current = nodes.front();
                nodes.pop_front();
                if (current -> left == NULL && current -> right == NULL) {
                    return depth;
                }
                if (current -> left != NULL) {
                    nodes.push_back(current -> left);
                }
                if (current -> right != NULL) {
                    nodes.push_back(current -> right);
                }
            } while (current != last);
        }
        return depth;
    }
};