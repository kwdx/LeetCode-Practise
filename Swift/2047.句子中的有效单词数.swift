/*
 * @lc app=leetcode.cn id=2047 lang=swift
 *
 * [2047] 句子中的有效单词数
 */

// @lc code=start
class Solution {
    func countValidWords(_ sentence: String) -> Int {
        let marks = Set("!.,")
        return sentence
            .components(separatedBy: " ")
            .filter { token in
                if token.isEmpty {
                    return false
                }
                var hyphens = 0
                let characters = Array(token)
                for (i, c) in characters.enumerated() {
                    if c.isNumber {
                        return false
                    }
                    if c == "-" {
                        if (hyphens > 0 || i == 0 || i == token.count - 1)
                            || marks.contains(characters[i - 1])
                            || marks.contains(characters[i + 1]) {
                            return false
                        } else {
                            hyphens += 1
                        }
                    }
                    if marks.contains(c), i < characters.count - 1 {
                        return false
                    }
                }
                return true
            }
            .count
    }
}
// @lc code=end

func main() {
    var sentence: String
    var res: Int
    
    /**
     输入：sentence = "cat and  dog"
     输出：3
     解释：句子中的有效单词是 "cat"、"and" 和 "dog"
     */
    sentence = "cat and  dog"
    res = 3
    assert(res == Solution().countValidWords(sentence))
    
    /**
     输入：sentence = "!this  1-s b8d!"
     输出：0
     解释：句子中没有有效单词
     "!this" 不是有效单词，因为它以一个标点开头
     "1-s" 和 "b8d" 也不是有效单词，因为它们都包含数字
     */
    sentence = "!this  1-s b8d!"
    res = 0
    assert(res == Solution().countValidWords(sentence))
    
    /**
     输入：sentence = "alice and  bob are playing stone-game10"
     输出：5
     解释：句子中的有效单词是 "alice"、"and"、"bob"、"are" 和 "playing"
     "stone-game10" 不是有效单词，因为它含有数字
     */
    sentence = "alice and  bob are playing stone-game10"
    res = 5
    assert(res == Solution().countValidWords(sentence))
    
    /**
     输入：sentence = "he bought 2 pencils, 3 erasers, and 1  pencil-sharpener."
     输出：6
     解释：句子中的有效单词是 "he"、"bought"、"pencils,"、"erasers,"、"and" 和 "pencil-sharpener."
     */
    sentence = "he bought 2 pencils, 3 erasers, and 1  pencil-sharpener."
    res = 6
    assert(res == Solution().countValidWords(sentence))
}
