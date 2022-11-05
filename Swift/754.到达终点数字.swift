/*
 * @lc app=leetcode.cn id=754 lang=swift
 *
 * [754] 到达终点数字
 */

// @lc code=start
class Solution {
    func reachNumber(_ target: Int) -> Int {
        var target = abs(target)
        var ans = 0
        while target > 0 {
            ans += 1
            target -= ans
        }
        return target % 2 == 0 ? ans : ans + 1 + ans % 2
    }
}
// @lc code=end

func main() {
    var target: Int
    var res: Int
    
    /**
     输入: target = 2
     输出: 3
     解释:
     第一次移动，从 0 到 1 。
     第二次移动，从 1 到 -1 。
     第三次移动，从 -1 到 2 。
     */
    target = 2
    res = 3
    assert(res == Solution().reachNumber(target))
    
    /**
     输入: target = 3
     输出: 2
     解释:
     第一次移动，从 0 到 1 。
     第二次移动，从 1 到 3 。
     */
    target = 3
    res = 2
    assert(res == Solution().reachNumber(target))
}
