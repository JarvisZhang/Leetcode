//
//  126.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/16.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Word Ladder II
//

#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, vector<string>> frontPath, tailPath;
        unordered_set<string> front, tail;
        front.insert(start);
        tail.insert(end);
        dict.erase(start);
        dict.erase(end);
        findLaddersRecur(front, tail, frontPath, tailPath, dict, false);
        return result;
    }
    
    void findLaddersRecur(unordered_set<string> &front, unordered_set<string> &tail, unordered_map<string, vector<string>> &frontPath, unordered_map<string, vector<string>> &tailPath, unordered_set<string> &dict, bool reversed) {
        if (front.empty() || tail.empty()) {
            return;
        }
        if (front.size() > tail.size()) {
            findLaddersRecur(tail, front, tailPath, frontPath, dict, !reversed);
            return;
        }
        unordered_set<string> temp;
        bool finished = false;
        for (string frontWord: front) {
            for (int i = 0; i < frontWord.size(); i++) {
                string preFront = frontWord;
                for (char j = 'a'; j <= 'z'; j++) {
                    if (preFront[i] == j) {
                        continue;
                    }
                    frontWord[i] = j;
                    if (tail.find(frontWord) != tail.end()) {
                        finished = true;
                        if (reversed) {
                            generateResult(tailPath, frontPath, frontWord, preFront);
                        }
                        else {
                            generateResult(frontPath, tailPath, preFront, frontWord);
                        }
                    }
                    if (dict.find(frontWord) != dict.end()) {
                        temp.insert(frontWord);
                        if (frontPath.find(frontWord) == frontPath.end()) {
                            frontPath[frontWord] = vector<string>({preFront});
                        }
                        else {
                            frontPath[frontWord].push_back(preFront);
                        }
                    }
                }
                frontWord = preFront;
            }
        }
        for (string str: temp) {
            dict.erase(str);
        }
        front = temp;
        if (!finished) {
            findLaddersRecur(front, tail, frontPath, tailPath, dict, reversed);
        }
    }
    
    void getFrontPath (vector<vector<string>> &frontResult, vector<string> path, unordered_map<string, vector<string>> &frontPath, string &frontWord) {
        auto pre = frontPath.find(frontWord);
        path.push_back(frontWord);
        if (pre != frontPath.end()) {
            for (string preWord: (*pre).second) {
                getFrontPath(frontResult, path, frontPath, preWord);
            }
        }
        else {
            reverse(path.begin(), path.end());
            frontResult.push_back(path);
        }
    }
    
    void getTailPath (vector<vector<string>> &tailResult, vector<string> path, unordered_map<string, vector<string>> &tailPath, string &tailWord) {
        auto post = tailPath.find(tailWord);
        path.push_back(tailWord);
        if (post != tailPath.end()) {
            for (string postWord: (*post).second) {
                getTailPath(tailResult, path, tailPath, postWord);
            }
        }
        else {
            tailResult.push_back(path);
        }
    }
    
    void generateResult(unordered_map<string, vector<string>> &frontPath, unordered_map<string, vector<string>> &tailPath, string &frontWord, string &tailWord) {
        vector<vector<string>> frontResult, tailResult;
        vector<string> path;
        getFrontPath(frontResult, path, frontPath, frontWord);
        getTailPath(tailResult, path, tailPath, tailWord);
        for (vector<string> frontPath: frontResult) {
            for (vector<string> tailPath: tailResult) {
                vector<string> path(frontPath.begin(), frontPath.end());
                path.insert(path.end(), tailPath.begin(), tailPath.end());
                result.push_back(path);
            }
        }
    }
};

class Test {
public:
    void sample() {
        string b("sand"), e("acne");
        unordered_set<string> wordDict({"sand","sans","sins","sims","aims","arms","arts","ants","ante","anne","acne","aids","ands"});
        Solution solution;
        vector<vector<string>> result = solution.findLadders(b, e, wordDict);
        for (auto path: result) {
            for (string str: path) {
                cout << str << " ";
            }
            cout << endl;
        }
    }
};