//
//  116.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/8.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Populating Next Right Pointers in Each Node
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
        if (!root) {
            return;
        }
        TreeLinkNode *upperHead = root;
        while (upperHead -> left) {
            TreeLinkNode *upperCurrent = upperHead, *downerHead = upperHead -> left;
            TreeLinkNode *temp = new TreeLinkNode(0), *downerCurrent = temp;
            while (upperCurrent) {
                downerCurrent -> next = upperCurrent -> left;
                downerCurrent = downerCurrent -> next;
                downerCurrent -> next = upperCurrent -> right;
                upperCurrent = upperCurrent -> next;
                downerCurrent = downerCurrent -> next;
            }
            delete temp;
            upperHead = downerHead;
        }
    }
};