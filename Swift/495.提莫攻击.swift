/*
 * @lc app=leetcode.cn id=495 lang=swift
 *
 * [495] 提莫攻击
 */

// @lc code=start
class Solution {
    func findPoisonedDuration(_ timeSeries: [Int], _ duration: Int) -> Int {
        var ans = 0
        var pre = -1
        for series in timeSeries {
            let end = series + duration - 1
            ans += pre < series ? duration : (end - pre)
            pre = end
        }
        return ans
    }
}
// @lc code=end


func main() {
    var timeSeries: [Int]
    var duration: Int
    var res: Int
    
    /**
     输入：timeSeries = [1,4], duration = 2
     输出：4
     解释：提莫攻击对艾希的影响如下：
     - 第 1 秒，提莫攻击艾希并使其立即中毒。中毒状态会维持 2 秒，即第 1 秒和第 2 秒。
     - 第 4 秒，提莫再次攻击艾希，艾希中毒状态又持续 2 秒，即第 4 秒和第 5 秒。
     艾希在第 1、2、4、5 秒处于中毒状态，所以总中毒秒数是 4 。
     */
    timeSeries = [1,4]
    duration = 2
    res = 4
    assert(res == Solution().findPoisonedDuration(timeSeries, duration))
    
    /**
     输入：timeSeries = [1,2], duration = 2
     输出：3
     解释：提莫攻击对艾希的影响如下：
     - 第 1 秒，提莫攻击艾希并使其立即中毒。中毒状态会维持 2 秒，即第 1 秒和第 2 秒。
     - 第 2 秒，提莫再次攻击艾希，并重置中毒计时器，艾希中毒状态需要持续 2 秒，即第 2 秒和第 3 秒。
     艾希在第 1、2、3 秒处于中毒状态，所以总中毒秒数是 3 。
     */
    timeSeries = [1,2]
    duration = 2
    res = 3
    assert(res == Solution().findPoisonedDuration(timeSeries, duration))
    
    /**
     输入：timeSeries = [1,2,3,4,5,6,7,8,9], duration = 10
     输出：18
     */
    timeSeries = [1,2,3,4,5,6,7,8,9]
    duration = 10
    res = 18
    assert(res == Solution().findPoisonedDuration(timeSeries, duration))
}
