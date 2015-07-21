//
//  82.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/25.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Remove Duplicates from Sorted List II
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *top = new ListNode(0), *pre = top, *front = head;
        top -> next = head;
        while (front != NULL) {
            ListNode *rear = front -> next;
            while (rear != NULL && front -> val == rear -> val) {
                rear = rear -> next;
            }
            if (front -> next != rear) {
                while (front != rear) {
                    ListNode *temp = front;
                    front = front -> next;
                    delete temp;
                }
                pre -> next = rear;
            }
            else {
                pre = front;
                front = rear;
            }
        }
        head = top -> next;
        delete top;
        return head;
    }
};