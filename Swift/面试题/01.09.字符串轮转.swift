/*
 * @lc app=leetcode.cn id=string-rotation-lcci lang=swift
 *
 * [面试题] 01.09. 字符串轮转
 */

// @lc code=start
class Solution {
    func isFlipedString(_ s1: String, _ s2: String) -> Bool {
        guard s1.count == s2.count else { return false }
        if s1 == "" {
            return true
        }
        return (s1 + s1).contains(s2)
    }
}
// @lc code=end

func main() {
    var s1: String
    var s2: String
    var res: Bool
    
    /**
     输入：s1 = "waterbottle", s2 = "erbottlewat"
     输出：True
     */
    s1 = "waterbottle"
    s2 = "erbottlewat"
    res = true
    assert(res == Solution().isFlipedString(s1, s2))
    
    /**
     输入：s1 = "aa", s2 = "aba"
     输出：False
     */
    s1 = "aa"
    s2 = "aba"
    res = false
    assert(res == Solution().isFlipedString(s1, s2))
}
