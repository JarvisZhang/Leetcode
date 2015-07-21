//
//  100.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/8.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Same Tree
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        else if (!p || !q || p -> val != q -> val) {
            return false;
        }
        return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
    }
};