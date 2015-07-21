//
//  143.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/20.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Reorder List
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
    void reorderList(ListNode* head) {
        if (head == NULL || head -> next == NULL) {
            return;
        }
        ListNode *walker = head, *runner = head;
        while (runner != NULL) {
            walker = walker -> next;
            runner = runner -> next;
            if (runner != NULL) {
                runner = runner -> next;
            }
        }
        ListNode *pre = walker, *current = walker -> next;
        while (current != NULL) {
            ListNode *post = current -> next;
            current -> next  = pre;
            pre = current;
            current = post;
        }
        walker -> next = NULL;
        ListNode *first = head, *second = pre, *result = first;
        while (first != pre && second != NULL) {
            first = first -> next;
            result -> next = second;
            result = result -> next;
            if (first != pre && second != NULL) {
                second = second -> next;
                result -> next = first;
                result = result -> next;
            }
        }
        if (result != NULL) {
            result -> next = NULL;
        }
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
        solution.reorderList(head);
        printListNode(head);
    }
    
public:
    void sample() {
        int input1[] = {1, 2, 3}, length1 = 3;
        int input2[] = {1, 2, 3, 4}, length2 = 4;
        
        runTest(input1, length1);
        runTest(input2, length2);
    }
};
