/*
 * @lc app=leetcode.cn id=2180 lang=swift
 *
 * [2180] 统计各位数字之和为偶数的整数个数
 */

// @lc code=start
class Solution {
    func countEven(_ num: Int) -> Int {
        var y = num / 10
        let x = num % 10
        var ans = y *  5
        var ySum = 0
        while y > 0 {
            ySum += y % 10
            y /= 10
        }
        if ySum % 2 == 0 {
            ans += x / 2 + 1
        } else {
            ans += (x + 1) / 2
        }
        return ans - 1
    }
}
// @lc code=end

func main() {
    var num: Int
    var res: Int
    
    /**
     输入：num = 4
     输出：2
     解释：
     只有 2 和 4 满足小于等于 4 且各位数字之和为偶数。
     */
    num = 4
    res = 2
    assert(res == Solution().countEven(num))
    
    /**
     输入：num = 30
     输出：14
     解释：
     只有 14 个整数满足小于等于 30 且各位数字之和为偶数，分别是：
     2、4、6、8、11、13、15、17、19、20、22、24、26 和 28 。
     */
    num = 30
    res = 14
    assert(res == Solution().countEven(num))
}
