/*
 * @lc app=leetcode.cn id=372 lang=swift
 *
 * [372] 超级次方
 */

// @lc code=start
class Solution {
    private let MOD = 1337
    private func dfs(_ a: Int, _ b: [Int], _ u: Int) -> Int {
        if u == -1 {
            return 1
        }
        return qpow(dfs(a, b, u - 1), 10) * qpow(a, b[u]) % MOD
    }
    
    private func qpow(_ a: Int, _ b: Int) -> Int {
        var ans = 1
        var a_ = a
        var b_ = b
        a_ %= MOD
        while b_ != 0 {
            if (b_ & 1) != 0 {
                ans = ans * a_ % MOD
            }
            a_ = a_ * a_ % MOD
            b_ >>= 1
        }
        return ans
    }
    
    func superPow(_ a: Int, _ b: [Int]) -> Int {
        return dfs(a, b, b.count - 1)
    }
}
// @lc code=end

func main() {
    var a: Int
    var b: [Int]
    var res: Int
    
    /**
     输入：a = 2, b = [3]
     输出：8
     */
    a = 2
    b = [3]
    res = 8
    assert(res == Solution().superPow(a, b))
    
    /**
     输入：a = 2, b = [1,0]
     输出：1024
     */
    a = 2
    b = [1,0]
    res = 1024
    assert(res == Solution().superPow(a, b))
    
    /**
     输入：a = 1, b = [4,3,3,8,5,2]
     输出：1
     */
    a = 1
    b = [4,3,3,8,5,2]
    res = 1
    assert(res == Solution().superPow(a, b))
    
    /**
     输入：a = 2147483647, b = [2,0,0]
     输出：1198
     */
    a = 2147483647
    b = [2,0,0]
    res = 1198
    assert(res == Solution().superPow(a, b))
}
