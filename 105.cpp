//
//  105.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/12.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Construct Binary Tree from Preorder and Inorder Traversal
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<int, int> inOrderMap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inOrderMap[inorder[i]] = i;
        }
        int currentInPre = 0;
        return buildTreeRecursive(preorder, inorder, 0, (int) inorder.size(), currentInPre);
    }
    
    TreeNode* buildTreeRecursive(vector<int> &preorder, vector<int> &inorder, int start, int end, int &currentInPre) {
        if (start == end) {
            --currentInPre;
            return NULL;
        }
        int root = inOrderMap[preorder[currentInPre]];
        TreeNode *rootNode = new TreeNode(inorder[root]);
        rootNode -> left = buildTreeRecursive(preorder, inorder, start, root, ++currentInPre);
        rootNode -> right = buildTreeRecursive(preorder, inorder, root+1, end, ++currentInPre);
        return rootNode;
    }
};