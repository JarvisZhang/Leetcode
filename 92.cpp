//
//  92.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/19.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *top = new ListNode(0), *start = top;
        top -> next = head;
        for (int i = 1; i < m; i++) {
            start = start -> next;
        }
        ListNode *pre = start -> next;
        if (pre == NULL) {
            return head;
        }
        ListNode *current = pre -> next;
        int count = n - m;
        while (count) {
            ListNode *post = current -> next;
            current -> next = pre;
            pre = current;
            current = post;
            count--;
        }
        start -> next -> next = current;
        start -> next = pre;
        head = top -> next;
        delete top;
        return head;
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
    static void runTest(int input[], int length, int m, int n) {
        ListNode *head = arrayToList(input, length);
        printListNode(head);
        Solution solution;
        ListNode *result = solution.reverseBetween(head, m, n);
        printListNode(result);
    }
    
public:
    void sample() {
        int input1[] = {1, 2, 3, 4, 5}, length1 = 5, m1 = 2, n1 = 4;
        int input2[] = {1, 2, 3, 4, 5}, length2 = 5, m2 = 1, n2 = 2;
        int input3[] = {1, 2, 3, 4, 5}, length3 = 5, m3 = 4, n3 = 5;
        int input4[] = {1}, length4= 1, m4 = 1, n4 = 1;
        int input5[] = {1, 2, 3, 4, 5}, length5 = 5, m5 = 1, n5 = 5;
        runTest(input1, length1, m1, n1);
        runTest(input2, length2, m2, n2);
        runTest(input3, length3, m3, n3);
        runTest(input4, length4, m4, n4);
        runTest(input5, length5, m5, n5);
    }
};