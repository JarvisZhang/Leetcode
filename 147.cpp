//
//  147.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/26.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode *top = new ListNode(0), *pre = top, *current = head;
        top -> next = head;
        while (current -> next != NULL) {
            ListNode *start = pre;
            while (start != current && start -> next -> val <= current -> next -> val) {
                start = start -> next;
            }
            if (start != current) {
                ListNode *temp = current -> next;
                current -> next = current -> next -> next;
                temp -> next = start -> next;
                start -> next = temp;
            }
            else {
                current = current -> next;
            }
        }
        head = top -> next;
        delete top;
        return head;
    }
};