/*
 * @lc app=leetcode.cn id=440 lang=swift
 *
 * [440] 字典序的第K小数字
 */

import Darwin

// @lc code=start
class Solution {
    func findKthNumber(_ n: Int, _ k: Int) -> Int {
        var ans = 1
        var kk = k
        while kk > 1 {
            let cnt = getCnts(ans, n)
            if cnt < kk {
                kk -= cnt
                ans += 1
            } else {
                kk -= 1
                ans *= 10
            }
        }
        return ans
    }

    func getCnts(_ x: Int, _ limit: Int) -> Int {
        let a = String(x), b = String(limit)
        let k = b.count - a.count
        var ans = 0, u = Int(b.prefix(a.count)) ?? 0
        for i in 0..<k {
            ans += Int(pow(10, Float(i)))
        }
        if u > x {
            ans += Int(pow(10, Float(k)))
        } else if u == x {
            ans += limit - x * Int(pow(10, Float(k))) + 1
        }
        return ans
    }
}
// @lc code=end


func main() {
    var n: Int
    var k: Int
    var res: Int
    
    /**
     输入: n = 13, k = 2
     输出: 10
     解释: 字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]，所以第二小的数字是 10。
     */
    n = 13
    k = 2
    res = 10
    assert(res == Solution().findKthNumber(n, k))
    
    /**
     输入: n = 1, k = 1
     输出: 1
     */
    n = 1
    k = 1
    res = 1
    assert(res == Solution().findKthNumber(n, k))
}
