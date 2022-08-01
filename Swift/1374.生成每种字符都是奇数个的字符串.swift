/*
 * @lc app=leetcode.cn id=1374 lang=swift
 *
 * [1374] 生成每种字符都是奇数个的字符串
 */

// @lc code=start
class Solution {
    func generateTheString(_ n: Int) -> String {
        if n % 2 == 1 {
            return String(repeating: "a", count: n)
        } else {
            return String(repeating: "a", count: n - 1) + "b"
        }
    }
}
// @lc code=end

func main() {
    var n: Int
    var res: String
    
    /**
     输入：n = 4
     输出："pppz"
     解释："pppz" 是一个满足题目要求的字符串，因为 'p' 出现 3 次，且 'z' 出现 1 次。当然，还有很多其他字符串也满足题目要求，比如："ohhh" 和 "love"。
     */
    n = 4
    res = "aaab"
    assert(res == Solution().generateTheString(n))
    
    /**
     输入：n = 2
     输出："xy"
     解释："xy" 是一个满足题目要求的字符串，因为 'x' 和 'y' 各出现 1 次。当然，还有很多其他字符串也满足题目要求，比如："ag" 和 "ur"。
     */
    n = 2
    res = "ab"
    assert(res == Solution().generateTheString(n))
    
    /**
     输入：n = 7
     输出："holasss"
     */
    n = 7
    res = "aaaaaaa"
    assert(res == Solution().generateTheString(n))
}
