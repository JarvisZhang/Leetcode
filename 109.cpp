//
//  109.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/14.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int length = 0;
        ListNode *current = head;
        while (current != NULL) {
            current = current -> next;
            length++;
        }
        return sortedListToBSTRecursive(head, length);
    }
    
    TreeNode* sortedListToBSTRecursive(ListNode* &head, int length) {
        if (length == 0) {
            return NULL;
        }
        TreeNode *leftTree = sortedListToBSTRecursive(head, length/2);
        TreeNode *root = new TreeNode(head -> val);
        head = head -> next;
        TreeNode *rightTree = sortedListToBSTRecursive(head, length-length/2-1);
        root -> left = leftTree;
        root -> right = rightTree;
        return root;
    }
};