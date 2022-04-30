/*
 * @lc app=leetcode.cn id=479 lang=swift
 *
 * [479] 最大回文数乘积
 */

import Darwin

// @lc code=start
class Solution {
    func largestPalindrome(_ n: Int) -> Int {
        if n == 1 {
            return 9
        }
        
        let maxNum = Int(pow(10, Double(n)) - 1)
        let minNum = Int(pow(10, Double(n - 1)))
        for i in (minNum...maxNum).reversed() {
            var num = i, t = i
            while t != 0 {
                num = num * 10 + (t % 10)
                t /= 10
            }
            var j = maxNum
            while j * j >= num {
                if num % j == 0 {
                   return num % 1337
                }
                j -= 1
            }

        }
        
        return -1
    }
}
// @lc code=end

func main() {
    var n: Int
    var res: Int
    
    /**
     输入：n = 2
     输出：987
     解释：99 x 91 = 9009, 9009 % 1337 = 987
     */
    n = 2
    res = 987
    assert(res == Solution().largestPalindrome(n))
    
    /**
     输入： n = 1
     输出： 9
     */
    n = 1
    res = 9
    assert(res == Solution().largestPalindrome(n))
}
