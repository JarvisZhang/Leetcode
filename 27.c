//
//  27.c
//  
//
//  Created by 张佐玮 on 15/5/28.
//
//  Title: Remove Element
//

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int rear = numsSize - 1, current = numsSize - 1, temp;
    while (current >= 0) {
        while (nums[current] != val && current >= 0) {
            current--;
        }
        if (current >= 0) {
            nums[current--] = nums[rear--];
        }
    }
    return rear + 1;
}