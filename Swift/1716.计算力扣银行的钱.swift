/*
 * @lc app=leetcode.cn id=1716 lang=swift
 *
 * [1716] 计算力扣银行的钱
 */

// @lc code=start
class Solution {
    func totalMoney(_ n: Int) -> Int {
        let weeks = n / 7
        let days = n % 7
        var monday = 1
        var ans = 0
        for _ in 0..<weeks {
            ans += (monday + monday + 6) * 7 / 2
            monday += 1
        }
        for _ in 0..<days {
            ans += monday
            monday += 1
        }
        return ans
    }
    func totalMoney1(_ n: Int) -> Int {
        (0..<n).reduce(0) { $0 + ($1 / 7 + 1) + $1 % 7 }
    }
}
// @lc code=end

func main() {
    var n: Int
    var res: Int
    
    /**
     输入：n = 4
     输出：10
     解释：第 4 天后，总额为 1 + 2 + 3 + 4 = 10 。
     */
    n = 4
    res = 10
    assert(res == Solution().totalMoney(n))
    
    /**
     输入：n = 10
     输出：37
     解释：第 10 天后，总额为 (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37 。注意到第二个星期一，Hercy 存入 2 块钱。
     */
    n = 10
    res = 37
    assert(res == Solution().totalMoney(n))
    
    /**
     输入：n = 20
     输出：96
     解释：第 20 天后，总额为 (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96 。
     */
    n = 20
    res = 96
    assert(res == Solution().totalMoney(n))
}
