//
//  37.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/28.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Sudoku Solver
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col) {
        for (int j = 0; j < 9; j++) {
            if (j != col && board[row][j] == board[row][col]) {
                return false;
            }
        }
        for (int i = 0; i < 9; i++) {
            if (i != row && board[i][col] == board[row][col]) {
                return false;
            }
        }
        for(int top = row / 3 * 3, left = col / 3 * 3, k = 0; k < 9; k++) {
            int i = top + k / 3, j = left + k % 3;
            if ((i != row || j != col) && board[i][j] == board[row][col]) {
                return false;
            }
        }
        return true;
    }
    
    bool solveSodokuRecur(vector<vector<char>>& board, int row, int col) {
        if (col >= 9) {
            return solveSodokuRecur(board, row + 1, 0);
        }
        if (row == 9) {
            return true;
        }
        if (board[row][col] != '.') {
            return solveSodokuRecur(board, row, col + 1);
        }
        else {
            for (int k = 0; k < 9; k++) {
                board[row][col] = '1' + k;
                if (isValid(board, row, col) && solveSodokuRecur(board, row, col + 1)) {
                    return true;
                }
            }
            board[row][col] = '.';
        }
        return false;
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        solveSodokuRecur(board, 0, 0);
    }
};