/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> rnums;
        map<int, int> maps;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (maps.find(num) != maps.end()) {
                rnums.push_back(maps[num]);
                rnums.push_back(i);
                break;
            }
            maps[target - num] = i;
        }
        return rnums;
    }
};
// @lc code=end