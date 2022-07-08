/*
 * @lc app=leetcode.cn id=1217 lang=swift
 *
 * [1217] 玩筹码
 */

// @lc code=start
class Solution {
    func minCostToMoveChips(_ position: [Int]) -> Int {
        var a = 0
        var b = 0
        for val in position {
            if val % 2 == 1 {
                a += 1
            } else {
                b += 1
            }
        }
        return min(a, b)
    }
}
// @lc code=end

func main() {
    
}
