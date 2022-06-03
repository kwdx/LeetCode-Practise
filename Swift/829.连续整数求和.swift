/*
 * @lc app=leetcode.cn id=829 lang=swift
 *
 * [829] 连续整数求和
 */

// @lc code=start
class Solution {
    func consecutiveNumbersSum(_ n: Int) -> Int {
        var ans = 0
        let m = n * 2
        var i = 1
        while i * i < m {
            if m % i == 0 {
                if (m / i - (i - 1)) % 2 == 0 {
                    ans += 1
                }
            }
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
     输入: n = 5
     输出: 2
     解释: 5 = 2 + 3，共有两组连续整数([5],[2,3])求和后为 5。
     */
    n = 5
    res = 2
    assert(res == Solution().consecutiveNumbersSum(n))
    
    /**
     输入: n = 9
     输出: 3
     解释: 9 = 4 + 5 = 2 + 3 + 4
     */
    n = 9
    res = 3
    assert(res == Solution().consecutiveNumbersSum(n))
    
    /**
     输入: n = 15
     输出: 4
     解释: 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
     */
    n = 15
    res = 4
    assert(res == Solution().consecutiveNumbersSum(n))
}
