/*
 * @lc app=leetcode.cn id=get-kth-magic-number-lcci lang=swift
 *
 * [面试题] 17.09. 第 k 个数
 */

// @lc code=start
class Solution {
    func getKthMagicNumber(_ k: Int) -> Int {
        guard k > 1 else { return 1 }
        var dp = [Int](repeating: 0, count: k + 1)
        dp[1] = 1
        var p3 = 1, p5 = 1, p7 = 1
        for i in 2...k {
            let num3 = dp[p3] * 3
            let num5 = dp[p5] * 5
            let num7 = dp[p7] * 7
            dp[i] = min(num3, num5, num7)
            if dp[i] == num3 {
                p3 += 1
            }
            if dp[i] == num5 {
                p5 += 1
            }
            if dp[i] == num7 {
                p7 += 1
            }
        }
        return dp[k]
    }
}
// @lc code=end

func main() {
    var k: Int
    var res: Int
    
    /**
     输入: k = 5
     输出: 9
     */
    k = 5
    res = 9
    assert(res == Solution().getKthMagicNumber(k))
}
