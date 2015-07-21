//
//  23.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/21.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Merge k Sorted Lists
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }
        for (int step = 1; step < lists.size(); step *= 2) {
            for (int current = 0; current + step < lists.size(); current += 2 * step) {
                ListNode *lista = lists[current], *listb = lists[current + step];
                ListNode *temp = new ListNode(0), *head = temp;
                while (lista != NULL && listb != NULL) {
                    if (lista -> val < listb -> val) {
                        temp -> next = lista;
                        lista = lista -> next;
                    }
                    else {
                        temp -> next = listb;
                        listb = listb -> next;
                    }
                    temp = temp -> next;
                }
                if (lista != NULL) {
                    temp -> next = lista;
                }
                else {
                    temp -> next = listb;
                }
                lists[current] = head -> next;
                delete head;
            }
        }
        return lists[0];
    }
};