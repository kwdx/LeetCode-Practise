/*
 * @lc app=leetcode.cn id=730 lang=cpp
 *
 * [730] 统计不同回文子序列
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int countPalindromicSubsequences(string s) {
        int n = (int)s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    int low = i + 1;
                    int high = j - 1;
                    while (low <= high && s[low] != s[i]) {
                        ++low;
                    }
                    while (high >= low && s[high] != s[j]) {
                        --high;
                    }
                    if (low > high) {
                        dp[i][j] = (2 + dp[i + 1][j - 1] * 2) % MOD;
                    } else if (low == high) {
                        dp[i][j] = (1 + dp[i + 1][j - 1] * 2) % MOD;
                    } else {
                        dp[i][j] = (0LL + dp[i + 1][j - 1] * 2 - dp[low + 1][high - 1] + MOD) % MOD;
                    }
                } else {
                    dp[i][j] = (0LL + dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
                }
            }
        }
        
        return dp[0][n - 1];
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    int res;
    
    /**
     输入：s = 'bccb'
     输出：6
     解释：6 个不同的非空回文子字符序列分别为：'b', 'c', 'bb', 'cc', 'bcb', 'bccb'。
     注意：'bcb' 虽然出现两次但仅计数一次。
     */
    s = "bccb";
    res = 6;
    assert(res == Solution().countPalindromicSubsequences(s));
    
    /**
     输入：s = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
     输出：104860361
     解释：共有 3104860382 个不同的非空回文子序列，104860361 对 109 + 7 取模后的值。
     */
    s = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba";
    res = 104860361;
    assert(res == Solution().countPalindromicSubsequences(s));
    
    cout << "OK~" << endl;
    
    return 0;
}
