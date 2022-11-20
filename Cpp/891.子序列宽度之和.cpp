/*
 * @lc app=leetcode.cn id=891 lang=cpp
 *
 * [891] 子序列宽度之和
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        long long mod = 1e9 + 7;
        long long x = nums[0], y = 2;
        for (int j = 1; j < nums.size(); ++j) {
            ans = (ans + nums[j] * (y - 1) - x) % mod;
            x = (x * 2 + nums[j]) % mod;
            y = y * 2 % mod;
        }
        return (int)((ans + mod) % mod);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int res;
    
    /**
     输入：nums = [2,1,3]
     输出：6
     解释：子序列为 [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3] 。
     相应的宽度是 0, 0, 0, 1, 1, 2, 2 。
     宽度之和是 6 。
     */
    nums = {2,1,3};
    res = 6;
    assert(res == Solution().sumSubseqWidths(nums));
    
    /**
     输入：nums = [2]
     输出：0
     */
    nums = {2};
    res = 0;
    assert(res == Solution().sumSubseqWidths(nums));

    cout << "OK~" << endl;
    
    return 0;
}
