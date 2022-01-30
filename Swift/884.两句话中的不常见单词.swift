/*
 * @lc app=leetcode.cn id=884 lang=swift
 *
 * [884] 两句话中的不常见单词
 */

// @lc code=start
class Solution {
    func uncommonFromSentences(_ s1: String, _ s2: String) -> [String] {
        var freq: [String: Int] = [:]
        s1.split(separator: " ").forEach {
            freq[String($0)] = 1 + (freq[String($0)] ?? 0)
        }
        s2.split(separator: " ").forEach {
            freq[String($0)] = 1 + (freq[String($0)] ?? 0)
        }
        return freq.filter { $0.value == 1 }.map { $0.key }
    }
}
// @lc code=end

func main() {
    var s1: String
    var s2: String
    var res: [String]
    
    /**
     输入：s1 = "this apple is sweet", s2 = "this apple is sour"
     输出：["sweet","sour"]
     */
    s1 = "this apple is sweet"
    s2 = "this apple is sour"
    res = ["sour","sweet"]
    assert(res == Solution().uncommonFromSentences(s1, s2))
    
    /**
     输入：s1 = "apple apple", s2 = "banana"
     输出：["banana"]
     */
    s1 = "apple apple"
    s2 = "banana"
    res = ["banana"]
    assert(res == Solution().uncommonFromSentences(s1, s2))
}
