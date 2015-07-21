//
//  148.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/1.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Sort List
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    static ListNode *mergeTwoSortLists(ListNode *head1, ListNode *head2) {
        ListNode *top = new ListNode(0), *result = top;
        while (head1 != NULL && head2 != NULL) {
            if (head1 -> val <= head2 -> val) {
                result -> next = head1;
                head1 = head1 -> next;
            }
            else {
                result -> next = head2;
                head2 = head2 -> next;
            }
            result = result -> next;
        }
        if (head1 != NULL) {
            result -> next = head1;
        }
        if (head2 != NULL) {
            result -> next = head2;
        }
        result = top -> next;
        delete top;
        return result;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        ListNode *walker = head, *runner = head;
        if (head == NULL || head -> next == NULL) {
            return head;
        }
        while (runner -> next != NULL && runner -> next -> next != NULL) {
            walker = walker -> next;
            runner = runner -> next -> next;
        }
        ListNode *head1 = head, *head2 = walker -> next;
        walker -> next = NULL;
        head1 = this -> sortList(head1);
        head2 = this -> sortList(head2);
        return mergeTwoSortLists(head1, head2);
    }
};