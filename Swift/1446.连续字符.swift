/*
 * @lc app=leetcode.cn id=1446 lang=swift
 *
 * [1446] 连续字符
 */

// @lc code=start
class Solution {
    func maxPower(_ s: String) -> Int {
        guard var preC = s.first else { return 0 }
        var ans = 0
        var cnt = 0
        for c in s {
            if c == preC {
                cnt += 1
            } else {
                ans = max(ans, cnt)
                cnt = 1
                preC = c
            }
        }
        return max(ans, cnt)
    }
}
// @lc code=end

func main() {
    var s: String
    var res: Int
    
    /**
     输入：s = "leetcode"
     输出：2
     解释：子字符串 "ee" 长度为 2 ，只包含字符 'e' 。
     */
    s = "leetcode"
    res = 2
    assert(res == Solution().maxPower(s))
    
    /**
     输入：s = "abbcccddddeeeeedcba"
     输出：5
     解释：子字符串 "eeeee" 长度为 5 ，只包含字符 'e' 。
     */
    s = "abbcccddddeeeeedcba"
    res = 5
    assert(res == Solution().maxPower(s))
    
    /**
     输入：s = "triplepillooooow"
     输出：5
     */
    s = "triplepillooooow"
    res = 5
    assert(res == Solution().maxPower(s))
    
    /**
     输入：s = "hooraaaaaaaaaaay"
     输出：11
     */
    s = "hooraaaaaaaaaaay"
    res = 11
    assert(res == Solution().maxPower(s))
    
    /**
     输入：s = "tourist"
     输出：1
     */
    s = "tourist"
    res = 1
    assert(res == Solution().maxPower(s))
}
