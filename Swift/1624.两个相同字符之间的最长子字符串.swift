/*
 * @lc app=leetcode.cn id=1624 lang=swift
 *
 * [1624] 两个相同字符之间的最长子字符串
 */

// @lc code=start
class Solution {
    func maxLengthBetweenEqualCharacters(_ s: String) -> Int {
        var ans = -1
        var pres: [Character: Int] = [:]
        let chars = Array(s)
        for i in 0..<chars.count {
            if let idx = pres[chars[i]] {
                ans = max(ans, i - idx - 1)
            } else {
                pres[chars[i]] = i
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var s: String
    var res: Int
    
    /**
     输入：s = "aa"
     输出：0
     解释：最优的子字符串是两个 'a' 之间的空子字符串。
     */
    s = "aa"
    res = 0
    assert(res == Solution().maxLengthBetweenEqualCharacters(s))
    
    /**
     输入：s = "abca"
     输出：2
     解释：最优的子字符串是 "bc" 。
     */
    s = "abca"
    res = 2
    assert(res == Solution().maxLengthBetweenEqualCharacters(s))
    
    /**
     输入：s = "cbzxy"
     输出：-1
     解释：s 中不存在出现出现两次的字符，所以返回 -1 。
     */
    s = "cbzxy"
    res = -1
    assert(res == Solution().maxLengthBetweenEqualCharacters(s))
    
    /**
     输入：s = "cabbac"
     输出：4
     解释：最优的子字符串是 "abba" ，其他的非最优解包括 "bb" 和 "" 。
     */
    s = "cabbac"
    res = 4
    assert(res == Solution().maxLengthBetweenEqualCharacters(s))
}
