//
//  99.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/8.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Recover Binary Search Tree
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *pre = new TreeNode(INT_MIN), *first = NULL, *second =NULL;
        recoverTreeRecrusive(root, pre, first, second);
        swap(first -> val, second -> val);
    }
    
    void recoverTreeRecrusive(TreeNode* current, TreeNode* &pre, TreeNode* &first, TreeNode* &second) {
        if (current == NULL) {
            return;
        }
        recoverTreeRecrusive(current -> left, pre, first, second);
        if (current -> val < pre -> val) {
            if (first == NULL){
                first = pre;
                second = current;
            }
            else {
                second = current;
            }
        }
        pre = current;
        recoverTreeRecrusive(current -> right, pre, first, second);
    }
};

class Test {
public:
    void sample() {
        TreeNode* node68 = new TreeNode(68);
        TreeNode* node41 = new TreeNode(41);
        TreeNode* node_85 = new TreeNode(-85);
        TreeNode* node_73 = new TreeNode(-73);
        TreeNode* node_98 = new TreeNode(-98);
        TreeNode* node_124 = new TreeNode(-124);
        TreeNode* node_49 = new TreeNode(-49);
        node68 -> left = node41;
        node41 -> left = node_85;
        node_85 -> left = node_73;
        node_85 -> right = node_49;
        node_73 -> left = node_98;
        node_98 -> left = node_124;
        Solution solution;
        solution.recoverTree(node68);
    }
};