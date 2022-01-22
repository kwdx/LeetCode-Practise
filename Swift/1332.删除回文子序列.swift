/*
 * @lc app=leetcode.cn id=1332 lang=swift
 *
 * [1332] 删除回文子序列
 */

// @lc code=start
class Solution {
    func removePalindromeSub(_ s: String) -> Int {
        s == String(s.reversed()) ? 1 : 2
    }
}
// @lc code=end

func main() {
    var s: String
    var res: Int
    
    /**
     输入：s = "ababa"
     输出：1
     解释：字符串本身就是回文序列，只需要删除一次。
     */
    s = "ababa"
    res = 1
    assert(res == Solution().removePalindromeSub(s))
    
    /**
     输入：s = "abb"
     输出：2
     解释："abb" -> "bb" -> "".
     先删除回文子序列 "a"，然后再删除 "bb"。
     */
    s = "abb"
    res = 2
    assert(res == Solution().removePalindromeSub(s))
    
    /**
     输入：s = "baabb"
     输出：2
     解释："baabb" -> "b" -> "".
     先删除回文子序列 "baab"，然后再删除 "b"。
     */
    s = "baabb"
    res = 2
    assert(res == Solution().removePalindromeSub(s))
}
