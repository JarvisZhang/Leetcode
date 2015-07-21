//
//  138.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/21.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Copy List with Random Pointer
//

#include <iostream>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        RandomListNode *current = head;
        while (current != NULL) {
            RandomListNode *shadow = new RandomListNode(current -> label);
            shadow -> next = current -> next;
            current -> next = shadow;
            current = shadow -> next;
        }
        current = head;
        while (current != NULL) {
            RandomListNode *shadow = current -> next;
            if (current -> random != NULL) {
                shadow -> random = current -> random -> next;
            }
            else {
                shadow -> random = NULL;
            }
            current = shadow -> next;
        }
        RandomListNode *oldList = head, *newList = head -> next;
        current = newList;
        while (oldList != NULL) {
            oldList -> next = current -> next;
            oldList = oldList -> next;
            if (oldList != NULL) {
                current -> next = oldList -> next;
            }
            else {
                current -> next = NULL;
            }
            current = current -> next;
        }
        return newList;
    }
};
