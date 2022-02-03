/*
 * @lc app=leetcode.cn id=1414 lang=swift
 *
 * [1414] 和为 K 的最少斐波那契数字数目
 */

// @lc code=start
class Solution {
    func findMinFibonacciNumbers(_ k: Int) -> Int {
        var a = 1, b = 1, c = 0
        var k_ = k
        while b < k {
            c = b
            b = a + b
            a = c
        }
        var ans = 0
        while k_ != 0 {
            if b <= k_ {
                k_ -= b
                ans += 1
            }
            c = a
            a = b - a
            b = c
        }
        return ans
    }
}
// @lc code=end

func main() {
    var k: Int
    var res: Int
    
    /**
     输入：k = 7
     输出：2
     解释：斐波那契数字为：1，1，2，3，5，8，13，……
     对于 k = 7 ，我们可以得到 2 + 5 = 7 。
     */
    k = 7
    res = 2
    assert(res == Solution().findMinFibonacciNumbers(k))
    
    /**
     输入：k = 10
     输出：2
     解释：对于 k = 10 ，我们可以得到 2 + 8 = 10 。
     */
    k = 10
    res = 2
    assert(res == Solution().findMinFibonacciNumbers(k))

    /**
     输入：k = 19
     输出：3
     解释：对于 k = 19 ，我们可以得到 1 + 5 + 13 = 19 。
     */
    k = 19
    res = 3
    assert(res == Solution().findMinFibonacciNumbers(k))
}
