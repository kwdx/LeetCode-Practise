//
//  091.粉刷房子.swift
//  Swift_
//
//  Created by warden on 2022/6/25.
//

// @lc code=start
class Solution {
    func minCost(_ costs: [[Int]]) -> Int {
        var a = costs[0][0]
        var b = costs[0][1]
        var c = costs[0][2]
        for i in 1..<costs.count {
            let d = min(b, c) + costs[i][0]
            let e = min(a, c) + costs[i][1]
            let f = min(a, b) + costs[i][2]
            a = d
            b = e
            c = f
        }
        return min(a, b, c)
    }
}
// @lc code=end

func main() {
    var costs: [[Int]]
    var res: Int
    
    /**
     输入: costs = [[17,2,17],[16,16,5],[14,3,19]]
     输出: 10
     解释: 将 0 号房子粉刷成蓝色，1 号房子粉刷成绿色，2 号房子粉刷成蓝色。
          最少花费: 2 + 5 + 3 = 10。
     */
    costs = [[17,2,17],[16,16,5],[14,3,19]]
    res = 10
    assert(res == Solution().minCost(costs))
    
    /**
     输入: costs = [[7,6,2]]
     输出: 2
     */
    costs = [[7,6,2]]
    res = 2
    assert(res == Solution().minCost(costs))
}
