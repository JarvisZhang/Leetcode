//
//  86.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/20.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Partition List
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) {
            return head;
        }
        ListNode *top = new ListNode(0), *front = top;
        top -> next = head;
        while (front -> next != NULL) {
            ListNode *middle = front;
            while (middle -> next != NULL && middle -> next -> val >= x) {
                middle = middle -> next;
            }
            ListNode *rear = middle;
            while (rear -> next != NULL && rear -> next -> val < x) {
                rear = rear -> next;
            }
            if (front != middle && middle != rear) {
                ListNode *temp = middle -> next;
                middle -> next = rear -> next;
                rear -> next = front -> next;
                front -> next = temp;
            }
            front = rear;
        }
        head = top -> next;
        delete top;
        return head;
    }
};
