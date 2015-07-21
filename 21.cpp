//
//  21.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/21.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Merge Two Sorted Lists

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0), *current = head;
        while (l1 != NULL && l2 != NULL) {
            if (l1 -> val < l2 -> val) {
                current -> next = l1;
                l1 = l1 -> next;
            }
            else {
                current -> next = l2;
                l2 = l2 -> next;
            }
            current = current -> next;
        }
        if (l1 != NULL) {
            current -> next = l1;
        }
        else {
            current -> next = l2;
        }
        ListNode *result = head -> next;
        delete head;
        return result;
    }
};