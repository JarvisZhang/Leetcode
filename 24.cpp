//
//  24.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/20.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode *first = head, *second = head -> next;
        ListNode *top = new ListNode(0), *pre =top;
        top -> next = head;
        while (first != NULL && second != NULL) {
            first -> next = second -> next;
            second -> next = first;
            pre -> next = second;
            pre = first;
            first = first -> next;
            if (first != NULL) {
                second = first -> next;
            }
        }
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
    static void runTest(int input[], int length) {
        ListNode *head = arrayToList(input, length);
        printListNode(head);
        Solution solution;
        ListNode *result = solution.swapPairs(head);
        printListNode(result);
    }
    
public:
    void sample() {
        int input1[] = {1, 2, 3, 4, 5}, length1 = 5;
        int input2[] = {1, 2, 3, 4, 5, 6}, length2 = 6;
        int input3[] = {1, 2}, length3 = 2;
        int input4[] = {1}, length4= 1;
        runTest(input1, length1);
        runTest(input2, length2);
        runTest(input3, length3);
        runTest(input4, length4);
    }
};