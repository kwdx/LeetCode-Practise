/*
 * @lc app=leetcode.cn id=1413 lang=swift
 *
 * [1413] 逐步求和得到正数的最小值
 */

// @lc code=start
class Solution {
    func minStartValue(_ nums: [Int]) -> Int {
        var ans = 0
        var sum = 0
        for num in nums {
            sum += num
            ans = min(ans, sum)
        }
        return 1 - ans
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: Int
    
    /**
     输入：nums = [-3,2,-3,4,2]
     输出：5
     解释：如果你选择 startValue = 4，在第三次累加时，和小于 1 。
                     累加求和
                     startValue = 4 | startValue = 5 | nums
                       (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
                       (1 +2 ) = 3  | (2 +2 ) = 4    |   2
                       (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
                       (0 +4 ) = 4  | (1 +4 ) = 5    |   4
                       (4 +2 ) = 6  | (5 +2 ) = 7    |   2
     */
    nums = [-3,2,-3,4,2]
    res = 5
    assert(res == Solution().minStartValue(nums))
    
    /**
     输入：nums = [1,2]
     输出：1
     解释：最小的 startValue 需要是正数。
     */
    nums = [1,2]
    res = 1
    assert(res == Solution().minStartValue(nums))
    
    /**
     输入：nums = [1,-2,-3]
     输出：5
     */
    nums = [1,-2,-3]
    res = 5
    assert(res == Solution().minStartValue(nums))
}
