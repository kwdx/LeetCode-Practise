/*
 * @lc app=leetcode.cn id=1813 lang=swift
 *
 * [1813] 句子相似性 III
 */

// @lc code=start
class Solution {
    func areSentencesSimilar(_ sentence1: String, _ sentence2: String) -> Bool {
        let words1 = sentence1.split(separator: " ")
        let words2 = sentence2.split(separator: " ")
        var i = 0, j = 0
        while i < words1.count && i < words2.count && words1[i] == words2[i] {
            i += 1
        }
        while j < words1.count - i && j < words2.count - i && words1[words1.count - j - 1] == words2[words2.count - j - 1] {
            j += 1
        }
        return i + j == min(words1.count, words2.count)
    }
}
// @lc code=end

func main() {
    var sentence1: String
    var sentence2: String
    var res: Bool

    /**
     输入：sentence1 = "My name is Haley", sentence2 = "My Haley"
     输出：true
     解释：可以往 sentence2 中 "My" 和 "Haley" 之间插入 "name is" ，得到 sentence1 。
     */
    sentence1 = "My name is Haley"
    sentence2 = "My Haley"
    res = true
    assert(res == Solution().areSentencesSimilar(sentence1, sentence2))
    
    /**
     输入：sentence1 = "of", sentence2 = "A lot of words"
     输出：false
     解释：没法往这两个句子中的一个句子只插入一个句子就得到另一个句子。
     */
    sentence1 = "of"
    sentence2 = "A lot of words"
    res = false
    assert(res == Solution().areSentencesSimilar(sentence1, sentence2))
    
    /**
     输入：sentence1 = "Eating right now", sentence2 = "Eating"
     输出：true
     解释：可以往 sentence2 的结尾插入 "right now" 得到 sentence1 。
     */
    sentence1 = "Eating right now"
    sentence2 = "Eating"
    res = true
    assert(res == Solution().areSentencesSimilar(sentence1, sentence2))
    
    /**
     输入：sentence1 = "Luky", sentence2 = "Lucccky"
     输出：false
     */
    sentence1 = "Luky"
    sentence2 = "Lucccky"
    res = false
    assert(res == Solution().areSentencesSimilar(sentence1, sentence2))
}
