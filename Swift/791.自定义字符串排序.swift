/*
 * @lc app=leetcode.cn id=791 lang=swift
 *
 * [791] 自定义字符串排序
 */

// @lc code=start
class Solution {
    func customSortString(_ order: String, _ s: String) -> String {
        var ans = ""
        var cnts = [Int](repeating: 0, count: 26)
        for c in s {
            cnts[Int(c.asciiValue!) - 97] += 1
        }
        for c in order {
            let idx = Int(c.asciiValue! - 97)
            let cnt = cnts[idx]
            ans += String(repeating: c, count: cnt)
            cnts[idx] = 0
        }
        for i in 0..<26 {
            if cnts[i] > 0 {
                let c = Character(UnicodeScalar(97 + i)!)
                ans += String(repeating: c, count: cnts[i])
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var order: String
    var s: String
    var res: String
    
    /**
     输入: order = "cba", s = "abcd"
     输出: "cbad"
     解释:
     “a”、“b”、“c”是按顺序出现的，所以“a”、“b”、“c”的顺序应该是“c”、“b”、“a”。
     因为“d”不是按顺序出现的，所以它可以在返回的字符串中的任何位置。“dcba”、“cdba”、“cbda”也是有效的输出。
     */
    order = "cba"
    s = "abcd"
    res = "cbad"
    assert(res == Solution().customSortString(order, s))
    
    /**
     输入: order = "cbafg", s = "abcd"
     输出: "cbad"
     */
    order = "cbafg"
    s = "abcd"
    res = "cbad"
    assert(res == Solution().customSortString(order, s))
}
