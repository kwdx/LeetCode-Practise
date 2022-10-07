/*
 * @lc app=leetcode.cn id=1784 lang=swift
 *
 * [1784] 检查二进制字符串字段
 */

// @lc code=start
class Solution {
    func checkOnesSegment(_ s: String) -> Bool {
        let n = s.count
        let chars = Array(s)
        var cnt = 0, idx = 0
        while idx < n && cnt <= 1 {
            while idx < n && chars[idx] == "0" {
                idx += 1
            }
            if idx < n {
                while idx < n && chars[idx] == "1" {
                    idx += 1
                }
                cnt += 1
            }
        }
        return cnt <= 1
    }
}
// @lc code=end

func main() {
    var s: String
    var res: Bool
    
    /**
     输入：s = "1001"
     输出：false
     解释：由连续若干个 '1' 组成的字段数量为 2，返回 false
     */
    s = "1001"
    res = false
    assert(res == Solution().checkOnesSegment(s))
    
    /**
     输入：s = "110"
     输出：true
     */
    s = "110"
    res = true
    assert(res == Solution().checkOnesSegment(s))
}
