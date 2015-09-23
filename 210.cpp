//
//  210.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/9/4.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Course Schedule II
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adjustGraph(numCourses, vector<int>());
        queue<int> current;
        vector<int> result;
        int inDegree[numCourses];
        memset(inDegree, 0, sizeof(int) * numCourses);
        for (auto &link: prerequisites) {
            adjustGraph[link.second].push_back(link.first);
            inDegree[link.first]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (!inDegree[i]) {
                current.push(i);
                result.push_back(i);
            }
        }
        while (!current.empty()) {
            int course = current.front();
            current.pop();
            for (auto &nextCourse: adjustGraph[course]) {
                if (!(--inDegree[nextCourse])) {
                    current.push(nextCourse);
                    result.push_back(nextCourse);
                }
            }
        }
        return result.size() == numCourses ? result : vector<int>();
    }
};