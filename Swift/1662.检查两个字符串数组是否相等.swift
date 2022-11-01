/*
 * @lc app=leetcode.cn id=1662 lang=swift
 *
 * [1662] 检查两个字符串数组是否相等
 */

// @lc code=start
class Solution {
    func arrayStringsAreEqual(_ word1: [String], _ word2: [String]) -> Bool {
        word1.joined() == word2.joined()
    }
}
// @lc code=end

func main() {
    var word1: [String]
    var word2: [String]
    var res: Bool
    
    /**
     输入：word1 = ["ab", "c"], word2 = ["a", "bc"]
     输出：true
     解释：
     word1 表示的字符串为 "ab" + "c" -> "abc"
     word2 表示的字符串为 "a" + "bc" -> "abc"
     两个字符串相同，返回 true
     */
    word1 = ["ab", "c"]
    word2 = ["a", "bc"]
    res = true
    assert(res == Solution().arrayStringsAreEqual(word1, word2))
    
    /**
     输入：word1 = ["a", "cb"], word2 = ["ab", "c"]
     输出：false
     */
    word1 = ["a", "cb"]
    word2 = ["ab", "c"]
    res = false
    assert(res == Solution().arrayStringsAreEqual(word1, word2))
    
    /**
     输入：word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
     输出：true
     */
    word1 = ["abc", "d", "defg"]
    word2 = ["abcddefg"]
    res = true
    assert(res == Solution().arrayStringsAreEqual(word1, word2))
}
