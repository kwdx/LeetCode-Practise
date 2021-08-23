/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        while (right < nums.size()) {
            while (right < nums.size() && nums[right] == 0) {
                right++;
            }
            
            if (right < nums.size())
                nums[left++] = nums[right++];
        }
        while (left < nums.size()) {
            nums[left++] = 0;
        }
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> nums, res;
    
    /**
     输入: [0,1,0,3,12]
     输出: [1,3,12,0,0]
     */
    nums = {0,1,0,3,12};
    res = {1,3,12,0,0};
    Solution().moveZeroes(nums);
    assert(res == nums);
    
    /**
     输入: [0]
     输出: [0]
     */
    nums = {0};
    res = {0};
    Solution().moveZeroes(nums);
    assert(res == nums);

    cout << "OK~" << endl;

    return 0;
}
