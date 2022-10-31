/*
 * @lc app=leetcode.cn id=481 lang=swift
 *
 * [481] 神奇字符串
 */

// @lc code=start
class Solution {
    func magicalString(_ n: Int) -> Int {
        var ans = 1
        var s: [Int8] = [1,2,2]
        var i = 2
        var j = 3
        while j < n {
            var size = s[i]
            let num = 3 - s[j - 1]
            while size > 0 && j < n {
                s.append(num)
                if num == 1 {
                    ans += 1
                }
                j += 1
                size -= 1
            }
            i += 1
        }
        return ans
    }
}
// @lc code=end

func main() {
    var n: Int
    var res: Int
    
    /**
     输入：n = 6
     输出：3
     解释：神奇字符串 s 的前 6 个元素是 “122112”，它包含三个 1，因此返回 3 。
     */
    n = 6
    res = 3
    assert(res == Solution().magicalString(n))
    
    /**
     输入：n = 1
     输出：1
     */
    n = 1
    res = 1
    assert(res == Solution().magicalString(n))
}
