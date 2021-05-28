#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/flatten-nested-list-iterator/
/**
  * We recursively store all the integers at initialization.
  * Once done, the next and hasNext function can be implemented using this array.
 */
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> arr;
    int index = 0;
    
    void combineSolver(vector<NestedInteger> &nestedList) {
        for (int i = 0; i < nestedList.size(); i++) {
            if (nestedList[i].isInteger())
                arr.push_back(nestedList[i].getInteger());
            else
                combineSolver(nestedList[i].getList());
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        arr = vector<int>();
        index = 0;
        
        combineSolver(nestedList);
    }
    
    int next() {
        return arr[index++];
    }
    
    bool hasNext() {
        return index < arr.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */