/*
 * @lc app=leetcode.cn id=get-kth-magic-number-lcci lang=cpp
 *
 * [面试题] 17.09. 第 k 个数
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> dp(k + 1);
        dp[1] = 1;
        int p3 = 1, p5 = 1, p7 = 1;
        for (int i = 2; i <= k; ++i) {
            int num3 = dp[p3] * 3;
            int num5 = dp[p5] * 5;
            int num7 = dp[p7] * 7;
            dp[i] = min(num3, min(num5, num7));
            if (dp[i] == num3) {
                ++p3;
            }
            if (dp[i] == num5) {
                ++p5;
            }
            if (dp[i] == num7) {
                ++p7;
            }
        }
        return dp[k];
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int k;
    int res;
    
    /**
     输入: k = 5
     输出: 9
     */
    k = 5;
    res = 9;
    assert(res == Solution().getKthMagicNumber(k));

    cout << "OK~" << endl;
    
    return 0;
}

