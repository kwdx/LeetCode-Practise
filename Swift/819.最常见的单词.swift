/*
 * @lc app=leetcode.cn id=819 lang=swift
 *
 * [819] 最常见的单词
 */

// @lc code=start
class Solution {
    func mostCommonWord(_ paragraph: String, _ banned: [String]) -> String {
        let blacks = Set(banned.map { $0.lowercased() })
        
        var cnts = [String: Int]()
        var ans = ""
        
        let chars = Array(paragraph.lowercased())
        var word = ""
        var cnt = 0
        
        for char in chars {
            switch char {
            case "a"..."z":
                word.append(char)
            default:
                if !word.isEmpty && !blacks.contains(word) {
                    let val = (cnts[word] ?? 0) + 1
                    if val > cnt {
                        ans = word
                        cnt = val
                    }
                    cnts[word] = val
                }
                word = ""
            }
        }
        
        if !word.isEmpty && !blacks.contains(word) && (cnts[word] ?? 1 > cnt) {
            ans = word
        }

        return ans
    }
}
// @lc code=end

func main() {
    var paragraph: String
    var banned: [String]
    var res: String
    
    /**
     输入:
     paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
     banned = ["hit"]
     输出: "ball"
     解释:
     "hit" 出现了3次，但它是一个禁用的单词。
     "ball" 出现了2次 (同时没有其他单词出现2次)，所以它是段落里出现次数最多的，且不在禁用列表中的单词。
     注意，所有这些单词在段落里不区分大小写，标点符号需要忽略（即使是紧挨着单词也忽略， 比如 "ball,"），
     "hit"不是最终的答案，虽然它出现次数更多，但它在禁用单词列表中。
     */
    paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
    banned = ["hit"]
    res = "ball"
    assert(res == Solution().mostCommonWord(paragraph, banned))
    
    paragraph = "Bob. hIt, baLl"
    banned = ["bob", "hit"]
    res = "ball"
    assert(res == Solution().mostCommonWord(paragraph, banned))
    
    paragraph = "a."
    banned = []
    res = "a"
    assert(res == Solution().mostCommonWord(paragraph, banned))
}
