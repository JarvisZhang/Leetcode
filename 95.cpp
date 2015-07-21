//
//  95.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/5.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Unique Binary Search Trees II
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
    vector<TreeNode*> generateTreesByRange(int start, int end) {
        vector<TreeNode*> result;
        if (start == end) {
            result.push_back(NULL);
            return result;
        }
        for (int i = start; i < end; i++) {
            vector<TreeNode*> leftTrees = generateTreesByRange(start, i);
            vector<TreeNode*> rightTrees = generateTreesByRange(i+1, end);
            for (TreeNode* lTree : leftTrees) {
                for (TreeNode* rTree : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root -> left = lTree;
                    root -> right = rTree;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return generateTreesByRange(1, n+1);
    }
};