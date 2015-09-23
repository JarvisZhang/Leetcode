//
//  146.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/9/1.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: LRU Cache
//

#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache{
public:
    struct CacheUnit {
        int key;
        int val;
        CacheUnit(int k, int v): key(k), val(v) {}
    };
    
    LRUCache(int capacity): size(capacity), currentSize(0) {
        
    }
    
    int get(int key) {
        auto cacheHashIt = cacheHash.find(key);
        if (cacheHashIt == cacheHash.end()) {
            return -1;
        }
        cache.splice(cache.begin(), cache, cacheHashIt -> second);
        return cache.front() -> val;
    }
    
    void set(int key, int value) {
        auto cacheHashIt = cacheHash.find(key);
        if (cacheHashIt == cacheHash.end()) {
            if (currentSize >= size) {
                cacheHash.erase(cache.back() -> key);
                delete cache.back();
                cache.pop_back();
            }
            else {
                currentSize++;
            }
            cache.push_front(new CacheUnit(key, value));
            cacheHash[key] = cache.begin();
        }
        else {
            (*(cacheHashIt -> second)) -> val = value;
            cache.splice(cache.begin(), cache, cacheHashIt -> second);
        }
    }
    
private:
    unordered_map<int, list<CacheUnit*>::iterator> cacheHash;
    list<CacheUnit*> cache;
    int size, currentSize;
};

class Test {
public:
    void sample() {
        //1,[set(2,1),get(2),set(3,2),get(2),get(3)]
        LRUCache lruCache(1);
        lruCache.set(2,1);
        cout << lruCache.get(2) << endl;
        lruCache.set(3,2);
        cout << lruCache.get(2) << endl;
        cout << lruCache.get(3) << endl;
    }
};