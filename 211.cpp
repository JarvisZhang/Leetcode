//
//  211.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/7.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Add and Search Word - Data structure design
//

#include <iostream>

using namespace std;

class TrieNode {
public:
    bool end;
    TrieNode *child[26];
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
        end = false;
    }
};

class WordDictionary {
private:
    TrieNode *root;
    bool searchRecur(string &word, int pos, TrieNode *&current) {
        if (current == NULL) {
            return false;
        }
        else if (pos == word.size()) {
            return current -> end;
        }
        else if (word[pos] != '.') {
            return searchRecur(word, pos + 1, current -> child[word[pos]-'a']);
        }
        else {
            bool found = false;
            for (int i = 0; i < 26 && !found; i++) {
                found = searchRecur(word, pos + 1, current -> child[i]);
            }
            return found;
        }
    }
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *current = root;
        for (char ch: word) {
            if (current -> child[ch-'a'] == NULL) {
                TrieNode *temp = new TrieNode();
                current -> child[ch-'a'] = temp;
            }
            current = current -> child[ch-'a'];
        }
        current -> end = true;
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchRecur(word, 0, root);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");