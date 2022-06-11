/*
 * @lc app=leetcode.cn id=926 lang=swift
 *
 * [926] 将字符串翻转到单调递增
 */

// @lc code=start
class Solution {
    func minFlipsMonoIncr(_ s: String) -> Int {
        var dp0 = 0, dp1 = 0
        for c in s {
            var dp0New = dp0, dp1New = min(dp0, dp1)
            if c == "1" {
                dp0New += 1
            } else {
                dp1New += 1
            }
            dp0 = dp0New
            dp1 = dp1New
        }
        return min(dp0, dp1)
    }
}
// @lc code=end

func main() {
    var s: String
    var res: Int
    
    /**
     输入：s = "00110"
     输出：1
     解释：翻转最后一位得到 00111.
     */
    s = "00110"
    res = 1
    assert(res == Solution().minFlipsMonoIncr(s))
    
    /**
     输入：s = "010110"
     输出：2
     解释：翻转得到 011111，或者是 000111。
     */
    s = "010110"
    res = 2
    assert(res == Solution().minFlipsMonoIncr(s))
    
    /**
     输入：s = "00011000"
     输出：2
     解释：翻转得到 00000000。
     */
    s = "00011000"
    res = 2
    assert(res == Solution().minFlipsMonoIncr(s))
}
