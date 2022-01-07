/*
 * @lc app=leetcode.cn id=1614 lang=swift
 *
 * [1614] 括号的最大嵌套深度
 */

// @lc code=start
class Solution {
    func maxDepth(_ s: String) -> Int {
        var ans = 0
        var cnt = 0
        for ch in s {
            if ch == "(" {
                cnt += 1
            } else if ch == ")" {
                cnt -= 1
            }
            ans = max(ans, cnt)
        }
        return ans
    }
}
// @lc code=end

func main() {
    var s: String
    var res: Int
    
    /**
     输入：s = "(1+(2*3)+((8)/4))+1"
     输出：3
     解释：数字 8 在嵌套的 3 层括号中。
     */
    s = "(1+(2*3)+((8)/4))+1"
    res = 3
    assert(res == Solution().maxDepth(s))
    
    /**
     输入：s = "(1)+((2))+(((3)))"
     输出：3
     */
    s = "(1)+((2))+(((3)))"
    res = 3
    assert(res == Solution().maxDepth(s))
    
    /**
     输入：s = "1+(2*3)/(2-1)"
     输出：1
     */
    s = "1+(2*3)/(2-1)"
    res = 1
    assert(res == Solution().maxDepth(s))
    
    /**
     输入：s = "1"
     输出：0
     */
    s = "1"
    res = 0
    assert(res == Solution().maxDepth(s))
}
