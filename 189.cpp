/*
 * 189.cpp
 *
 *  Created on: Mar 2, 2015
 *      Author: zhangzuowei
 */

#include<iostream>

using namespace std;

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        int step = n - k % n;
        if(step == n)
        	return;
        for(int i = 0; i < gcd(n, step); i++) {
        	int loc = i, shift_loc = i + step, temp = nums[loc];
        	do {
        		nums[loc] = nums[shift_loc];
        		loc = shift_loc;
        		shift_loc = (shift_loc + step) % n;
        	} while(shift_loc != i);
        	nums[loc] = temp;
        }
        return;
    }
private:
    static int gcd(int a, int b) {
    	int big = (a > b) ? a : b;
    	int small = (a < b) ? a : b;
    	if(!small)	return big;
    	int r = big % small;
    	while(r) {
    		big = small;
    		small = r;
    		r = big % small;
    	}
    	return small;
    }
};

class Test {
public:
	void sample() {
		int input1[] = {1,2,3,4,5,6,7}, n1 = 7, k1 = 3;
		int input2[] = {1,2,3,4,5,6}, n2 = 6, k2 = 0;
		int input3[] = {1,2,3}, n3 = 3, k3 = 3;
		int input4[] = {1}, n4 = 1, k4 = 10;
		int input5[] = {1,2,3,4,5,6}, n5 = 6, k5 = 2;
		runTest(input1, n1, k1);
		runTest(input2, n2, k2);
		runTest(input3, n3, k3);
		runTest(input4, n4, k4);
		runTest(input5, n5, k5);
	}
private:
	void runTest(int input[], int n, int k) {
		Solution *s = new Solution();
		s -> rotate(input, n, k);
		for(int i = 0; i < n; i++)
			cout << input[i] << ",";
		cout << endl;
	}
};
