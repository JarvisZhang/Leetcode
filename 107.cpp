//
//  107.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/11.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        int depth = 1;
        levelOrderBottomRecursive(result, depth, root);
        reverse(result.begin(), result.end());
        return result;
    }
    
    void levelOrderBottomRecursive(vector<vector<int>> &result, int depth, TreeNode* current) {
        if (current == NULL) {
            return;
        }
        if (result.size() < depth) {
            result.push_back(vector<int>());
        }
        result[depth-1].push_back(current -> val);
        levelOrderBottomRecursive(result, depth+1, current -> left);
        levelOrderBottomRecursive(result, depth+1, current -> right);
    }
};