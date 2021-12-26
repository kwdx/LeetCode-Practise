/*
 * @lc app=leetcode.cn id=1078 lang=swift
 *
 * [1078] Bigram 分词
 */

import Darwin

// @lc code=start
class Solution {
    func findOcurrences(_ text: String, _ first: String, _ second: String) -> [String] {
        var word = "", word1 = "", word2 = ""
        var ans: [String] = text.split(separator: " ")
            .map { String($0) }
            .filter {
                var match = false
                if word1 == first && word2 == second {
                    match = true
                }
                word1 = word2
                word2 = $0
                return match
            }
        if word1 == first && word2 == second && !word.isEmpty {
            ans.append(word)
        }
        return ans
    }
}
// @lc code=end

func main() {
    var text: String
    var first: String
    var second: String
    var res: [String]
    
    /**
     输入：text = "alice is a good girl she is a good student", first = "a", second = "good"
     输出：["girl","student"]
     */
    text = "alice is a good girl she is a good student"
    first = "a"
    second = "good"
    res = ["girl","student"]
    assert(res == Solution().findOcurrences(text, first, second))

    /**
     输入：text = "we will we will rock you", first = "we", second = "will"
     输出：["we","rock"]
     */
    text = "we will we will rock you"
    first = "we"
    second = "will"
    res = ["we","rock"]
    assert(res == Solution().findOcurrences(text, first, second))
    
    /**
     输入：text = "jkypmsxd jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa kcyxdfnoa jkypmsxd kcyxdfnoa", first = "kcyxdfnoa", second = "jkypmsxd"
     输出：["kcyxdfnoa","kcyxdfnoa","kcyxdfnoa"]
     */
    text = "jkypmsxd jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa kcyxdfnoa jkypmsxd kcyxdfnoa"
    first = "kcyxdfnoa"
    second = "jkypmsxd"
    res = ["kcyxdfnoa","kcyxdfnoa","kcyxdfnoa"]
    assert(res == Solution().findOcurrences(text, first, second))
    
    /**
     输入：text = "we we we we will rock you", first = "we", second = "we"
     输出：["we","we","will"]
     */
    text = "we we we we will rock you"
    first = "we"
    second = "we"
    res = ["we","we","will"]
    assert(res == Solution().findOcurrences(text, first, second))
    
    /**
     输入：text = "ypkk lnlqhmaohv lnlqhmaohv lnlqhmaohv ypkk ypkk ypkk ypkk ypkk ypkk lnlqhmaohv lnlqhmaohv lnlqhmaohv lnlqhmaohv ypkk ypkk ypkk lnlqhmaohv lnlqhmaohv ypkk", first = "lnlqhmaohv", second = "ypkk"
     输出：["ypkk","ypkk"]
     */
    text = "ypkk lnlqhmaohv lnlqhmaohv lnlqhmaohv ypkk ypkk ypkk ypkk ypkk ypkk lnlqhmaohv lnlqhmaohv lnlqhmaohv lnlqhmaohv ypkk ypkk ypkk lnlqhmaohv lnlqhmaohv ypkk"
    first = "lnlqhmaohv"
    second = "ypkk"
    res = ["ypkk","ypkk"]
    assert(res == Solution().findOcurrences(text, first, second))
}
