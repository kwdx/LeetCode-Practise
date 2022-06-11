/*
 * @lc app=leetcode.cn id=730 lang=swift
 *
 * [730] 统计不同回文子序列
 */

// @lc code=start
class Solution {
    let MOD: Int = Int(1e9 + 7)
    
    func countPalindromicSubsequences(_ s: String) -> Int {
        let n = s.count
        let chars = Array(s)
        var dp: [[Int]] = .init(repeating: .init(repeating: 0, count: n), count: n)
        for i in 0..<n {
            dp[i][i] = 1
        }
        
        var len = 2
        while len <= n {
            for i in 0...(n - len) {
                let j = i + len - 1
                if chars[i] == chars[j] {
                    var low = i + 1
                    var high = j - 1
                    while low <= high && chars[low] != chars[i] {
                        low += 1
                    }
                    while low <= high && chars[high] != chars[j] {
                        high -= 1
                    }
                    if low > high {
                        dp[i][j] = (2 + dp[i + 1][j - 1] * 2) % MOD
                    } else if low == high {
                        dp[i][j] = (1 + dp[i + 1][j - 1] * 2) % MOD
                    } else {
                        dp[i][j] = (0 + dp[i + 1][j - 1] * 2 - dp[low + 1][high - 1] + MOD) % MOD
                    }
                } else {
                    dp[i][j] = (0 + dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD
                }
            }
            len += 1
        }
        return dp[0][n - 1]
    }
}
// @lc code=end

func main() {
    var s: String
    var res: Int
    
    s = "ab"
    res = 2
    assert(res == Solution().countPalindromicSubsequences(s))
    
    /**
     输入：s = 'bccb'
     输出：6
     解释：6 个不同的非空回文子字符序列分别为：'b', 'c', 'bb', 'cc', 'bcb', 'bccb'。
     注意：'bcb' 虽然出现两次但仅计数一次。
     */
    s = "bccb"
    res = 6
    assert(res == Solution().countPalindromicSubsequences(s))
    
    /**
     输入：s = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
     输出：104860361
     解释：共有 3104860382 个不同的非空回文子序列，104860361 对 109 + 7 取模后的值。
     */
    s = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba"
    res = 104860361
    assert(res == Solution().countPalindromicSubsequences(s))
}
