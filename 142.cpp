//
//  142.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/18.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Linked List Cycle II
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *walker = head, *runner = head;
        while (walker != NULL && runner != NULL) {
            walker = walker -> next;
            runner = runner -> next;
            if (runner != NULL) {
                runner = runner -> next;
            }
            else {
                return  NULL;
            }
            if (walker == runner) {
                break;
            }
        }
        if (runner == NULL) {
            return NULL;
        }
        while (head != walker) {
            head = head -> next;
            walker = walker -> next;
        }
        return walker;
    }
};