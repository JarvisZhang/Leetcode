//
//  207.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/9/4.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Course Schedule
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (prerequisites.empty()) {
            return true;
        }
        vector<vector<bool>> courseGraph(numCourses, vector<bool>(numCourses, false));
        vector<int> visited(numCourses, 0);
//        bool courseGraph[numCourses][numCourses];
//        bool visited[numCourses];
//        memset(courseGraph, false, sizeof(bool) * numCourses * numCourses);
//        memset(visited, 0, sizeof(bool) * numCourses);
        for (auto &link: prerequisites) {
            courseGraph[link.second][link.first] = true;
        }
        for (int i = 0; i < numCourses; i++) {
            if (!canFinishDFS(courseGraph, numCourses, visited, i)) {
                return false;
            }
        }
        return true;
    }
    
    bool canFinishDFS(vector<vector<bool>> &courseGraph, int &numCourses, vector<int> &visited, int current) {
        if (visited[current] == 1) {
            return false;
        }
        else if (visited[current] == -1) {
            return true;
        }
        visited[current] = 1;
        for (int i = 0; i < numCourses; i++) {
            if (courseGraph[current][i] && !canFinishDFS(courseGraph, numCourses, visited, i)) {
                return false;
            }
        }
        visited[current] = -1;
        return true;
    }
    
    bool canFinishBFS(int numCourses, vector<pair<int, int>>& prerequisites) {
//        vector<vector<bool>> courseGraph(numCourses, vector<bool>(numCourses, false));
//        vector<int> inDegrees(numCourses, 0);
        bool courseGraph[numCourses][numCourses];
        int inDegrees[numCourses];
        memset(courseGraph, false, sizeof(bool) * numCourses * numCourses);
        memset(inDegrees, 0, sizeof(int) * numCourses);
        queue<int> current;
        for (auto &link: prerequisites) {
            if (!courseGraph[link.second][link.first]) {
                courseGraph[link.second][link.first] = true;
                inDegrees[link.first]++;
            }
        }
        for (int i = 0; i < numCourses; i++) {
            if (!inDegrees[i]) {
                current.push(i);
            }
        }
        while (!current.empty()) {
            int course = current.front();
            current.pop();
            for (int i = 0; i < numCourses; i++) {
                if (courseGraph[course][i]) {
                    if (!(--inDegrees[i])) {
                        current.push(i);
                    }
                }
            }
        }
        for (int i = 0; i < numCourses; i++) {
            if (inDegrees[i]) {
                return false;
            }
        }
        return true;
    }
};

class Test {
public:
    void sample() {
        int numCourses = 2;
        vector<pair<int, int>> prerequisites;
        Solution solution;
        cout << solution.canFinish(numCourses, prerequisites) << endl;
    }
};