//
//  141.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/18.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Linked List Cycle
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
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        ListNode *walker = head, *runner = head -> next;
        while (walker != NULL && runner != NULL) {
            if (walker == runner) {
                return true;
            }
            walker = walker -> next;
            runner = runner -> next;
            if (runner != NULL) {
                runner = runner -> next;
            }
        }
        return false;
    }
};
