//
//  222.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/18.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Count Complete Tree Nodes
//

#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        int depth = 0, count = 0;
        TreeNode *current = root;
        while (current != NULL) {
            current = current -> left;
            depth++;
        }
        if (depth > 0) {
            count += pow(2, depth - 1) - 1;
        }
        current = root;
        while (depth > 1) {
            TreeNode *temp = current -> left;
            int tempDepth = 1;
            while (temp!= NULL) {
                temp = temp -> right;
                tempDepth++;
            }
            if (tempDepth < depth) {
                current = current -> left;
            }
            else {
                count += pow(2, depth - 2);
                current = current -> right;
            }
            depth--;
        }
        if (current != NULL) {
            count++;
        }
        return count;
    }
};