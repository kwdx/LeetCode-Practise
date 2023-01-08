/*
 * @lc app=leetcode.cn id=2185 lang=swift
 *
 * [2185] 统计包含给定前缀的字符串
 */

// @lc code=start
class Solution {
    func prefixCount(_ words: [String], _ pref: String) -> Int {
        words.filter { $0.hasPrefix(pref) }.count
    }
}
// @lc code=end

func main() {
    var words: [String]
    var pref: String
    var res: Int
    
    /**
     输入：words = ["pay","attention","practice","attend"], pref = "at"
     输出：2
     解释：以 "at" 作为前缀的字符串有两个，分别是："attention" 和 "attend" 。
     */
    words = ["pay","attention","practice","attend"]
    pref = "at"
    res = 2
    assert(res == Solution().prefixCount(words, pref))
    
    /**
     输入：words = ["leetcode","win","loops","success"], pref = "code"
     输出：0
     解释：不存在以 "code" 作为前缀的字符串。
     */
    words = ["leetcode","win","loops","success"]
    pref = "code"
    res = 0
    assert(res == Solution().prefixCount(words, pref))
}
