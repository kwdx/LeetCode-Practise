/*
 * @lc app=leetcode.cn id=693 lang=swift
 *
 * [693] 交替位二进制数
 */

// @lc code=start
class Solution {
    func hasAlternatingBits(_ n: Int) -> Bool {
        var ans = -1
        var k = n
        while k > 0 {
            if k & 1 == ans {
                return false
            }
            ans = k & 1
            k >>= 1
        }
        return true
    }
}
// @lc code=end

func main() {
    var n: Int
    var res: Bool
    
    /**
     输入：n = 5
     输出：true
     解释：5 的二进制表示是：101
     */
    n = 5
    res = true
    assert(res == Solution().hasAlternatingBits(n))
    
    /**
     输入：n = 7
     输出：false
     解释：7 的二进制表示是：111.
     */
    n = 7
    res = false
    assert(res == Solution().hasAlternatingBits(n))
    
    /**
     输入：n = 11
     输出：false
     解释：11 的二进制表示是：1011.
     */
    n = 11
    res = false
    assert(res == Solution().hasAlternatingBits(n))
}
