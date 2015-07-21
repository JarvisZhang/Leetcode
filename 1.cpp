/*
 * 1.cpp
 *
 *  Created on: Jan 27, 2015
 *      Author: zhangzuowei
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		unordered_map<int, int> mp;
		for(int i = 0; i < numbers.size(); i++) {
			mp[numbers[i]] = i;
		}
		vector<int> result;
		unordered_map<int, int>::iterator it = mp.end();
		for(int i = 0; i < numbers.size(); i++) {
			it = mp.find(target - numbers[i]);
			if(it != mp.end() && it->second != i) {
				result.push_back(min(i+1, it->second+1));
				result.push_back(max(i+1, it->second+1));
				break;
			}
		}
		return result;
	}

	vector<int> twoSum_Sort(vector<int> &numbers, int target) {
		vector<int> sorted_numbers(numbers);
		sort(sorted_numbers.begin(), sorted_numbers.end());
		vector<int>::iterator i = sorted_numbers.begin(), j = sorted_numbers.end() - 1;
		while(i != j){
			int current = *i + *j;
			if(current < target)
				i++;
			else if (current > target)
				j--;
			else
				break;
		}
		vector<int> result;
		int index1 = (int) (find(numbers.begin(), numbers.end(), *i) - numbers.begin() + 1);
		int index2 = (int) (numbers.size() - (find(numbers.rbegin(), numbers.rend(), *j) - numbers.rbegin()));
		result.push_back(index1 < index2 ? index1 : index2);
		result.push_back(index2 > index1 ? index2 : index1);
		return result;
	}
};

class Test {
public:
	void sample() {
		int input1[] = {3, 2, 4};
		int input2[] = {0, 1, 0};
		int input3[] = {3, 4, 2};
        int input4[] = {3, 4, 4};
		int target1 = 6;
		int target2 = 0;
		int target3 = 7;
        int target4 = 8;
		runTest(input1, target1);
		runTest(input2, target2);
		runTest(input3, target3);
        runTest(input4, target4);
	}
private:
	static void runTest(int input[], int target) {
		vector<int> v(input, input+3);
		Solution* s = new Solution();
		vector<int> result = s->twoSum(v, target);
		cout << result[0] << " " << result[1] << endl;
	}
};
