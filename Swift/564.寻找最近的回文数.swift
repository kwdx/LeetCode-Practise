/*
 * @lc app=leetcode.cn id=564 lang=swift
 *
 * [564] 寻找最近的回文数
 */

import Darwin

// @lc code=start
class Solution {
    func nearestPalindromic(_ s: String) -> String {
        let cur = Int(s)!
        
        let getNum: (Int, Bool) -> Int = {
            var chars = Array(String($0))
            var idx = $1 ? chars.count - 1 : chars.count - 2
            while idx >= 0 {
                chars.append(chars[idx])
                idx -= 1
            }
            return Int(String(chars))!
        }
        
        let pow_: (Int) -> Int = { Int(pow(10, Double($0))) }
        
        var bucket: Set<Int> = []
        bucket.insert(Int(pow_(s.count - 1)) - 1)
        bucket.insert(Int(pow_(s.count)) + 1)
        let t = Int(s[s.startIndex..<s.index(s.startIndex, offsetBy: (s.count + 1) / 2)])!
        for i in (t - 1)...(t + 1) {
            let temp = getNum(i, s.count % 2 == 0)
            if temp != cur {
                bucket.insert(temp)
            }
        }
        
        var ans = -1
        bucket.forEach {
            if ans == -1 {
                ans = $0
            } else if abs($0 - cur) < abs(ans - cur) {
                ans = $0
            } else if abs($0 - cur) == abs(ans - cur) && $0 < ans {
                ans = $0
            }
        }
        return String(ans)
    }
}
// @lc code=end

func main() {
    var n: String
    var res: String
    
    /**
     输入: n = "123"
     输出: "121"
     */
    n = "123"
    res = "121"
    assert(res == Solution().nearestPalindromic(n))
    
    /**
     输入: n = "1"
     输出: "0"
     解释: 0 和 2是最近的回文，但我们返回最小的，也就是 0。
     */
    n = "1"
    res = "0"
    assert(res == Solution().nearestPalindromic(n))
    
    n = "9"
    res = "8"
    assert(res == Solution().nearestPalindromic(n))
}
