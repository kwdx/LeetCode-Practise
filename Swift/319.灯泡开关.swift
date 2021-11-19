/*
 * @lc app=leetcode.cn id=319 lang=swift
 *
 * [319] 灯泡开关
 */

import Darwin

// @lc code=start
class Solution {
    func bulbSwitch(_ n: Int) -> Int {
        return Int(sqrt(Double(n)))
    }
}
// @lc code=end

func main() {
    var n: Int
    var res: Int
    
    /**
     输入：n = 3
     输出：1
     解释：
     初始时, 灯泡状态 [关闭, 关闭, 关闭].
     第一轮后, 灯泡状态 [开启, 开启, 开启].
     第二轮后, 灯泡状态 [开启, 关闭, 开启].
     第三轮后, 灯泡状态 [开启, 关闭, 关闭].

     你应该返回 1，因为只有一个灯泡还亮着。
     */
    n = 3
    res = 1
    assert(res == Solution().bulbSwitch(n))
    
    /**
     输入：n = 0
     输出：0
     */
    n = 0
    res = 0
    assert(res == Solution().bulbSwitch(n))
    
    /**
     输入：n = 1
     输出：1
     */
    n = 1
    res = 1
    assert(res == Solution().bulbSwitch(n))
}
