/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于K的子数组
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int ans = 0;
        if (k <= 1) return 0;
        for (int i = 0, j = 0, cur = 1; i < n; ++i) {
            cur *= nums[i];
            while (cur >= k) cur /= nums[j++];
            ans += i - j + 1;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...

    vector<int> nums;
    int k;
    int res;
    
    /**
     输入：nums = [10,5,2,6], k = 100
     输出：8
     解释：8 个乘积小于 100 的子数组分别为：[10]、[5]、[2],、[6]、[10,5]、[5,2]、[2,6]、[5,2,6]。
     需要注意的是 [10,5,2] 并不是乘积小于 100 的子数组。
     */
    nums = {10,5,2,6};
    k = 100;
    res = 8;
    assert(res == Solution().numSubarrayProductLessThanK(nums, k));
    
    /**
     输入：nums = [1,2,3], k = 0
     输出：0
     */
    nums = {1,2,3};
    k = 0;
    res = 0;
    assert(res == Solution().numSubarrayProductLessThanK(nums, k));
    
    cout << "OK~" << endl;
    
    return 0;
}
