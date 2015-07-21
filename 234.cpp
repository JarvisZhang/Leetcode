//
//  234.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/14.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        ListNode *walker = head, *runner = head;
        while (runner != NULL) {
            walker = walker -> next;
            runner = runner -> next;
            if (runner != NULL) {
                runner = runner -> next;
            }
        }
        ListNode *tail = reverseList(walker);
        while (tail != NULL) {
            if (head -> val != tail -> val) {
                return false;
            }
            head = head -> next;
            tail = tail -> next;
        }
        return true;
    }
    
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head -> next == NULL) {
            return head;
        }
        ListNode *pre = head, *current = head -> next, *post;
        while (current != NULL) {
            post = current -> next;
            current -> next = pre;
            pre = current;
            current = post;
        }
        head -> next = NULL;
        return pre;
    }
};