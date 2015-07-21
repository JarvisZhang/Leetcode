//
//  160.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/21.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode_twocycle(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        ListNode *currentA = headA, *currentB = headB;
        int count = 0;
        while (count < 2) {
            currentA = currentA -> next;
            currentB = currentB -> next;
            if (currentA == NULL) {
                currentA = headB;
                count++;
            }
            if (currentB == NULL) {
                currentB = headA;
                count++;
            }
        }
        while (currentA != NULL && currentB != NULL) {
            if (currentA == currentB) {
                return currentA;
            }
            currentA = currentA -> next;
            currentB = currentB -> next;
        }
        return NULL;
    }
};
