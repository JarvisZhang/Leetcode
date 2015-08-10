//
//  79.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/7.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Word Search
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) {
            return false;
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (existRecur(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool existRecur(vector<vector<char>>& board, string &word, int row, int col, int pos) {
        if (pos == word.size()) {
            return true;
        }
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[pos]) {
            return false;
        }
        char temp = board[row][col];
        board[row][col] = 0;
        bool isExist = existRecur(board, word, row - 1, col, pos + 1) ||
                       existRecur(board, word, row, col + 1, pos + 1) ||
                       existRecur(board, word, row + 1, col, pos + 1) ||
                       existRecur(board, word, row, col - 1, pos + 1);
        board[row][col] = temp;
        return isExist;
    }
};