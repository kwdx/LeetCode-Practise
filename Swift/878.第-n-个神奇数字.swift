/*
 * @lc app=leetcode.cn id=878 lang=swift
 *
 * [878] 第 N 个神奇数字
 */

// @lc code=start
class Solution {
    func nthMagicalNumber(_ n: Int, _ a: Int, _ b: Int) -> Int {
        var l = min(a, b)
        var r = n * l
        let c = lcm(a, b)
        while l <= r {
            let mid = (l + r) / 2
            let cnt = mid / a + mid / b - mid / c
            if cnt >= n {
                r = mid - 1
            } else {
                l = mid + 1
            }
        }
        return (r + 1) % 1000000007
    }
    
    func gcd(_ a: Int, _ b: Int) -> Int {
        if a % b == 0 {
            return b
        }
        return gcd(b, a % b)
    }
    
    func lcm(_ a: Int, _ b: Int) -> Int {
        return a * b / gcd(a, b)
    }
}
// @lc code=end

func main() {
    var n: Int
    var a: Int
    var b: Int
    var res: Int
    
    /**
     输入：n = 1, a = 2, b = 3
     输出：2
     */
    n = 1
    a = 2
    b = 3
    res = 2
    assert(res == Solution().nthMagicalNumber(n, a, b))
    
    /**
     输入：n = 4, a = 2, b = 3
     输出：6
     */
    n = 4
    a = 2
    b = 3
    res = 6
    assert(res == Solution().nthMagicalNumber(n, a, b))
}
