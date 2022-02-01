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
    
}
