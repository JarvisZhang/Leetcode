//
//  83.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/25.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode *front = head;
        while (front != NULL) {
            ListNode *rear = front -> next;
            while (rear != NULL && front -> val == rear -> val) {
                rear = rear -> next;
            }
            ListNode *current = front -> next;
            while (current != rear) {
                ListNode *temp = current -> next;
                delete current;
                current = temp;
            }
            front -> next = rear;
            front = rear;
        }
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
    static void runTest(int input[], int length) {
        ListNode *head = arrayToList(input, length);
        printListNode(head);
        Solution solution;
        solution.deleteDuplicates(head);
        printListNode(head);
    }
    
public:
    void sample() {
        int input1[] = {1, 2, 3}, length1 = 3;
        runTest(input1, length1);
    }
};
