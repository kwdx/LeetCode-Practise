/*
 * @lc app=leetcode.cn id=942 lang=swift
 *
 * [942] 增减字符串匹配
 */

// @lc code=start
class Solution {
    func diStringMatch(_ s: String) -> [Int] {
        var ans: [Int] = []
        var l = 0, r = s.count
        for char in s {
            if char == "I" {
                ans.append(l)
                l += 1
            } else {
                ans.append(r)
                r -= 1
            }
        }
        ans.append(l)
        return ans
    }
}
// @lc code=end

func main() {
    var s: String
    var res: [Int]
    
    /**
     输入：s = "IDID"
     输出：[]
     */
    s = "IDID"
    res = [0,4,1,3,2]
    assert(res == Solution().diStringMatch(s))
    
    /**
     输入：s = "III"
     输出：[0,1,2,3]
     */
    s = "III"
    res = [0,1,2,3]
    assert(res == Solution().diStringMatch(s))
    
    /**
     输入：s = "DDI"
     输出：[3,2,0,1]
     */
    s = "DDI"
    res = [3,2,0,1]
    assert(res == Solution().diStringMatch(s))
}
