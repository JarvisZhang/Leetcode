/*
 * 2.cpp
 *
 *  Created on: Feb 1, 2015
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    	int carry = 0, sum = 0;
    	ListNode *current = new ListNode(-1), *result = current;
    	while(l1 && l2) {
    		sum = l1 -> val + l2 -> val + carry;
    		current -> next = new ListNode(sum % 10);
    		carry = (sum > 9) ? 1 : 0;
    		l1 = l1 -> next;
    		l2 = l2 -> next;
    		current = current -> next;
    	}
    	ListNode *longer = (l1 == NULL) ? l2 : l1;
		while(longer) {
			sum = longer -> val + carry;
			current -> next = new ListNode(sum % 10);
			carry = (sum > 9) ? 1 : 0;
			longer = longer -> next;
			current = current -> next;
		}
		if(carry != 0) {
			current -> next = new ListNode(carry);
		}
    	return result -> next;
    }
};

class Test {
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

public:
	void sample() {
		int a1[] = {2, 4, 3}, b1[] = {5, 6, 4};
		int a2[] = {0, 0, 4}, b2[] = {0, 0, 6};
		int a3[] = {0}, b3[] = {5, 6};
		int a4[] = {6, 6}, b4[] = {1};
		int a5[] = {9, 9, 9}, b5[] = {1};
		runTest(arrayToList(a1, 3), arrayToList(b1, 3));
		runTest(arrayToList(a2, 3), arrayToList(b2, 3));
		runTest(arrayToList(a3, 1), arrayToList(b3, 2));
		runTest(arrayToList(a4, 2), arrayToList(b4, 1));
		runTest(arrayToList(a5, 3), arrayToList(b5, 1));
	}

	static void runTest(ListNode *a, ListNode *b) {
		Solution s = Solution();
		ListNode *result = s.addTwoNumbers(a, b);
		printListNode(result);
	}
};
