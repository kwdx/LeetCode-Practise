/*
 * @lc app=leetcode.cn id=809 lang=swift
 *
 * [809] 情感丰富的文字
 */

// @lc code=start
class Solution {
    func expressiveWords(_ s: String, _ words: [String]) -> Int {
        return words.filter { check(Array(s), Array($0)) }.count
    }
    
    func check(_ s: [String.Element], _ t: [String.Element]) -> Bool {
        if s.count < t.count {
            return false
        }
        var i = 0, j = 0
        while i < s.count && j < t.count {
            if s[i] != t[j] {
                return false
            }
            var k = i
            while k < s.count && s[k] == s[i] {
                k += 1
            }
            let c1 = k - i
            i = k
            k = j
            while k < t.count && t[k] == t[j] {
                k += 1
            }
            let c2 = k - j
            j = k
            if c1 < c2 || (c1 < 3 && c1 != c2) {
                return false
            }
        }
        return i == s.count && j == t.count
    }
}
// @lc code=end

func main() {
    var s: String
    var words: [String]
    var res: Int
    
    /**
     输入：
     S = "heeellooo"
     words = ["hello", "hi", "helo"]
     输出：1
     解释：
     我们能通过扩张 "hello" 的 "e" 和 "o" 来得到 "heeellooo"。
     我们不能通过扩张 "helo" 来得到 "heeellooo" 因为 "ll" 的长度小于 3 。
     */
    s = "heeellooo"
    words = ["hello", "hi", "helo"]
    res = 1
    assert(res == Solution().expressiveWords(s, words))
}
