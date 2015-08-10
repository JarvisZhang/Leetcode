//
//  130.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/8.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() <= 2 || board[0].size() <= 2) {
            return;
        }
        bfsBound(board);
        modifyBoard(board, 'O', 'X');
        modifyBoard(board, '#', 'O');
    }
    
    void modifyBoard(vector<vector<char>> &board, char src, char dst) {
        for (auto &row: board) {
            for (auto &ch: row) {
                if (ch == src) {
                    ch = dst;
                }
            }
        }
    }
    
    void bfsBound(vector<vector<char>> &board) {
        for (int i = 0; i < board[0].size(); i++) {
            markPound(board, 0, i);
            markPound(board, (int) board.size() - 1, i);
        }
        for (int i = 1; i < board.size() - 1; i++) {
            markPound(board, i, 0);
            markPound(board, i, (int) board[0].size() - 1);
        }
    }
    
    void markPound(vector<vector<char>> &board, int row, int col) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != 'O') {
            return;
        }
        board[row][col] = '#';
        if (row > 1) {
            markPound(board, row - 1, col);
        }
        if (row < board.size() - 2) {
            markPound(board, row + 1, col);
        }
        if (col > 1) {
            markPound(board, row, col - 1);
        }
        if (col < board[0].size() - 2) {
            markPound(board, row, col + 1);
        }
    }
};