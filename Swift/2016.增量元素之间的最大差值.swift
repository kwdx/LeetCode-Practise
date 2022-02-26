/*
 * @lc app=leetcode.cn id=2016 lang=swift
 *
 * [2016] 增量元素之间的最大差值
 */

// @lc code=start
class Solution {
    func maximumDifference(_ nums: [Int]) -> Int {
        var ans = -1
        var val = nums[0]
        for i in 1..<nums.count {
            if nums[i] > val {
                ans = max(ans, nums[i] - val)
            }
            val = min(val, nums[i])
        }
        return ans
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: Int
    
    /**
     输入：nums = [7,1,5,4]
     输出：4
     解释：
     最大差值出现在 i = 1 且 j = 2 时，nums[j] - nums[i] = 5 - 1 = 4 。
     注意，尽管 i = 1 且 j = 0 时 ，nums[j] - nums[i] = 7 - 1 = 6 > 4 ，但 i > j 不满足题面要求，所以 6 不是有效的答案。
     */
    nums = [7,1,5,4]
    res = 4
    assert(res == Solution().maximumDifference(nums))

    /**
     输入：nums = [9,4,3,2]
     输出：-1
     解释：
     不存在同时满足 i < j 和 nums[i] < nums[j] 这两个条件的 i, j 组合。
     */
    nums = [9,4,3,2]
    res = -1
    assert(res == Solution().maximumDifference(nums))

    /**
     输入：nums = [1,5,2,10]
     输出：9
     解释：
     最大差值出现在 i = 0 且 j = 3 时，nums[j] - nums[i] = 10 - 1 = 9 。
     */
    nums = [1,5,2,10]
    res = 9
    assert(res == Solution().maximumDifference(nums))
}
