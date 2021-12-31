/*
 * @lc app=leetcode.cn id=507 lang=swift
 *
 * [507] 完美数
 */

// @lc code=start
class Solution {
    func checkPerfectNumber(_ num: Int) -> Bool {
        guard num > 1 else { return false }
        var ans = 1
        var i = 2
        while i < num / i {
            if num % i == 0 {
                ans += i
                if (i * i != num) {
                    ans += num / i
                }
            }
            i += 1
        }
        return ans == num
    }
}
// @lc code=end

func main() {
    var num: Int
    var res: Bool
    
    /**
     输入：num = 28
     输出：true
     解释：28 = 1 + 2 + 4 + 7 + 14
     1, 2, 4, 7, 和 14 是 28 的所有正因子。
     */
    num = 28
    res = true
    assert(res == Solution().checkPerfectNumber(num))
    
    /**
     输入：num = 6
     输出：true
     */
    num = 6
    res = true
    assert(res == Solution().checkPerfectNumber(num))
    
    /**
     输入：num = 496
     输出：true
     */
    num = 496
    res = true
    assert(res == Solution().checkPerfectNumber(num))
    
    /**
     输入：num = 8128
     输出：true
     */
    num = 8128
    res = true
    assert(res == Solution().checkPerfectNumber(num))
    
    /**
     输入：num = 2
     输出：false
     */
    num = 2
    res = false
    assert(res == Solution().checkPerfectNumber(num))
}
