/*
 * @lc app=leetcode.cn id=790 lang=swift
 *
 * [790] 多米诺和托米诺平铺
 */

// @lc code=start
class Solution {
    let MOD = 1000000007
    func numTilings(_ n: Int) -> Int {
        if n == 1 {
            return 1
        }
        var f = [[Int]](repeating: [Int](repeating: 0, count: 4), count: 2)
        f[1][0] = 1
        f[1][1] = 1
        for i in 2...n {
            let a = i & 1
            let b = (i - 1) & 1
            f[a][0] = f[b][1]
            var cur = 0
            for j in 0..<4 {
                cur = (cur + f[b][j]) % MOD
            }
            f[a][1] = cur
            f[a][2] = (f[b][0] + f[b][3]) % MOD
            f[a][3] = (f[b][0] + f[b][2]) % MOD
        }
        return f[n & 1][1]
    }
}
// @lc code=end

func main() {
    var n: Int
    var res: Int
    
    /**
     输入: n = 3
     输出: 5
     解释: 五种不同的方法如上所示。
     */
    n = 3
    res = 5
    assert(res == Solution().numTilings(n))
    
    /**
     输入: n = 1
     输出: 1
     */
    n = 1
    res = 1
    assert(res == Solution().numTilings(n))
}
