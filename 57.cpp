//
//  57.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/1.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        auto insertLoc = intervals.begin(), it = intervals.begin();
        int eraseLength = 0;
        while (it != intervals.end() && newInterval.end >= it -> start) {
            if (newInterval.start <= it -> end) {
                newInterval.start = min(newInterval.start, it -> start);
                newInterval.end = max(newInterval.end, it -> end);
                if (!eraseLength) {
                    insertLoc = it;
                }
                eraseLength++;
            }
            it++;
        }
        if (!eraseLength) {
            insertLoc = it;
        }
        auto eraseLoc = intervals.insert(insertLoc, newInterval) + 1;
        intervals.erase(eraseLoc, eraseLoc + eraseLength);
        return intervals;
    }
    
    vector<Interval> insert_bs(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.empty()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        int start = 0, end = (int) intervals.size();
        while (start < end) {
            int middle = start + (end - start) / 2;
            if (intervals[middle].end < newInterval.start) {
                start = middle + 1;
            }
            else {
                end = middle;
            }
        }
        int left = start;
        if (left < intervals.size() && intervals[left].end < newInterval.start) {
            left++;
        }
        end = (int) intervals.size();
        while (start < end) {
            int middle = start + (end - start) / 2;
            if (intervals[middle].start <= newInterval.end) {
                start = middle + 1;
            }
            else {
                end = middle;
            }
        }
        int right = start;
        if (right < intervals.size() && intervals[right].start > newInterval.end) {
            right--;
        }
        if (left > right || right == -1 || left == intervals.size()) {
            intervals.resize(intervals.size() + 1);
            for (int i = (int) intervals.size() - 1; i > left; i--) {
                intervals[i] = intervals[i-1];
            }
            intervals[left] = newInterval;
        }
        else {
            if (left >= 0) {
                newInterval.start = min(intervals[left].start, newInterval.start);
            }
            if (right <= intervals.size()) {
                newInterval.end = max(intervals[min(right, (int) intervals.size()-1)].end, newInterval.end);
            }
            int newSize = (int) intervals.size() - (right - left);
            if (right == intervals.size()) {
                newSize++;
            }
            for (int i = right + 1, loc = left + 1; loc < newSize; loc++, i++) {
                intervals[loc] = intervals[i];
            }
            intervals[left] = newInterval;
            intervals.erase(intervals.begin() + newSize, intervals.end());
        }
        return intervals;
    }
};

class Test {
private:
    static void runTest(int intervals[][2], int length, int newInterval[]) {
        vector<Interval> intervalsVec(length);
        for (int i = 0; i < length; i++) {
            intervalsVec[i] = Interval(intervals[i][0], intervals[i][1]);
        }
        Interval nInterval(newInterval[0], newInterval[1]);
        Solution solution;
        vector<Interval> result = solution.insert(intervalsVec, nInterval);
        for (auto interval : result) {
            cout << "["  << interval.start << ", " << interval.end << "]" << ", ";
        }
        cout << endl;
    }
    
public:
    void sample() {
        int interval1[][2] = {{1,3},{6,9}}, length1 = 2, newInterval1[] = {2,5};
        int interval2[][2] = {{1,2},{3,5},{6,7},{8,10},{12,16}}, length2 = 5, newInterval2[] = {4, 9};
        int interval3[][2] = {{1,2},{3,9}}, length3 = 2, newInterval3[] = {12,15};
        int interval4[][2] = {{1,2},{3,9},{12,15}}, length4 = 3, newInterval4[] = {-2,-1};
        int interval5[][2] = {{1,3},{4,9},{12,15}}, length5 = 3, newInterval5[] = {-2,2};
        int interval6[][2] = {{1,3},{4,9},{12,15}}, length6 = 3, newInterval6[] = {10,11};
        int interval7[][2] = {{1,3},{4,9},{12,15}}, length7 = 3, newInterval7[] = {13,16};
        int interval8[][2] = {{1,3},{4,9},{12,15}}, length8 = 3, newInterval8[] = {-1,16};
        int interval9[][2] = {{}}, length9 = 0, newInterval9[] = {0,1};
        int interval10[][2] = {{-4,-3},{-2,-1},{1,5}}, length10 = 3, newInterval10[] = {2,3};
        int interval11[][2] = {{2,4},{5,7},{8,10},{11,13}}, length11 = 4, newInterval11[] = {3,6};
        runTest(interval1, length1, newInterval1);
        runTest(interval2, length2, newInterval2);
        runTest(interval3, length3, newInterval3);
        runTest(interval4, length4, newInterval4);
        runTest(interval5, length5, newInterval5);
        runTest(interval6, length6, newInterval6);
        runTest(interval7, length7, newInterval7);
        runTest(interval8, length8, newInterval8);
        runTest(interval9, length9, newInterval9);
        runTest(interval10, length10, newInterval10);
        runTest(interval11, length11, newInterval11);
    }
};