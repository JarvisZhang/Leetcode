//
//  61.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/20.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) {
            return head;
        }
        int length = 0;
        ListNode *current = head;
        while (length < k) {
            current = current -> next;
            length++;
            if (current == NULL) {
                k %= length;
                current = head;
                length = 0;
            }
        }
        ListNode *front = head;
        while (current -> next != NULL) {
            front = front -> next;
            current = current -> next;
        }
        current -> next = head;
        head = front -> next;
        front -> next = NULL;
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
    static void runTest(int input[], int length, int k) {
        ListNode *head = arrayToList(input, length);
        printListNode(head);
        Solution solution;
        ListNode *result = solution.rotateRight(head, k);
        printListNode(result);
    }
    
public:
    void sample() {
        int input1[] = {1, 2, 3, 4, 5}, length1 = 5, k1 = 2;
        int input2[] = {1}, length2 = 1, k2 = 1;
        int input3[] = {1, 2}, length3 = 2, k3 = 1;
        int input4[] = {1, 2, 3, 4, 5}, length4 = 5, k4 = 5;
        runTest(input1, length1, k1);
        runTest(input2, length2, k2);
        runTest(input3, length3, k3);
        runTest(input4, length4, k4);
    }
};