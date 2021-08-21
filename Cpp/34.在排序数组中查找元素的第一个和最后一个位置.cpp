/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        
        // 先找左边界
        int left = 0, right = (int)nums.size();
        bool isFound = false;
        
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) {
                right = mid;
                isFound = true;
            } else if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (!isFound) {
            // 找不到左边界限
            return {-1, -1};
        }
        res.push_back(left);
        // 找右边界
        right = (int)nums.size();
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        res.push_back(right - 1);
        
        return res;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> nums, res;
    
    /**
     输入：nums = [5,7,7,8,8,10], target = 8
     输出：[3,4]
     */
    nums = {5,7,7,8,8,10};
    res = {3,4};
    cout << (res == Solution().searchRange(nums, 8)) << endl;

    /**
     输入：nums = [5,7,7,8,8,10], target = 6
     输出：[-1,-1]
     */
    nums = {5,7,7,8,8,10};
    res = {-1,-1};
    cout << (res == Solution().searchRange(nums, 6)) << endl;

    /**
     输入：nums = [], target = 0
     输出：[-1,-1]
     */
    nums = {};
    res = {-1,-1};
    cout << (res == Solution().searchRange(nums, 0)) << endl;
    
    /**
     输入：nums = [1], target = 1
     输出：[0,0]
     */
    nums = {1};
    res = {0,0};
    cout << (res == Solution().searchRange(nums, 1)) << endl;

    return 0;
}
