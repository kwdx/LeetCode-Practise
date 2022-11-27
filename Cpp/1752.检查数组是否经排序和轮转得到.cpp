/*
 * @lc app=leetcode.cn id=1752 lang=cpp
 *
 * [1752] 检查数组是否经排序和轮转得到
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool check(vector<int>& nums) {
        int ans = 0;
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] > nums[(i + 1) % n]) {
                ++ans;
            }
        }
        return ans <= 1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    bool res;
    
    /**
     输入：nums = [3,4,5,1,2]
     输出：true
     解释：[1,2,3,4,5] 为有序的源数组。
     可以轮转 x = 3 个位置，使新数组从值为 3 的元素开始：[3,4,5,1,2] 。
     */
    nums = {3,4,5,1,2};
    res = true;
    assert(res == Solution().check(nums));
    
    /**
     输入：nums = [2,1,3,4]
     输出：false
     解释：源数组无法经轮转得到 nums 。
     */
    nums = {2,1,3,4};
    res = false;
    assert(res == Solution().check(nums));
    
    /**
     输入：nums = [1,2,3]
     输出：true
     解释：[1,2,3] 为有序的源数组。
     可以轮转 x = 0 个位置（即不轮转）得到 nums 。
     */
    nums = {1,2,3};
    res = true;
    assert(res == Solution().check(nums));
    
    cout << "OK~" << endl;
    
    return 0;
}
