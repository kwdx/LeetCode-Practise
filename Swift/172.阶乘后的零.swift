/*
 * @lc app=leetcode.cn id=172 lang=swift
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution {
    func trailingZeroes(_ n: Int) -> Int {
        var ans = 0
        var num = n
        while num > 0 {
            num /= 5
            ans += num
        }
        return ans
    }
}
// @lc code=end

func main() {
    var n: Int
    var res: Int
    
    /**
     输入：n = 3
     输出：0
     解释：3! = 6 ，不含尾随 0
     */
    n = 3
    res = 0
    assert(res == Solution().trailingZeroes(n))
    
    /**
     输入：n = 5
     输出：1
     解释：5! = 120 ，有一个尾随 0
     */
    n = 5
    res = 1
    assert(res == Solution().trailingZeroes(n))
    
    /**
     输入：n = 0
     输出：0
     */
    n = 0
    res = 0
    assert(res == Solution().trailingZeroes(n))
}
