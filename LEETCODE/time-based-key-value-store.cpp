#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/time-based-key-value-store/
/**
 * use a map of map to store key with its corresponding timestamp and value
*/
class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, map<int, string>> hashMap;
    TimeMap() {
        hashMap.clear();
    }
    
    void set(string key, string value, int timestamp) {
        map<int, string> &temp = hashMap[key];
        temp[-timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (hashMap.find(key) == hashMap.end())
            return "";
        
        auto j = hashMap[key].lower_bound(-timestamp);
        if (j != hashMap[key].end())
            return j->second;
        
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */