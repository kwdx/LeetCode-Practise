/*
 * @lc app=leetcode.cn id=198 lang=swift
 *
 * [198] 打家劫舍
 */

import Foundation

// @lc code=start
class Solution {
    func rob(_ nums: [Int]) -> Int {
        var first = 0
        var second = 0
        for num in nums {
            let tmp = second
            second = max(first + num, second)
            first = tmp
        }
        return max(first, second)
    }
}
// @lc code=end

func main() {
    var nums: [Int] = []
    var res: Int = 0

    /**
     输入：[1,2,3,1]
     输出：4
     解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
          偷窃到的最高金额 = 1 + 3 = 4 。
     */
    nums = [1,2,3,1]
    res = 4
    assert(res == Solution().rob(nums))

    /**
     输入：[2,7,9,3,1]
     输出：12
     解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
          偷窃到的最高金额 = 2 + 9 + 1 = 12 。
     */
    nums = [2,7,9,3,1]
    res = 12
    assert(res == Solution().rob(nums))
}
