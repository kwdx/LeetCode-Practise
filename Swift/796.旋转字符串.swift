/*
 * @lc app=leetcode.cn id=796 lang=swift
 *
 * [796] 旋转字符串
 */

// @lc code=start
class Solution {
    func rotateString(_ s: String, _ goal: String) -> Bool {
        s.count == goal.count && (s + s).contains(goal)
    }
}
// @lc code=end

func main() {
    var s: String
    var goal: String
    var res: Bool
    
    /**
     输入: s = "abcde", goal = "cdeab"
     输出: true
     */
    s = "abcde"
    goal = "cdeab"
    res = true
    assert(res == Solution().rotateString(s, goal))
    
    /**
     输入: s = "abcde", goal = "abced"
     输出: false
     */
    s = "abcde"
    goal = "abced"
    res = false
    assert(res == Solution().rotateString(s, goal))
}
