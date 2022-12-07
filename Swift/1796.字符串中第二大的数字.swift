/*
 * @lc app=leetcode.cn id=1796 lang=swift
 *
 * [1796] 字符串中第二大的数字
 */

// @lc code=start
class Solution {
    func secondHighest(_ s: String) -> Int {
        var a = -1, b = -1
        for c in s {
            if let val = c.wholeNumberValue {
                if val > a {
                    b = a
                    a = val
                } else if val > b && val < a {
                    b = val
                }
            }
        }
        return b
    }
}
// @lc code=end

func main() {
    var s: String
    var res: Int
    
    /**
     输入：s = "dfa12321afd"
     输出：2
     解释：出现在 s 中的数字包括 [1, 2, 3] 。第二大的数字是 2 。
     */
    s = "dfa12321afd"
    res = 2
    assert(res == Solution().secondHighest(s))
    
    /**
     输入：s = "abc1111"
     输出：-1
     解释：出现在 s 中的数字只包含 [1] 。没有第二大的数字。
     */
    s = "abc1111"
    res = -1
    assert(res == Solution().secondHighest(s))
}
