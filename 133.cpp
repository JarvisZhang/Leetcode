//
//  133.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/15.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Clone Graph
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> cloned;
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) {
            return NULL;
        }
        auto visited = cloned.find(node);
        if (visited != cloned.end()) {
            return visited -> second;
        }
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node -> label);
        cloned[node] = newNode;
        for (auto neighbor: node -> neighbors) {
            newNode -> neighbors.push_back(cloneGraph(neighbor));
        }
        return newNode;
    }
};