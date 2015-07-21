//
//  106.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/12.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        stack<TreeNode*> parents;
        int i = 0, j = 0;
        TreeNode *current = nullptr;
        while (j < postorder.size()) {
            if (!parents.empty() && parents.top() -> val == postorder[j]) {
                parents.top() -> right = current;
                current = parents.top();
                parents.pop();
                j++;
            }
            else {
                TreeNode *newNode = new TreeNode(inorder[i++]);
                newNode -> left = current;
                parents.push(newNode);
                current = nullptr;
            }
        }
        return current;
    }
};