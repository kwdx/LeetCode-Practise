/*
 * @lc app=leetcode.cn id=902 lang=swift
 *
 * [902] 最大为 N 的数字组合
 */

// @lc code=start
class Solution {
    func atMostNGivenDigitSet(_ digits: [String], _ n: Int) -> Int {
        let s = Array(String(n))
        let digits = digits.map { Array($0) }
        let m = digits.count
        let k = s.count
        var dp = [[Int]](repeating: [Int](repeating: 0, count: 2), count: k + 1)
        dp[0][1] = 1
        for i in 1...k {
            for j in 0..<m {
                if digits[j][0] == s[i - 1] {
                    dp[i][1] = dp[i - 1][1]
                } else if digits[j][0] < s[i - 1] {
                    dp[i][0] += dp[i - 1][1]
                } else {
                    break
                }
            }
            if i > 1 {
                dp[i][0] += m + dp[i - 1][0] * m
            }
        }
        return dp[k][0] + dp[k][1]
    }
}
// @lc code=end

func main() {
    var digits: [String]
    var n: Int
    var res: Int
    
    /**
     输入：digits = ["1","3","5","7"], n = 100
     输出：20
     解释：
     可写出的 20 个数字是：
     1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.
     */
    digits = ["1","3","5","7"]
    n = 100
    res = 20
    assert(res == Solution().atMostNGivenDigitSet(digits, n))
    
    /**
     输入：digits = ["1","4","9"], n = 1000000000
     输出：29523
     解释：
     我们可以写 3 个一位数字，9 个两位数字，27 个三位数字，
     81 个四位数字，243 个五位数字，729 个六位数字，
     2187 个七位数字，6561 个八位数字和 19683 个九位数字。
     总共，可以使用D中的数字写出 29523 个整数。
     */
    digits = ["1","4","9"]
    n = 1000000000
    res = 29523
    assert(res == Solution().atMostNGivenDigitSet(digits, n))
    
    /**
     输入：digits = ["7"], n = 8
     输出：1
     */
    digits = ["7"]
    n = 8
    res = 1
    assert(res == Solution().atMostNGivenDigitSet(digits, n))
}
