/*
 * @lc app=leetcode.cn id=2027 lang=swift
 *
 * [2027] 转换字符串的最少操作次数
 */

// @lc code=start
class Solution {
    func minimumMoves(_ s: String) -> Int {
        var ans = 0, idx = -1
        var i = 0
        let s = Array(s)
        while i < s.count {
            if s[i] == "X" && idx < i {
                ans += 1
                idx = i + 2
                i += 2
            } else {
                i += 1
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var s: String
    var res: Int
    
    s = "OXOX"
    res = 1
    assert(res == Solution().minimumMoves(s))
    
    /**
     输入：s = "XXX"
     输出：1
     解释：XXX -> OOO
     一次操作，选中全部 3 个字符，并将它们转换为 'O' 。
     */
    s = "XXX"
    res = 1
    assert(res == Solution().minimumMoves(s))
    
    /**
     输入：s = "XXOX"
     输出：2
     解释：XXOX -> OOOX -> OOOO
     第一次操作，选择前 3 个字符，并将这些字符转换为 'O' 。
     然后，选中后 3 个字符，并执行转换。最终得到的字符串全由字符 'O' 组成。
     */
    s = "XXOX"
    res = 2
    assert(res == Solution().minimumMoves(s))
    
    /**
     输入：s = "OOOO"
     输出：0
     解释：s 中不存在需要转换的 'X' 。
     */
    s = "OOOO"
    res = 0
    assert(res == Solution().minimumMoves(s))
}
