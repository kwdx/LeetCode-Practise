/*
 * @lc app=leetcode.cn id=940 lang=swift
 *
 * [940] 不同的子序列 II
 */

// @lc code=start
class Solution {
    private static let mod = 100_000_000_7
    
    func distinctSubseqII(_ s: String) -> Int {
        var g = [Int](repeating: 0, count: 26)
        for c in s {
            var total = 1
            for val in g {
                total = (total + val) % Self.mod
            }
            g[Int(c.asciiValue! - 97)] = total
        }
        var ans = 0
        for val in g {
            ans = (ans + val) % Self.mod
        }
        return ans
    }
}
// @lc code=end

func main() {
    var s: String
    var res: Int
    
    /**
     输入：s = "abc"
     输出：7
     解释：7 个不同的子序列分别是 "a", "b", "c", "ab", "ac", "bc", 以及 "abc"。
     */
    s = "abc"
    res = 7
    assert(res == Solution().distinctSubseqII(s))
    
    /**
     输入：s = "aba"
     输出：6
     解释：6 个不同的子序列分别是 "a", "b", "ab", "ba", "aa" 以及 "aba"。
     */
    s = "aba"
    res = 6
    assert(res == Solution().distinctSubseqII(s))
    
    /**
     输入：s = "aaa"
     输出：3
     解释：3 个不同的子序列分别是 "a", "aa" 以及 "aaa"。
     */
    s = "aaa"
    res = 3
    assert(res == Solution().distinctSubseqII(s))
}
