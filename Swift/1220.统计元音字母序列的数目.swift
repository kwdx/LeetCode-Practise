/*
 * @lc app=leetcode.cn id=1220 lang=swift
 *
 * [1220] 统计元音字母序列的数目
 */

// @lc code=start
class Solution {
    private let MOD = Int(1e9+7)
    
    func countVowelPermutation(_ n: Int) -> Int {
        var f: [[Int]] = .init(repeating: .init(repeating: 1, count: 5), count: n)
        for i in 1..<n {
            f[i][0] = f[i - 1][1] % MOD
            f[i][1] = (f[i - 1][0] + f[i - 1][2]) % MOD
            f[i][2] = (f[i - 1][0] + f[i - 1][1] + f[i - 1][3] + f[i - 1][4]) % MOD
            f[i][3] = (f[i - 1][2] + f[i - 1][4]) % MOD
            f[i][4] = f[i - 1][0] % MOD
        }
        return f[n - 1].reduce(0) { ($0 + $1) % MOD}
    }
}
// @lc code=end

func main() {
    var n: Int
    var res: Int
    
    /**
     输入：n = 1
     输出：5
     解释：所有可能的字符串分别是："a", "e", "i" , "o" 和 "u"。
     */
    n = 1
    res = 5
    assert(res == Solution().countVowelPermutation(n))
    
    /**
     输入：n = 2
     输出：10
     解释：所有可能的字符串分别是："ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" 和 "ua"。
     */
    n = 2
    res = 10
    assert(res == Solution().countVowelPermutation(n))
    
    /**
     输入：n = 5
     输出：68
     */
    n = 5
    res = 68
    assert(res == Solution().countVowelPermutation(n))
}
