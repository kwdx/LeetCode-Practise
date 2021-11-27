/*
 * @lc app=leetcode.cn id=423 lang=swift
 *
 * [423] 从英文中重建数字
 */

// @lc code=start
class Solution {
    func originalDigits(_ s: String) -> String {
        var c: [Character: Int] = [:]
        for ch in s {
            c[ch] = (c[ch] ?? 0) + 1
        }
        
        var cnt: [Int] = .init(repeating: 0, count: 10)
        
        cnt[0] = c["z"] ?? 0
        cnt[2] = c["w"] ?? 0
        cnt[4] = c["u"] ?? 0
        cnt[5] = (c["f"] ?? 0) - cnt[4]
        cnt[6] = (c["x"] ?? 0)
        cnt[7] = (c["s"] ?? 0) - cnt[6]
        cnt[8] = (c["g"] ?? 0)
        cnt[1] = (c["o"] ?? 0) - cnt[0] - cnt[2] - cnt[4]
        cnt[3] = (c["h"] ?? 0) - cnt[8]
        cnt[9] = (c["i"] ?? 0) - cnt[5] - cnt[6] - cnt[8]

        var ans: String = ""
        for i in 0..<10 {
            for _ in 0..<cnt[i] {
                ans += String(Character(UnicodeScalar(i + 48)!))
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var s: String
    var res: String
    
    /**
     输入：s = "owoztneoer"
     输出："012"
     */
    s = "owoztneoer"
    res = "012"
    assert(res == Solution().originalDigits(s))
    
    /**
     输入：s = "fviefuro"
     输出："45"
     */
    s = "fviefuro"
    res = "45"
    assert(res == Solution().originalDigits(s))
    
    /**
     输入：s = "nnei"
     输出："9"
     */
    s = "nnei"
    res = "9"
    assert(res == Solution().originalDigits(s))
}
