/*
 * @lc app=leetcode.cn id=1175 lang=swift
 *
 * [1175] 质数排列
 */

// @lc code=start
class Solution {
    private let MOD = Int(1e9 + 7)
    
    func numPrimeArrangements(_ n: Int) -> Int {
        if n == 1 {
            return 1
        }
        var primes = 0
        for i in 2...n {
            if isPrime(i) {
                primes += 1
            }
        }
        return factorial(primes) * factorial(n - primes) % MOD
    }
    
    private func isPrime(_ n: Int) -> Bool {
        if n == 1 {
            return false
        }
        var i = 2
        while i * i <= n {
            if n % i == 0 {
                return false
            }
            i += 1
        }
        return true
    }
    
    private func factorial(_ n: Int) -> Int {
        if n == 1 {
            return 1
        }
        var ans = 1
        for i in 2...n {
            ans *= i
            ans %= MOD
        }
        return ans
    }
}
// @lc code=end

func main() {
    var n: Int
    var res: Int
    
    /**
     输入：n = 5
     输出：12
     解释：举个例子，[1,2,5,4,3] 是一个有效的排列，但 [5,2,3,4,1] 不是，因为在第二种情况里质数 5 被错误地放在索引为 1 的位置上。
     */
    n = 5
    res = 12
    assert(res == Solution().numPrimeArrangements(n))
    
    /**
     输入：n = 100
     输出：682289015
     */
    n = 100
    res = 682289015
    assert(res == Solution().numPrimeArrangements(n))
}
