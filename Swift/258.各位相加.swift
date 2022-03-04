/*
 * @lc app=leetcode.cn id=258 lang=swift
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
    func addDigits(_ num: Int) -> Int {
        (num - 1) % 9 + 1
    }
}
// @lc code=end

func main() {
    var num: Int
    var res: Int
    
    /**
     输入: num = 38
     输出: 2
     解释: 各位相加的过程为：
     38 --> 3 + 8 --> 11
     11 --> 1 + 1 --> 2
     由于 2 是一位数，所以返回 2。
     */
    num = 38
    res = 2
    assert(res == Solution().addDigits(num))
    
    /**
     输入: num = 0
     输出: 0
     */
    num = 0
    res = 0
    assert(res == Solution().addDigits(num))
}
