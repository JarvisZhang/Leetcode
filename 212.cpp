//
//  212.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/7.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Word Search II
//

#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
public:
    string word;
    TrieNode *children[26];
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class TrieTree {
public:
    TrieNode *root;
    
    TrieTree(const vector<string> &words) {
        root = new TrieNode();
        for (string word: words) {
            insert(word);
        }
    }
    
    void insert(const string &word) {
        TrieNode *current = root;
        for (char ch: word) {
            if (current -> children[ch-'a'] == NULL) {
                TrieNode *temp = new TrieNode();
                current -> children[ch-'a'] = temp;
            }
            current = current -> children[ch-'a'];
        }
        current -> word = word;
    }
};

class Solution {
public:
//    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> findWords(vector<string>& board, vector<string>& words) {
        vector<string> results;
        if (board.empty() || board[0].empty() || words.empty()) {
            return results;
        }
        TrieTree dictionay(words);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                findWordsRecur(results, board, dictionay.root, i, j);
            }
        }
        return results;
    }
//    void findWordsRecur(vector<string> &results, vector<vector<char>>& board, TrieNode *current, int row, int col) {
    void findWordsRecur(vector<string> &results, vector<string>& board, TrieNode *current, int row, int col) {
        if (!(current -> word.empty())) {
            results.push_back(current -> word);
            current -> word.clear();
        }
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] == 0 || current -> children[board[row][col]-'a'] == NULL) {
            return;
        }
        char temp = board[row][col];
        board[row][col] = 0;
        findWordsRecur(results, board, current -> children[temp - 'a'], row - 1, col);
        findWordsRecur(results, board, current -> children[temp - 'a'], row, col + 1);
        findWordsRecur(results, board, current -> children[temp - 'a'], row + 1, col);
        findWordsRecur(results, board, current -> children[temp - 'a'], row, col - 1);
        board[row][col] = temp;
    }
};

class Test {
public:
    void sample() {
        vector<string> board({"aa"});
        vector<string> words({"aa"});
        Solution solution;
        vector<string> results = solution.findWords(board, words);
        for (string result: results) {
            cout << result << endl;
        }
    }
};