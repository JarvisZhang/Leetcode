//
//  113.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/9.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Path Sum II
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        stack<TreeNode*> nodes;
        stack<bool> visited;
        while (root != NULL || !nodes.empty()) {
            while (root != NULL) {
                path.push_back(root -> val);
                nodes.push(root);
                visited.push(false);
                sum -= root -> val;
                root = root -> left;
            }
            root = nodes.top();
            if (visited.top()) {
                if (root -> left == NULL && root -> right == NULL && sum == 0) {
                    result.push_back(path);
                }
                visited.pop();
                nodes.pop();
                path.pop_back();
                sum += root -> val;
                root = NULL;
            }
            else {
                visited.top() = true;
                root = root -> right;
            }
        }
        return result;
    }
    
    void pathSumRecrusive(TreeNode* root, int sum, vector<int> path, vector<vector<int>>& result) {
        if (!root) {
            return;
        }
        path.push_back(root -> val);
        if (root -> left == NULL && root -> right == NULL && root -> val == sum) {
            result.push_back(path);
        }
        else {
            pathSumRecrusive(root -> left, sum - root -> val, path, result);
            pathSumRecrusive(root -> right, sum - root -> val, path, result);
        }
    }
};

class Test {
public:
    void sample () {
        Solution solution;
        TreeNode *node1 = new TreeNode(1), *node2 = new TreeNode(2);
        node1 -> left = node2;
        vector<vector<int>> result = solution.pathSum(node1, 1);
    }
};