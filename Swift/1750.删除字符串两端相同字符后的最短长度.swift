/*
 * @lc app=leetcode.cn id=1750 lang=swift
 *
 * [1750] 删除字符串两端相同字符后的最短长度
 */

// @lc code=start
class Solution {
    func minimumLength(_ s: String) -> Int {
        let s = Array(s)
        var left = 0, right = s.count - 1
        while left < right && s[left] == s[right] {
            let c = s[left]
            while left <= right && s[left] == c {
                left += 1
            }
            while left <= right && s[right] == c {
                right -= 1
            }
        }
        return right - left + 1
    }
}
// @lc code=end

func main() {
    var s: String
    var res: Int
    
    /**
     输入：s = "ca"
     输出：2
     解释：你没法删除任何一个字符，所以字符串长度仍然保持不变。
     */
    s = "ca"
    res = 2
    assert(res == Solution().minimumLength(s))
    
    /**
     输入：s = "cabaabac"
     输出：0
     解释：最优操作序列为：
     - 选择前缀 "c" 和后缀 "c" 并删除它们，得到 s = "abaaba" 。
     - 选择前缀 "a" 和后缀 "a" 并删除它们，得到 s = "baab" 。
     - 选择前缀 "b" 和后缀 "b" 并删除它们，得到 s = "aa" 。
     - 选择前缀 "a" 和后缀 "a" 并删除它们，得到 s = "" 。
     */
    s = "cabaabac"
    res = 0
    assert(res == Solution().minimumLength(s))
    
    /**
     输入：s = "aabccabba"
     输出：3
     解释：最优操作序列为：
     - 选择前缀 "aa" 和后缀 "a" 并删除它们，得到 s = "bccabb" 。
     - 选择前缀 "b" 和后缀 "bb" 并删除它们，得到 s = "cca" 。
     */
    s = "aabccabba"
    res = 3
    assert(res == Solution().minimumLength(s))
}
