//
//  257.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/9/8.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Binary Tree Paths
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        if (root == NULL) {
            return result;
        }
        path = to_string(root -> val);
        if (root -> left == NULL && root -> right == NULL) {
            result.push_back(path);
            return result;
        }
        if (root -> left != NULL) {
            binaryTreePathsRecur(result, path, root -> left);
        }
        if (root -> right != NULL) {
            binaryTreePathsRecur(result, path, root -> right);
        }
        return result;
    }
    
    void binaryTreePathsRecur(vector<string> &result, string &path, TreeNode *currentNode) {
        string currentVal = to_string(currentNode -> val);
        path += "->" + currentVal;
        if (currentNode -> left == NULL && currentNode -> right == NULL) {
            result.push_back(path);
            path.erase(path.end() - currentVal.size() - 2, path.end());
            return;
        }
        if (currentNode -> left != NULL) {
            binaryTreePathsRecur(result, path, currentNode -> left);
        }
        if (currentNode -> right != NULL) {
            binaryTreePathsRecur(result, path, currentNode -> right);
        }
        path.erase(path.end() - currentVal.size() - 2, path.end());
    }
};