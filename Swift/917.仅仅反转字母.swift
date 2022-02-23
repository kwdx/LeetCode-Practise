/*
 * @lc app=leetcode.cn id=917 lang=swift
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
class Solution {
    func reverseOnlyLetters(_ s: String) -> String {
        var ans = Array(s)
        var left = 0, right = s.count - 1
        while left <= right {
            while left <= right && !ans[left].isLetter {
                left += 1
            }
            while left <= right && !ans[right].isLetter {
                right -= 1
            }
            if left <= right {
                ans.swapAt(left, right)
                left += 1
                right -= 1
            }
        }
        return String(ans)
    }
}
// @lc code=end

func main() {
    var s: String
    var res: String
    
    /**
     输入：s = "ab-cd"
     输出："dc-ba"
     */
    s = "ab-cd"
    res = "dc-ba"
    assert(res == Solution().reverseOnlyLetters(s))
    
    /**
     输入：s = "a-bC-dEf-ghIj"
     输出："j-Ih-gfE-dCba"
     */
    s = "a-bC-dEf-ghIj"
    res = "j-Ih-gfE-dCba"
    assert(res == Solution().reverseOnlyLetters(s))
    
    s = "-"
    res = "-"
    assert(res == Solution().reverseOnlyLetters(s))
}
