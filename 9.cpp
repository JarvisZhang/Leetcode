/*
 * 9.cpp
 *
 *  Created on: Feb 26, 2015
 *      Author: zhangzuowei
 */

#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
    	if(x < 0)
    		return false;
    	int top = 1;
    	while(x/top >= 10) {
    		top *= 10;
    	}
    	while(x) {
    		if(x / top != x % 10)
    			return false;
    		x = x % top / 10;
    		top /= 100;
    	}
    	return true;
    }
};

class Test {
public:
	void sample(){
		int x1 = -123;
		int x2 = 123321;
		int x3 = 1000021;
		runTest(x1);
		runTest(x2);
		runTest(x3);
	}
private:
	static void runTest(int x){
		Solution* s = new Solution();
		int result = s -> isPalindrome(x);
		cout << result << endl;
	}
};
