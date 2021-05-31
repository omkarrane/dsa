#include <bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/finding-pairs-with-a-certain-sum/
class FindSumPairs {
public:
    unordered_map<int, int> arr1, arr2;
    vector<int> copyArr2;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        copyArr2 = nums2;
        for (int i : nums1)
            arr1[i]++;
        
        for (int i : nums2)
            arr2[i]++;
    }
    
    void add(int index, int val) {
        int countVal = arr2[copyArr2[index]];
        if (countVal > 1) {
            arr2[copyArr2[index]]--;
            arr2[copyArr2[index] + val]++;
            copyArr2[index] += val;
        }
        else {
            arr2.erase(copyArr2[index]);
            arr2[copyArr2[index] + val]++;
            copyArr2[index] += val;
        }
    }
    
    int count(int tot) {
        int count = 0;
        for (auto i : arr1) {
            if (arr2.find(tot - i.first) != arr2.end()) {
                count += arr2[tot - i.first] * i.second;
            }
        }
        
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */