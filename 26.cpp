/*
 * 26.cpp
 *
 *  Created on: Mar 2, 2015
 *      Author: zhangzuowei
 */

#include<iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	if(n < 2)
    		return n;
    	int loc = 0, i = 0, j = 1;
    	while(j < n) {
    		if(A[i] == A[j]) {
    			j++;
    			continue;
    		}
			A[++loc] = A[j];
			i = j;
    	}
    	return loc + 1;
    }
};

class Test {
public:
	void sample() {
		int a1[] = {1,1,2}, n1 = 3;
		int a2[] = {1,1,1}, n2 = 3;
		int a3[] = {1,1,2,3,3}, n3 = 5;
		int a4[] = {1}, n4 = 1;
		runTest(a1, n1);
		runTest(a2, n2);
		runTest(a3, n3);
		runTest(a4, n4);
	}
private:
	void runTest(int a[], int n) {
		Solution *s = new Solution();
		int length = s -> removeDuplicates(a, n);
		for(int i = 0; i < length; i++)
			cout << a[i] << ",";
		cout << endl;
	}
};
