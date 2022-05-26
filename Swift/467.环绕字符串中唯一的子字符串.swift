/*
 * @lc app=leetcode.cn id=467 lang=swift
 *
 * [467] 环绕字符串中唯一的子字符串
 */

// @lc code=start
class Solution {
    func findSubstringInWraproundString(_ p: String) -> Int {
        var dp = [Int](repeating: 0, count: 26)
        var k = 0
        let aChar = Character("a").asciiValue!
        let chars = p.map { Int($0.asciiValue! -  aChar) }
        for i in 0..<chars.count {
            if i > 0 && (chars[i] - chars[i - 1] + 26) % 26 == 1 {
                // 字符相差 1 或则 -25
                k += 1
            } else {
                k = 1
            }
            dp[chars[i]] = max(dp[chars[i]], k)
        }
        return dp.reduce(0, +)
    }
}
// @lc code=end

func main() {
    var p: String
    var res: Int
    
    /**
     输入: p = "a"
     输出: 1
     解释: 字符串 s 中只有一个"a"子字符。
     */
    p = "a"
    res = 1
    assert(res == Solution().findSubstringInWraproundString(p))
    
    /**
     输入: p = "cac"
     输出: 2
     解释: 字符串 s 中的字符串“cac”只有两个子串“a”、“c”。.
     */
    p = "cac"
    res = 2
    assert(res == Solution().findSubstringInWraproundString(p))
    
    /**
     输入: p = "zab"
     输出: 6
     解释: 在字符串 s 中有六个子串“z”、“a”、“b”、“za”、“ab”、“zab”。
     */
    p = "zab"
    res = 6
    assert(res == Solution().findSubstringInWraproundString(p))
}
