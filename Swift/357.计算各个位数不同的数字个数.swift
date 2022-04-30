/*
 * @lc app=leetcode.cn id=357 lang=swift
 *
 * [357] 计算各个位数不同的数字个数
 */

// @lc code=start
class Solution {
    func countNumbersWithUniqueDigits(_ n: Int) -> Int {
        guard n > 0 else { return 1 }
        var ans = 10
        var i = 2, a = 9
        while i <= n {
            let cur = a * (10 - i + 1)
            ans += cur
            a = cur
            i += 1
        }
        return ans
    }
}
// @lc code=end

func main() {
    var n: Int
    var res: Int
    
    /**
     输入：n = 2
     输出：91
     解释：答案应为除去 11、22、33、44、55、66、77、88、99 外，在 0 ≤ x < 100 范围内的所有数字。
     */
    n = 2
    res = 91
    assert(res == Solution().countNumbersWithUniqueDigits(n))
    
    /**
     输入：n = 0
     输出：1
     */
    n = 0
    res = 1
    assert(res == Solution().countNumbersWithUniqueDigits(n))
}
