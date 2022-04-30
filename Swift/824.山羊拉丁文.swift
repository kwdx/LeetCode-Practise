/*
 * @lc app=leetcode.cn id=824 lang=swift
 *
 * [824] 山羊拉丁文
 */

// @lc code=start
class Solution {
    func toGoatLatin(_ sentence: String) -> String {
        var ans: [String] = []
        let words = sentence.split(separator: " ")
        let vowel: Set<String> = ["a","e","i","o","u"]
        for i in 0..<words.count {
            let word = words[i]
            let first = String(word.first!)
            let end = "ma" + String(repeating: "a", count: i + 1)
            if vowel.contains(first.lowercased()) {
                // 元音开头
                ans.append(word + end)
            } else {
                // 辅音
                ans.append("\(word[word.index(after: word.startIndex)...])" + first + end)
            }
        }
        return ans.joined(separator: " ")
    }
}
// @lc code=end

func main() {
    var sentence: String
    var res: String
    
    /**
     输入：sentence = "I speak Goat Latin"
     输出："Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
     */
    sentence = "I speak Goat Latin"
    res = "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
    assert(res == Solution().toGoatLatin(sentence))
    
    /**
     输入：sentence = "The quick brown fox jumped over the lazy dog"
     输出："heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
     */
    sentence = "The quick brown fox jumped over the lazy dog"
    res = "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
    assert(res == Solution().toGoatLatin(sentence))
}
