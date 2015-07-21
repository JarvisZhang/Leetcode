/*
 * 19.cpp
 *
 *  Created on: Feb 28, 2015
 *      Author: zhangzuowei
 */

#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		if(n < 1 || head == NULL)
			return NULL;
		ListNode *start = new ListNode(0), *pre = start;
		pre -> next = head;
		while(n--)
			head = head -> next;
		while(head) {
			head = head -> next;
			pre = pre -> next;
		}
		ListNode *target = pre -> next;
		pre -> next = target -> next;
		delete target;
		return start -> next;
	}

    ListNode *removeNthFromEndWithoutHead(ListNode *head, int n) {
    	if(n < 1 || head == NULL)
    		return NULL;
    	ListNode *pre = head, *target = head -> next, *tail = target;
    	int i;
    	for(i = 0; i < n && tail != NULL; i++) {
    		tail = tail -> next;
    	}
    	if(i < n - 1)
    		return head;
    	else if(i == n - 1) {
    		head = head -> next;
    		delete pre;
    		return head;
    	}
    	while(tail != NULL) {
    		tail = tail -> next;
    		pre = target;
    		target = target -> next;
    	}
    	if(target -> next == NULL) {
    		delete target;
    		pre -> next = NULL;
    		return head;
    	}
    	pre -> next = target -> next;
    	delete target;
    	return head;
    }
};

class Test {
public:
	void sample() {
		int input1[] = {1, 2, 3}, loc1 = 3, length1 = 3;
		int input2[] = {1}, loc2 = 1, length2 = 1;
		int input3[] = {1, 2}, loc3 = 2, length3 = 2;
		int input4[] = {1, 2, 3}, loc4 = 1, length4 = 3;
		runTest(input1, loc1, length1);
		runTest(input2, loc2, length2);
		runTest(input3, loc3, length3);
		runTest(input4, loc4, length4);
	}
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
	static void runTest(int input[], int loc, int length) {
		ListNode *l = arrayToList(input, length);
		printListNode(l);
		Solution *s = new Solution();
		ListNode *result = s -> removeNthFromEnd(l ,loc);
		printListNode(result);
	}
};
