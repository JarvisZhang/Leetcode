/*
 * 7.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: zhangzuowei
 */
#include<iostream>
#include<climits>
#include <math.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
    	int result = 0;
    	while(x){
    		if(INT_MAX/10 < result || INT_MIN/10 > result)
    			return 0;
    		result *= 10;
    		result += x % 10;
    		x /= 10;
    	}
    	return result;
    }
};

class Test {
public:
	void sample(){
		int x1 = -123;
		int x2 = 1534236469;
		int x3 = -2147483412;
		runTest(x1);
		runTest(x2);
		runTest(x3);
	}
private:
	static void runTest(int x){
		Solution* s = new Solution();
		int result = s -> reverse(x);
		cout << result << endl;
	}
};
