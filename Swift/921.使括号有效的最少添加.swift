/*
 * @lc app=leetcode.cn id=921 lang=swift
 *
 * [921] 使括号有效的最少添加
 */

// @lc code=start
class Solution {
    func minAddToMakeValid(_ s: String) -> Int {
        var ans = 0
        var score = 0
        for c in s {
            score += c == "(" ? 1 : -1
            if score < 0 {
                score = 0
                ans += 1
            }
        }
        return score + ans
    }
}
// @lc code=end

func main() {
    var s: String
    var res: Int
    
    /**
     输入：s = "())"
     输出：1
     */
    s = "())"
    res = 1
    assert(res == Solution().minAddToMakeValid(s))
    
    /**
     输入：s = "((("
     输出：3
     */
    s = "((("
    res = 3
    assert(res == Solution().minAddToMakeValid(s))
}
