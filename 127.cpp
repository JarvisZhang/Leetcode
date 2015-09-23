//
//  127.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/16.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Word Ladder
//

#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        queue<string> current;
        current.push(beginWord);
        wordDict.erase(beginWord);
        wordDict.insert(endWord);
        int step = 1;
        while (!current.empty()) {
            int currentLen = (int) current.size();
            while (currentLen--) {
                string word = current.front();
                current.pop();
                if (word == endWord) {
                    return step;
                }
                for (int i = 0; i < word.size(); i++) {
                    char temp = word[i];
                    for (char j = 'a'; j <= 'z'; j++) {
                        if (j == temp) {
                            continue;
                        }
                        word[i] = j;
                        if (wordDict.find(word) != wordDict.end()) {
                            wordDict.erase(word);
                            current.push(word);
                        }
                    }
                    word[i] = temp;
                }
            }
            step++;
        }
        return 0;
    }
    
    int ladderLengthBidir(string beginWord, string endWord, unordered_set<string>& wordDict) {
        if (beginWord == endWord) {
            return 1;
        }
        unordered_set<string> begin, end, *head, *tail;
        int step = 2;
        begin.insert(beginWord);
        end.insert(endWord);
        while (!begin.empty() && !end.empty()) {
            if (begin.size() <= end.size()) {
                head = &begin;
                tail = &end;
            }
            else {
                head = &end;
                tail = &begin;
            }
            unordered_set<string> temp;
            for (string current: *head) {
                for (int i = 0; i < current.size(); i++) {
                    char ch = current[i];
                    for (char j = 'a'; j <= 'z'; j++) {
                        if (j == ch) {
                            continue;
                        }
                        current[i] = j;
                        if (tail -> find(current) != tail -> end()) {
                            return step;
                        }
                        if (wordDict.find(current) != wordDict.end()) {
                            wordDict.erase(current);
                            temp.insert(current);
                        }
                    }
                    current[i] = ch;
                }
            }
            step++;
            *head = temp;
        }
        return 0;
    }
};

class Test {
public:
    void sample() {
        string b("hit"), e("cog");
        unordered_set<string> wordDict({"hot","dot","dog","lot","log"});
        Solution solution;
        cout << solution.ladderLengthBidir(b, e, wordDict) << endl;
    }
};