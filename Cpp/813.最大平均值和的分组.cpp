/*
 * @lc app=leetcode.cn id=813 lang=cpp
 *
 * [813] 最大平均值和的分组
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<double> prefix(n + 1);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        vector<vector<double>> dp(n + 1, vector<double>(k + 1));
        for (int i = 1; i <= n; ++i) {
            dp[i][1] = prefix[i] / i;
        }
        for (int j = 2; j <= k; ++j) {
            for (int i = j; i <= n; ++i) {
                for (int x = j - 1; x < i; ++x) {
                    dp[i][j] = max(dp[i][j], dp[x][j - 1] + (prefix[i] - prefix[x]) / (i - x));
                }
            }
        }
        return dp[n][k];
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int k;
    double res;
    
    /**
     输入: nums = [9,1,2,3,9], k = 3
     输出: 20.00000
     解释:
     nums 的最优分组是[9], [1, 2, 3], [9]. 得到的分数是 9 + (1 + 2 + 3) / 3 + 9 = 20.
     我们也可以把 nums 分成[9, 1], [2], [3, 9].
     这样的分组得到的分数为 5 + 2 + 6 = 13, 但不是最大值.
     */
    nums = {9,1,2,3,9};
    k = 3;
    res = 20.00000;
    assert(res == Solution().largestSumOfAverages(nums, k));
    
    /**
     输入: nums = [1,2,3,4,5,6,7], k = 4
     输出: 20.50000
     */
    nums = {1,2,3,4,5,6,7};
    k = 4;
    res = 20.50000;
    assert(res == Solution().largestSumOfAverages(nums, k));
    
    cout << "OK~" << endl;
    
    return 0;
}
