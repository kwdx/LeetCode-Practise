/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = (int)nums.size();
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return -1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> nums;
    
    /**
     输入: nums = [-1,0,3,5,9,12], target = 9
     输出: 4
     */
    nums = {-1,0,3,5,9,12};
    cout << (4 == Solution().search(nums, 9)) << endl;
    
    /**
     输入: nums = [-1,0,3,5,9,12], target = 2
     输出: -1
     */
    nums = {-1,0,3,5,9,12};
    cout << (-1 == Solution().search(nums, 2)) << endl;
    
    return 0;
}
