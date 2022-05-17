/*
 * @lc app=leetcode.cn id=953 lang=swift
 *
 * [953] 验证外星语词典
 */

// @lc code=start
class Solution {
    func isAlienSorted(_ words: [String], _ order: String) -> Bool {
        var ord: [Int] = .init(repeating: 0, count: 26)
        let orders = order.map { Int($0.asciiValue!) - 97 }
        for i in 0..<26 {
            ord[orders[i]] = i
        }
        let sortedWords = words.sorted { a, b in
            let chars1 = Array(a)
            let chars2 = Array(b)
            var i = 0, j = 0
            while i < chars1.count && j < chars2.count {
                let c1 = Int(chars1[i].asciiValue!) - 97
                let c2 = Int(chars2[j].asciiValue!) - 97
                if c1 != c2 {
                    return ord[c1] < ord[c2]
                }
                i += 1
                j += 1
            }
            if i < chars1.count {
                return false
            }
            return true
        }
        for i in 0..<words.count {
            if sortedWords[i] != words[i] {
                return false
            }
        }
        return true
    }
}
// @lc code=end

func main() {
    var words: [String]
    var order: String
    var res: Bool
    
    /**
     输入：words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
     输出：true
     解释：在该语言的字母表中，'h' 位于 'l' 之前，所以单词序列是按字典序排列的。
     */
    words = ["hello","leetcode"]
    order = "hlabcdefgijkmnopqrstuvwxyz"
    res = true
    assert(res == Solution().isAlienSorted(words, order))
    
    /**
     输入：words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
     输出：false
     解释：在该语言的字母表中，'d' 位于 'l' 之后，那么 words[0] > words[1]，因此单词序列不是按字典序排列的。
     */
    words = ["word","world","row"]
    order = "worldabcefghijkmnpqstuvxyz"
    res = false
    assert(res == Solution().isAlienSorted(words, order))
    
    /**
     输入：words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
     输出：false
     解释：当前三个字符 "app" 匹配时，第二个字符串相对短一些，然后根据词典编纂规则 "apple" > "app"，因为 'l' > '∅'，其中 '∅' 是空白字符，定义为比任何其他字符都小（更多信息）。
     */
    words = ["apple","app"]
    order = "abcdefghijklmnopqrstuvwxyz"
    res = false
    assert(res == Solution().isAlienSorted(words, order))
}
