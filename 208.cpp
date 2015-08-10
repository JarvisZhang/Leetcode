//
//  208.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/7.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Implement Trie (Prefix Tree)
//

#include <iostream>

using namespace std;

class TrieNode {
public:
    bool end;
    TrieNode *child[26];
    
    // Initialize your data structure here.
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
        end = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *current = root;
        for (auto ch: word) {
            if (current -> child[ch-'a'] == NULL) {
                TrieNode *temp = new TrieNode();
                current -> child[ch-'a'] = temp;
            }
            current = current -> child[ch-'a'];
        }
        current -> end = true;
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *current = root;
        for (int i = 0; i < word.size() && current != NULL; i++) {
            current = current -> child[word[i]-'a'];
        }
        return current != NULL && current -> end;
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *current = root;
        for (int i = 0; i < prefix.size() && current != NULL; i++) {
            current = current -> child[prefix[i]-'a'];
        }
        return current != NULL;

    }
    
private:
    TrieNode* root;
};