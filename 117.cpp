//
//  117.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/8.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Populating Next Right Pointers in Each Node II
//

#include <iostream>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *upperHead = root;
        while (upperHead) {
            TreeLinkNode *upperCurrent = upperHead, *downerHead;
            while (upperCurrent && !upperCurrent -> left && !upperCurrent -> right) {
                upperCurrent = upperCurrent -> next;
            }
            if (!upperCurrent) {
                break;
            }
            downerHead = upperCurrent -> left ? upperCurrent -> left : upperCurrent -> right;
            TreeLinkNode *temp = new TreeLinkNode(0), *downerCurrent = temp;
            while (upperCurrent) {
                if (upperCurrent -> left) {
                    downerCurrent -> next = upperCurrent -> left;
                    downerCurrent = downerCurrent -> next;
                }
                if (upperCurrent -> right) {
                    downerCurrent -> next = upperCurrent -> right;
                    downerCurrent = downerCurrent -> next;
                }
                upperCurrent = upperCurrent -> next;
            }
            delete temp;
            upperHead = downerHead;
        }
    }
};

class Test {
private:
    void printTreeLinkNode(TreeLinkNode *root) {
        TreeLinkNode *current = root;
        while (current) {
            cout << current -> val << ", " << endl;
            current = current -> next;
        }
        printTreeLinkNode(root -> left);
    }
    
    void runTest(TreeLinkNode *root) {
        Solution solution;
        solution.connect(root);
        printTreeLinkNode(root);
    }
    
public:
    void sample() {
        TreeLinkNode *node1 = new TreeLinkNode(1);
        TreeLinkNode *node2 = new TreeLinkNode(2);
        TreeLinkNode *node3 = new TreeLinkNode(3);
        node1 -> left = node2;
        node1 -> right = node3;
        runTest(node1);
    }
};