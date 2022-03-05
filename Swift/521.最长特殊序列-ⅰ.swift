/*
 * @lc app=leetcode.cn id=521 lang=swift
 *
 * [521] 最长特殊序列 Ⅰ
 */

// @lc code=start
class Solution {
    func findLUSlength(_ a: String, _ b: String) -> Int {
        a == b ? -1 : max(a.count, b.count)
    }
}
// @lc code=end

func main() {
    var a: String
    var b: String
    var res: Int
    
    /**
     输入: a = "aba", b = "cdc"
     输出: 3
     解释: 最长特殊序列可为 "aba" (或 "cdc")，两者均为自身的子序列且不是对方的子序列。
     */
    a = "aba"
    b = "cdc"
    res = 3
    assert(res == Solution().findLUSlength(a, b))
    
    /**
     输入：a = "aaa", b = "bbb"
     输出：3
     解释: 最长特殊序列是 "aaa" 和 "bbb" 。
     */
    a = "aaa"
    b = "bbb"
    res = 3
    assert(res == Solution().findLUSlength(a, b))

    /**
     输入：a = "aaa", b = "aaa"
     输出：-1
     解释: 字符串 a 的每个子序列也是字符串 b 的每个子序列。同样，字符串 b 的每个子序列也是字符串 a 的子序列。
     */
    a = "aaa"
    b = "aaa"
    res = -1
    assert(res == Solution().findLUSlength(a, b))
}
