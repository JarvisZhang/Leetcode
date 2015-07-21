//
//  25.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/25.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Reverse Nodes in k-Group
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k < 2) {
            return head;
        }
        ListNode *top = new ListNode(0), *front = top, *pre = head, *current;
        top -> next = head;
        while (pre != NULL) {
            current = pre -> next;
            ListNode *rear = current;
            int count = 1;
            while (rear != NULL && count++ < k - 1) {
                rear = rear -> next;
            }
            if (rear == NULL) {
                break;
            }
            ListNode *post, *nextFront = front -> next;
            front -> next = rear;
            pre -> next = rear -> next;
            while (pre != rear) {
                post = current -> next;
                current -> next = pre;
                pre = current;
                current = post;
            }
            front = nextFront;
            pre = current;
        }
        head = top -> next;
        delete top;
        return head;
    }
};