/*
 * @lc app=leetcode.cn id=808 lang=swift
 *
 * [808] 分汤
 */

import Darwin

// @lc code=start
class Solution {
    var memo: [[Double]] = []
    
    func soupServings(_ n: Int) -> Double {
        let n: Int = Int(ceil(Double(n) / 25.0))
        if n >= 179 {
            return 1
        }
        memo = [[Double]](repeating: [Double](repeating: 0, count: n + 1), count: n + 1)
        return dfs(n, n)
    }
    
    func dfs(_ a: Int, _ b: Int) -> Double {
        if a <= 0 && b <= 0 {
            return 0.5
        } else if a <= 0 {
            return 1
        } else if b <= 0 {
            return 0
        }
        if memo[a][b] > 0 {
            return memo[a][b]
        }
        memo[a][b] = 0.25 * (dfs(a - 4, b) + dfs(a - 3, b - 1) +
                             dfs(a - 2, b - 2) + dfs(a - 1, b - 3));
        return memo[a][b]
    }
}
// @lc code=end

func main() {
    var n: Int
    var res: Double
    
    /**
     输入: n = 50
     输出: 0.62500
     解释:如果我们选择前两个操作，A 首先将变为空。
     对于第三个操作，A 和 B 会同时变为空。
     对于第四个操作，B 首先将变为空。
     所以 A 变为空的总概率加上 A 和 B 同时变为空的概率的一半是 0.25 *(1 + 1 + 0.5 + 0)= 0.625。
     */
    n = 50
    res = 0.62500
    assert(res == Solution().soupServings(n))
    
    /**
     输入: n = 100
     输出: 0.71875
     */
    n = 100
    res = 0.71875
    assert(res == Solution().soupServings(n))
}
