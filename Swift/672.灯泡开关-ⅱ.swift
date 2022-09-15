/*
 * @lc app=leetcode.cn id=672 lang=swift
 *
 * [672] 灯泡开关 Ⅱ
 */

import Foundation

// @lc code=start
class Solution {
    func flipLights(_ n: Int, _ presses: Int) -> Int {
        var ans: Set<Int> = []
        for i in 0..<(1 << 4) {
            var pressArr = [Int](repeating: 0, count: 4)
            for j in 0..<4 {
                pressArr[j] = (i >> j) & 1
            }
            let sum = pressArr.reduce(0, +)
            if sum % 2 == presses % 2 && sum <= presses {
                var status = pressArr[0] ^ pressArr[1] ^ pressArr[3]
                if n >= 2 {
                    status |= (pressArr[0] ^ pressArr[1]) << 1
                }
                if n >= 3 {
                    status |= (pressArr[0] ^ pressArr[2]) << 2
                }
                if n >= 4 {
                    status |= (pressArr[0] ^ pressArr[1] ^ pressArr[3]) << 3
                }
                ans.insert(status)
            }
        }
        return ans.count
    }
}
// @lc code=end

func main() {
    var n: Int
    var presses: Int
    var res: Int
    
    /**
     输入：n = 1, presses = 1
     输出：2
     解释：状态可以是：
     - 按压开关 1 ，[关]
     - 按压开关 2 ，[开]
     */
    n = 1
    presses = 1
    res = 2
    assert(res == Solution().flipLights(n, presses))
    
    /**
     输入：n = 2, presses = 1
     输出：3
     解释：状态可以是：
     - 按压开关 1 ，[关, 关]
     - 按压开关 2 ，[开, 关]
     - 按压开关 3 ，[关, 开]
     */
    n = 2
    presses = 1
    res = 3
    assert(res == Solution().flipLights(n, presses))
    
    /**
     输入：n = 3, presses = 1
     输出：4
     解释：状态可以是：
     - 按压开关 1 ，[关, 关, 关]
     - 按压开关 2 ，[关, 开, 关]
     - 按压开关 3 ，[开, 关, 开]
     - 按压开关 4 ，[关, 开, 开]
     */
    n = 3
    presses = 1
    res = 4
    assert(res == Solution().flipLights(n, presses))
}
