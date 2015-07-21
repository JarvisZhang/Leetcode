//
//  174.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/24.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Dungeon Game
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int height = (int) dungeon.size(), width = (int) dungeon[0].size();
        vector<vector<int>> enterBefore(height, vector<int>(width));
        enterBefore[height-1][width-1] = max(1, 1-dungeon[height-1][width-1]);
        for (int i = height - 2; i >=0; i--) {
            enterBefore[i][width-1] = max(1, enterBefore[i+1][width-1]-dungeon[i][width-1]);
        }
        for (int j = width - 2; j >= 0; j--) {
            enterBefore[height-1][j] = max(1, enterBefore[height-1][j+1]-dungeon[height-1][j]);
        }
        for (int i = height - 2; i >= 0; i--) {
            for (int j = width - 2; j >= 0; j--) {
                enterBefore[i][j] = max(1, min(enterBefore[i+1][j], enterBefore[i][j+1]) - dungeon[i][j]);
            }
        }
        return enterBefore[0][0];
    }
};

class Test {
public:
    void sample() {
        vector<vector<int>> dungeon = {{0}};
        Solution solution;
        int result = solution.calculateMinimumHP(dungeon);
        cout << result << endl;
    }
};