/*
 * @lc app=leetcode.cn id=828 lang=swift
 *
 * [828] 统计子串中的唯一字符
 */

// @lc code=start
class Solution {
    func uniqueLetterString(_ s: String) -> Int {
        var ans = 0
        let chars = Array(s)
        var index: [Character: [Int]] = [:]
        for (idx, char) in chars.enumerated() {
            index[char] = (index[char] ?? []) + [idx]
        }
        for arr in index.values {
            let arr =  [-1] + arr + [s.count]
            for i in 1..<(arr.count-1) {
                ans += (arr[i] - arr[i - 1]) * (arr[i + 1] - arr[i])
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var s: String
    var res: Int
    
    /**
     输入: s = "ABC"
     输出: 10
     解释: 所有可能的子串为："A","B","C","AB","BC" 和 "ABC"。
          其中，每一个子串都由独特字符构成。
          所以其长度总和为：1 + 1 + 1 + 2 + 2 + 3 = 10
     */
    s = "ABC"
    res = 10
    assert(res == Solution().uniqueLetterString(s))
    
    /**
     输入: s = "ABA"
     输出: 8
     解释: 除了 countUniqueChars("ABA") = 1 之外，其余与示例 1 相同。
     */
    s = "ABA"
    res = 8
    assert(res == Solution().uniqueLetterString(s))
    
    /**
     输入：s = "LEETCODE"
     输出：92
     */
    s = "LEETCODE"
    res = 92
    assert(res == Solution().uniqueLetterString(s))
}
