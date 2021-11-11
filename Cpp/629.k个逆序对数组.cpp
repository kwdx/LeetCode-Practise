/*
 * @lc app=leetcode.cn id=629 lang=cpp
 *
 * [629] K个逆序对数组
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
private:
    int mod = 1e9+7;
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[1][0] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= k; j++) {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
                if (i <= j) {
                    dp[i][j] = ((dp[i][j] - dp[i - 1][j - i]) % mod + mod) % mod;
                }
            }
        }
        return dp[n][k];
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, k;
    int res;
    
    /**
     输入: n = 3, k = 0
     输出: 1
     解释:
     只有数组 [1,2,3] 包含了从1到3的整数并且正好拥有 0 个逆序对。
     */
    n = 3;
    k = 0;
    res = 1;
    assert(res == Solution().kInversePairs(n, k));
    
    /**
     输入: n = 3, k = 1
     输出: 2
     解释:
     数组 [1,3,2] 和 [2,1,3] 都有 1 个逆序对。
     */
    n = 3;
    k = 1;
    res = 2;
    assert(res == Solution().kInversePairs(n, k));
    
    /**
     输入: n = 1, k = 0
     输出: 1
     */
    n = 1;
    k = 0;
    res = 1;
    assert(res == Solution().kInversePairs(n, k));
    
    /**
     输入: n = 1, k = 1
     输出: 0
     */
    n = 1;
    k = 1;
    res = 0;
    assert(res == Solution().kInversePairs(n, k));

    cout << "OK~" << endl;

    return 0;
}
