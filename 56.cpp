//
//  56.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/1.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Merge Intervals
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
private:
    static void quickSortInterval(vector<Interval>& intervals, int front, int tail) {
        int start = front, end = tail;
        if (front >= tail - 1) {
            return;
        }
        Interval temp = intervals[front];
        while (front < tail) {
            while (front < --tail && intervals[tail].start > temp.start) ;
            intervals[front] = intervals[tail];
            while (front < tail && intervals[front].start <= temp.start) {
                front++;
            }
            intervals[tail] = intervals[front];
        }
        intervals[front] = temp;
        quickSortInterval(intervals, start, front);
        quickSortInterval(intervals, front + 1, end);
    }
    
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return intervals;
        }
        quickSortInterval(intervals, 0, (int) intervals.size());
        int loc = 0, current = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start <= intervals[current].end) {
                intervals[current].end = max(intervals[i].end, intervals[current].end);
            }
            else {
                intervals[loc++] = intervals[current];
                current = i;
            }
        }
        intervals[loc++] = intervals[current];
        intervals.erase(intervals.begin() + loc, intervals.end());
        return intervals;
    }
};