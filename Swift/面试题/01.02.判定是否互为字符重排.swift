/*
 * @lc app=leetcode.cn id=check-permutation-lcci lang=swift
 *
 * [面试题] 01.02. 判定是否互为字符重排
 */

// @lc code=start
class Solution {
    func CheckPermutation(_ s1: String, _ s2: String) -> Bool {
        guard s1.count == s2.count else { return false }
        
        var chars: [Character: Int] = [:]
        for c in s1 {
            chars[c] = 1 + (chars[c] ?? 0)
        }
        for c in s2 {
            let val = chars[c] ?? 0
            if val < 1 {
                return false
            }
            chars[c] = val - 1
        }
        return true
    }
}
// @lc code=end

func main() {
    var s1: String
    var s2: String
    var res: Bool
    
    /**
     输入: s1 = "abc", s2 = "bca"
     输出: true
     */
    s1 = "abc"
    s2 = "bca"
    res = true
    assert(res == Solution().CheckPermutation(s1, s2))
    
    /**
     输入: s1 = "abc", s2 = "bad"
     输出: false
     */
    s1 = "abc"
    s2 = "bad"
    res = false
    assert(res == Solution().CheckPermutation(s1, s2))
}
