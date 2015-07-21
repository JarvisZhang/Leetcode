//
//  173.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/14.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Binary Search Tree Iterator
//

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    queue<TreeNode*> inorder;
    
    BSTIterator(TreeNode *root) {
        stack<TreeNode*> nodes;
        while (root != NULL || !nodes.empty()) {
            while (root != NULL) {
                nodes.push(root);
                root = root -> left;
            }
            root = nodes.top();
            inorder.push(root);
            nodes.pop();
            root = root -> right;
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !inorder.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        if (inorder.empty()) {
            return INT_MIN;
        }
        int val = inorder.front() -> val;
        inorder.pop();
        return val;
    }
};

class Test {
public:
    void sample() {
        TreeNode *node1 = new TreeNode(1);
        BSTIterator bsiIterator = BSTIterator(node1);
        while (bsiIterator.hasNext()) {
            cout << bsiIterator.next() << endl;
        }
    }
};