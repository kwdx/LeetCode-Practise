/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k > 0) {
            return false;
        }
        int m = sum / k;
        sort(nums.begin(), nums.end());
        if (nums.back() > m) {
            // 最后一个数大于平均数
            return false;
        }
        int n = (int)nums.size();
        vector<bool> dp(1 << n, false);
        vector<int> curSum(1 << n, 0);
        dp[0] = true;
        for (int i = 0; i < (1 << n); ++i) {
            if (!dp[i]) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (curSum[i] + nums[j] > m) {
                    break;
                }
                if (((i >> j) & 1) == 0) {
                    int next = i | (1 << j);
                    if (!dp[next]) {
                        curSum[next] = (curSum[i] + nums[j]) % m;
                        dp[next] = true;
                    }
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int k;
    bool res;
    
    /**
     输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
     输出： True
     说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。
     */
    nums = {4,3,2,3,5,2,1};
    k = 4;
    res = true;
    assert(res == Solution().canPartitionKSubsets(nums, k));
    
    /**
     输入: nums = [1,2,3,4], k = 3
     输出: false
     */
    nums = {1,2,3,4};
    k = 3;
    res = false;
    assert(res == Solution().canPartitionKSubsets(nums, k));

    cout << "OK~" << endl;
    
    return 0;
}
