/*
 * @lc app=leetcode.cn id=1403 lang=cpp
 *
 * [1403] 非递增顺序的最小子序列
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> ans;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());
        int tmp = 0;
        for (auto i = nums.size() - 1; i >= 0; --i) {
            tmp += nums[i];
            ans.emplace_back(nums[i]);
            if (tmp > sum / 2) {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    vector<int> res;
    
    /**
     输入：nums = [4,3,10,9,8]
     输出：[10,9]
     解释：子序列 [10,9] 和 [10,8] 是最小的、满足元素之和大于其他各元素之和的子序列。但是 [10,9] 的元素之和最大。
     */
    nums = {4,3,10,9,8};
    res = {10,9};
    assert(res == Solution().minSubsequence(nums));
    
    /**
     输入：nums = [4,4,7,6,7]
     输出：[7,7,6]
     解释：子序列 [7,7] 的和为 14 ，不严格大于剩下的其他元素之和（14 = 4 + 4 + 6）。因此，[7,6,7] 是满足题意的最小子序列。注意，元素按非递增顺序返回。
     */
    nums = {4,4,7,6,7};
    res = {7,7,6};
    assert(res == Solution().minSubsequence(nums));
    
    /**
     输入：nums = [6]
     输出：[6]
     */
    nums = {6};
    res = {6};
    assert(res == Solution().minSubsequence(nums));
    
    cout << "OK~" << endl;
    
    return 0;
}
