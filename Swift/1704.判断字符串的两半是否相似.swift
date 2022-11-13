/*
 * @lc app=leetcode.cn id=1704 lang=swift
 *
 * [1704] 判断字符串的两半是否相似
 */

// @lc code=start
class Solution {
    func halvesAreAlike(_ s: String) -> Bool {
        let chars = Array(s)
        var a = 0
        var b = 0
        let mid = chars.count >> 1
        for i in 0..<chars.count {
            switch chars[i].lowercased() {
            case "a", "e", "i", "o", "u":
                if i < mid {
                    a += 1
                } else {
                    b += 1
                }
            default:
                break
            }
        }
        return a == b
    }
}
// @lc code=end

func main() {
    var s: String
    var res: Bool
    
    /**
     输入：s = "book"
     输出：true
     解释：a = "bo" 且 b = "ok" 。a 中有 1 个元音，b 也有 1 个元音。所以，a 和 b 相似。
     */
    s = "book"
    res = true
    assert(res == Solution().halvesAreAlike(s))
    
    /**
     输入：s = "textbook"
     输出：false
     解释：a = "text" 且 b = "book" 。a 中有 1 个元音，b 中有 2 个元音。因此，a 和 b 不相似。
     注意，元音 o 在 b 中出现两次，记为 2 个。
     */
    s = "textbook"
    res = false
    assert(res == Solution().halvesAreAlike(s))
}
