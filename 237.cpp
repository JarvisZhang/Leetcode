//
//  237.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/15.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Delete Node in a Linked List
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
    void deleteNode(ListNode* node) {
        ListNode *temp = node -> next;
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
        delete temp;
    }
};