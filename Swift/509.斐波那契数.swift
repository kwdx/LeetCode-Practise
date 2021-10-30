/*
 * @lc app=leetcode.cn id=509 lang=swift
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
    func fib(_ n: Int) -> Int {
        if n == 0 {
            return 0
        }
        var f0 = 0
        var f1 = 1
        for _ in 1..<n {
            let tmp = f1
            f1 = f1 + f0
            f0 = tmp
        }
        return f1
    }
}
// @lc code=end

func main() {
    var n: Int
    var res: Int
    
    /**
     输入：2
     输出：1
     解释：F(2) = F(1) + F(0) = 1 + 0 = 1
     */
    n = 2
    res = 1
    assert(res == Solution().fib(n))
    
    /**
     输入：3
     输出：2
     解释：F(3) = F(2) + F(1) = 1 + 1 = 2
     */
    n = 3
    res = 2
    assert(res == Solution().fib(n))
    
    /**
     输入：4
     输出：3
     解释：F(4) = F(3) + F(2) = 2 + 1 = 3
     */
    n = 4
    res = 3
    assert(res == Solution().fib(n))
}
