//
//  _349_两个数组的交集.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/2/18.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/intersection-of-two-arrays/

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto num:nums2) {
            if (set1.erase(num)) {
                res.push_back(num);
            }
        }
        return res;
    }
};

/**
 示例 1:

 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 输出: [2]
 示例 2:

 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 输出: [9,4]
*/
/**
int main(int argc, const char * argv[]) {
    
//    vector<int> nums1 = {1, 2, 2, 1};
//    vector<int> nums2 = {2, 2};
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    
    Solution solution = Solution();
    vector<int> res = solution.intersection(nums1, nums2);
    
    for (auto num:res) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
*/
