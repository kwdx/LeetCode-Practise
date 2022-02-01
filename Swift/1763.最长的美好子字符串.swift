/*
 * @lc app=leetcode.cn id=1763 lang=swift
 *
 * [1763] 最长的美好子字符串
 */

// @lc code=start
class Solution {
    func longestNiceSubstring(_ s: String) -> String {
        let n = s.count
        var idx = -1, len = 0
        let chars = s.map { $0 }
        for i in 0..<n {
            var a = 0, A = 0
            for j in i..<n {
                let c = chars[j]
                switch c {
                case "a"..."z":
                    a |= (1 << (c.asciiValue! - 97))
                case "A"..."Z":
                    A |= (1 << (c.asciiValue! - 65))
                default:
                    break
                }
                if a == A && j - i + 1 > len {
                    idx = i
                    len = j - i + 1
                }
            }
        }
        return idx == -1 ? "" : String(chars[idx..<idx+len])
    }
}
// @lc code=end

func main() {
    var s: String
    var res: String
    
    /**
     输入：s = "YazaAay"
     输出："aAa"
     解释："aAa" 是一个美好字符串，因为这个子串中仅含一种字母，其小写形式 'a' 和大写形式 'A' 也同时出现了。
     "aAa" 是最长的美好子字符串。
     */
    s = "YazaAay"
    res = "aAa"
    assert(res == Solution().longestNiceSubstring(s))
    
    /**
     输入：s = "Bb"
     输出："Bb"
     解释："Bb" 是美好字符串，因为 'B' 和 'b' 都出现了。整个字符串也是原字符串的子字符串。
     */
    s = "Bb"
    res = "Bb"
    assert(res == Solution().longestNiceSubstring(s))
    
    /**
     输入：s = "c"
     输出：""
     解释：没有美好子字符串。
     */
    s = "c"
    res = ""
    assert(res == Solution().longestNiceSubstring(s))
    
    /**
     输入：s = "dDzeE"
     输出："dD"
     解释："dD" 和 "eE" 都是最长美好子字符串。
     由于有多个美好子字符串，返回 "dD" ，因为它出现得最早。
     */
    s = "dDzeE"
    res = "dD"
    assert(res == Solution().longestNiceSubstring(s))
}
