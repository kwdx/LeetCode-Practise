/*
 * @lc app=leetcode.cn id=764 lang=swift
 *
 * [764] 最大加号标志
 */

// @lc code=start
class Solution {
    func orderOfLargestPlusSign(_ n: Int, _ mines: [[Int]]) -> Int {
        var dp = [[Int]](repeating: [Int](repeating: n, count: n), count: n)
        let banned = Set<Int>(mines.map { $0[0] * n + $0[1] })
        
        var ans = 0
        
        for i in 0..<n {
            var count = 0
            // left
            for j in 0..<n {
                if banned.contains(i * n + j) {
                    count = 0
                } else {
                    count += 1
                }
                dp[i][j] = min(dp[i][j], count)
            }
            count = 0
            // right
            for j in (0..<n).reversed() {
                if banned.contains(i * n + j) {
                    count = 0
                } else {
                    count += 1
                }
                dp[i][j] = min(dp[i][j], count)
            }
        }
        for i in 0..<n {
            var count = 0
            // top
            for j in 0..<n {
                if banned.contains(j * n + i) {
                    count = 0
                } else {
                    count += 1
                }
                dp[j][i] = min(dp[j][i], count)
            }
            count = 0
            // right
            for j in (0..<n).reversed() {
                if banned.contains(j * n + i) {
                    count = 0
                } else {
                    count += 1
                }
                dp[j][i] = min(dp[j][i], count)
                ans = max(ans, dp[j][i])
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var n: Int
    var mines: [[Int]]
    var res: Int
    
    /**
     输入: n = 5, mines = [[4, 2]]
     输出: 2
     解释: 在上面的网格中，最大加号标志的阶只能是2。一个标志已在图中标出。
     */
    n = 5
    mines = [[4, 2]]
    res = 2
    assert(res == Solution().orderOfLargestPlusSign(n, mines))
    
    /**
     输入: n = 1, mines = [[0, 0]]
     输出: 0
     解释: 没有加号标志，返回 0 。
     */
    n = 1
    mines = [[0, 0]]
    res = 0
    assert(res == Solution().orderOfLargestPlusSign(n, mines))
}
