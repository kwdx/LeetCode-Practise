/*
 * @lc app=leetcode.cn id=1768 lang=swift
 *
 * [1768] 交替合并字符串
 */

// @lc code=start
class Solution {
    func mergeAlternately(_ word1: String, _ word2: String) -> String {
        var ans = ""
        let word1 = Array(word1)
        let word2 = Array(word2)
        for i in 0..<min(word1.count, word2.count) {
            ans.append(word1[i])
            ans.append(word2[i])
        }
        if word1.count < word2.count {
            ans.append(contentsOf: word2[word1.count...])
        } else {
            ans.append(contentsOf: word1[word2.count...])
        }
        return ans
    }
}
// @lc code=end

func main() {
    var word1: String
    var word2: String
    var res: String
    
    /**
     输入：word1 = "abc", word2 = "pqr"
     输出："apbqcr"
     解释：字符串合并情况如下所示：
     word1：  a   b   c
     word2：    p   q   r
     合并后：  a p b q c r
     */
    word1 = "abc"
    word2 = "pqr"
    res = "apbqcr"
    assert(res == Solution().mergeAlternately(word1, word2))
    
    /**
     输入：word1 = "ab", word2 = "pqrs"
     输出："apbqrs"
     解释：注意，word2 比 word1 长，"rs" 需要追加到合并后字符串的末尾。
     word1：  a   b
     word2：    p   q   r   s
     合并后：  a p b q   r   s
     */
    word1 = "ab"
    word2 = "pqrs"
    res = "apbqrs"
    assert(res == Solution().mergeAlternately(word1, word2))
    
    /**
     输入：word1 = "abcd", word2 = "pq"
     输出："apbqcd"
     解释：注意，word1 比 word2 长，"cd" 需要追加到合并后字符串的末尾。
     word1：  a   b   c   d
     word2：    p   q
     合并后：  a p b q c   d
     */
    word1 = "abcd"
    word2 = "pq"
    res = "apbqcd"
    assert(res == Solution().mergeAlternately(word1, word2))
}
