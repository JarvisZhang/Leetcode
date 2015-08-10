//
//  36.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/28.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Valid Sudoku
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            bool checked[9] = {false};
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (checked[board[i][j]-'1']) {
                        return false;
                    }
                    checked[board[i][j]-'1'] = true;
                }
            }
        }
        for (int j = 0; j < 9; j++) {
            bool checked[9] = {false};
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    if (checked[board[i][j]-'1']) {
                        return false;
                    }
                    checked[board[i][j]-'1'] = true;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                bool checked[9] = {false};
                for (int k = 0; k < 9; k++) {
                    int row = i * 3 + k / 3, col = j * 3 + k % 3;
                    if (board[row][col] != '.') {
                        if (checked[board[row][col]-'1']) {
                            return false;
                        }
                        checked[board[row][col]-'1'] = true;
                    }
                }
            }
        }
        return true;
    }
};