/*
 * @lc app=leetcode.cn id=1781 lang=swift
 *
 * [1781] 所有子字符串美丽值之和
 */

// @lc code=start
class Solution {
    func beautySum(_ s: String) -> Int {
        let s = s.map { Int($0.asciiValue!) - 97 }
        var ans = 0
        for i in 0..<s.count {
            var cnt = [Int](repeating: 0, count: 26)
            var maxFreq = 0
            var j = i
            while j < s.count {
                cnt[s[j]] += 1
                maxFreq = max(maxFreq, cnt[s[j]])
                var minFreq =  s.count
                for k in 0..<26 {
                    if cnt[k] > 0 {
                        minFreq = min(minFreq, cnt[k])
                    }
                }
                ans += maxFreq - minFreq
                j += 1
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
     输入：s = "aabcb"
     输出：5
     解释：美丽值不为零的字符串包括 ["aab","aabc","aabcb","abcb","bcb"] ，每一个字符串的美丽值都为 1 。
     */
    s = "aabcb"
    res = 5
    assert(res == Solution().beautySum(s))
    
    /**
     输入：s = "aabcbaa"
     输出：17
     */
    s = "aabcbaa"
    res = 17
    assert(res == Solution().beautySum(s))
}
