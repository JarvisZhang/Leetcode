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
        ListNode *top1 = new ListNode(0),*top2 = new ListNode(0);
        ListNode *sCurrent = top1, *bCurrent = top2;
        while (head != NULL) {
            ListNode *temp = head;
            head = head -> next;
            if (temp -> val < x) {
                sCurrent -> next = temp;
                sCurrent = sCurrent -> next;
            }
            else {
                bCurrent -> next = temp;
                bCurrent = bCurrent -> next;
            }
        }
        ListNode *current = sCurrent;
        if (top2 -> next != NULL ) {
            current -> next = top2 -> next;
            current = bCurrent;
        }
        current -> next = NULL;
        head = top1 -> next;
        delete top1; delete top2;
        return head;
    }
};

class Test {
public:
    void sample() {
        Solution solution;
        ListNode *node1 = new ListNode(2), *node2 = new ListNode(1);
        node1 -> next = node2;
        solution.partition(node1, 1);
    }
};
