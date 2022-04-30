/*
 * @lc app=leetcode.cn id=191 lang=swift
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
    func hammingWeight(_ n: Int) -> Int {
        var ans = 0
        var k = n
        while k > 0 {
            k &= k - 1
            ans += 1
        }
        return ans
    }
}
// @lc code=end

func main() {
    var n: Int
    var res: Int
    
    /**
     输入：00000000000000000000000000001011
     输出：3
     解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
     */
    n = 0b00000000000000000000000000001011
    res = 3
    assert(res == Solution().hammingWeight(n))
    
    /**
     输入：00000000000000000000000010000000
     输出：1
     解释：输入的二进制串 00000000000000000000000010000000 中，共有一位为 '1'。
     */
    n = 0b00000000000000000000000010000000
    res = 1
    assert(res == Solution().hammingWeight(n))
    
    /**
     输入：11111111111111111111111111111101
     输出：31
     解释：输入的二进制串 11111111111111111111111111111101 中，共有 31 位为 '1'。
     */
    n = 0b11111111111111111111111111111101
    res = 31
    assert(res == Solution().hammingWeight(n))
}
