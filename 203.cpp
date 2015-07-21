//
//  203.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/17.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *front = new ListNode(0);
        front -> next = head;
        ListNode *pre = front, *current = head;
        while (current != NULL) {
            if (current -> val == val) {
                pre -> next = current -> next;
                delete current;
            }
            else {
                pre = pre -> next;
            }
            current = pre -> next;
        }
        ListNode *result = front -> next;
        delete front;
        return result;
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
    static void runTest(int input[], int val, int length) {
        ListNode *head = arrayToList(input, length);
        printListNode(head);
        Solution solution;
        ListNode *result = solution.removeElements(head, val);
        printListNode(result);
    }
    
public:
    void sample() {
        int input1[] = {1, 1}, val1 = 1, length1 = 2;
        runTest(input1, val1, length1);
    }
};

