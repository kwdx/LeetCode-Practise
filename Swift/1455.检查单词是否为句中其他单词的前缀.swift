/*
 * @lc app=leetcode.cn id=1455 lang=swift
 *
 * [1455] 检查单词是否为句中其他单词的前缀
 */

// @lc code=start
class Solution {
    func isPrefixOfWord(_ sentence: String, _ searchWord: String) -> Int {
        return sentence.components(separatedBy: " ")
            .firstIndex(where: { $0.hasPrefix(searchWord) })
            .map { $0 + 1 } ?? -1
    }
}
// @lc code=end

func main() {
    var sentence: String
    var searchWord: String
    var res: Int
    
    /**
     输入：sentence = "i love eating burger", searchWord = "burg"
     输出：4
     解释："burg" 是 "burger" 的前缀，而 "burger" 是句子中第 4 个单词。
     */
    sentence = "i love eating burger"
    searchWord = "burg"
    res = 4
    assert(res == Solution().isPrefixOfWord(sentence, searchWord))
    
    /**
     输入：sentence = "this problem is an easy problem", searchWord = "pro"
     输出：2
     解释："pro" 是 "problem" 的前缀，而 "problem" 是句子中第 2 个也是第 6 个单词，但是应该返回最小下标 2 。
     */
    sentence = "this problem is an easy problem"
    searchWord = "pro"
    res = 2
    assert(res == Solution().isPrefixOfWord(sentence, searchWord))
    
    /**
     输入：sentence = "i am tired", searchWord = "you"
     输出：-1
     解释："you" 不是句子中任何单词的前缀。
     */
    sentence = "i am tired"
    searchWord = "you"
    res = -1
    assert(res == Solution().isPrefixOfWord(sentence, searchWord))
}
