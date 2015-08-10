//
//  206.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/18.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head -> next == NULL) {
            return head;
        }
        ListNode *pre = head, *current = head -> next;
        while (current != NULL) {
            ListNode *post = current -> next;
            current -> next = pre;
            pre = current;
            current = post;
        }
        head -> next = NULL;
        return pre;
    }
};

class Test {
private:
    static ListNode *arrayToList(int input[], int length) {
        if(length < 1)
            return NULL;
        ListNode *head = new ListNode(input[0]), *tail = head;
        for(int i = 1; i < length; i++) {
            ListNode *current = new ListNode(input[i]);
            tail -> next = current;
            tail = tail -> next;
        }
        return head;
    }
    
    static void printListNode(ListNode *head) {
        while(head != NULL) {
            cout << head -> val << "->";
            head = head -> next;
        }
        cout << "NULL" <<endl;
    }
    static void runTest(int input[], int length) {
        ListNode *head = arrayToList(input, length);
        printListNode(head);
        Solution solution;
        ListNode *result = solution.reverseList(head);
        printListNode(result);
    }
    
public:
    void sample() {
        int input1[] = {1, 2}, length1 = 2;
        runTest(input1, length1);
    }
};