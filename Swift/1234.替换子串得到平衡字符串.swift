/*
 * @lc app=leetcode.cn id=1234 lang=swift
 *
 * [1234] 替换子串得到平衡字符串
 */

// @lc code=start
class Solution {
    func balancedString(_ s: String) -> Int {
        var cnt = [Int](repeating: 0, count: 26)
        let s = Array(s)
        let idx: (Character) -> Int = { Int($0.asciiValue! - 65) }
        for c in s {
            cnt[idx(c)] += 1
        }
        
        let partial = s.count / 4
        var ans = s.count
        
        let check: () -> Bool = {
            if cnt[idx("Q")] > partial || cnt[idx("W")] > partial || cnt[idx("E")] > partial || cnt[idx("R")] > partial {
                return false
            }
            return true
        }
        if check() {
            return 0
        }

        var r = 0
        for l in 0..<s.count {
            while r < s.count && !check() {
                cnt[idx(s[r])] -= 1
                r += 1
            }
            if !check() {
                break
            }
            ans = min(ans, r - l)
            cnt[idx(s[l])] += 1
        }
        return ans
    }
}
// @lc code=end

func main() {
    var s: String
    var res: Int
    
    /**
     输入：s = "QWER"
     输出：0
     解释：s 已经是平衡的了。
     */
    s = "QWER"
    res = 0
    assert(res == Solution().balancedString(s))
    
    /**
     输入：s = "QQWE"
     输出：1
     解释：我们需要把一个 'Q' 替换成 'R'，这样得到的 "RQWE" (或 "QRWE") 是平衡的。
     */
    s = "QQWE"
    res = 1
    assert(res == Solution().balancedString(s))
    
    /**
     输入：s = "QQQW"
     输出：2
     解释：我们可以把前面的 "QQ" 替换成 "ER"。
     */
    s = "QQQW"
    res = 2
    assert(res == Solution().balancedString(s))
    
    /**
     输入：s = "QQQQ"
     输出：3
     解释：我们可以替换后 3 个 'Q'，使 s = "QWER"。
     */
    s = "QQQQ"
    res = 3
    assert(res == Solution().balancedString(s))
}
