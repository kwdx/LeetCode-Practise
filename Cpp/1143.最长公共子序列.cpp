/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = (int)text1.size();
        int m = (int)text2.size();

        int dp[n + 1][m + 1];
        for (int i = 0; i <= n; i++) {
            memset(dp[i], 0, (m + 1) * sizeof(int));
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    string text1, text2;
    int res;
    
    /**
     输入：text1 = "abcde", text2 = "ace"
     输出：3
     解释：最长公共子序列是 "ace" ，它的长度为 3 。
     */
    text1 = "abcde";
    text2 = "ace";
    res = 3;
    assert(res == Solution().longestCommonSubsequence(text1, text2));
    
    /**
     输入：text1 = "abc", text2 = "abc"
     输出：3
     解释：最长公共子序列是 "abc" ，它的长度为 3 。
     */
    text1 = "abc";
    text2 = "abc";
    res = 3;
    assert(res == Solution().longestCommonSubsequence(text1, text2));
    
    /**
     输入：text1 = "abc", text2 = "def"
     输出：0
     解释：两个字符串没有公共子序列，返回 0 。
     */
    text1 = "abc";
    text2 = "def";
    res = 0;
    assert(res == Solution().longestCommonSubsequence(text1, text2));
    
    cout << "OK~" << endl;
    
    return 0;
}
