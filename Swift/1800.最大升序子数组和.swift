/*
 * @lc app=leetcode.cn id=1800 lang=swift
 *
 * [1800] 最大升序子数组和
 */

// @lc code=start
class Solution {
    func maxAscendingSum(_ nums: [Int]) -> Int {
        guard nums.count > 1 else {
            return nums[0]
        }
        var ans = nums[0]
        var cur = nums[0]
        for i in 1..<nums.count {
            if nums[i] > nums[i - 1] {
                cur += nums[i]
            } else {
                cur = nums[i]
            }
            ans = max(ans, cur)
        }
        return ans
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: Int
    
    /**
     输入：nums = [10,20,30,5,10,50]
     输出：65
     解释：[5,10,50] 是元素和最大的升序子数组，最大元素和为 65 。
     */
    nums = [10,20,30,5,10,50]
    res = 65
    assert(res == Solution().maxAscendingSum(nums))
    
    /**
     输入：nums = [10,20,30,40,50]
     输出：150
     解释：[10,20,30,40,50] 是元素和最大的升序子数组，最大元素和为 150 。
     */
    nums = [10,20,30,40,50]
    res = 150
    assert(res == Solution().maxAscendingSum(nums))
    
    /**
     输入：nums = [12,17,15,13,10,11,12]
     输出：33
     解释：[10,11,12] 是元素和最大的升序子数组，最大元素和为 33 。
     */
    nums = [12,17,15,13,10,11,12]
    res = 33
    assert(res == Solution().maxAscendingSum(nums))
    
    /**
     输入：nums = [100,10,1]
     输出：100
     */
    nums = [100,10,1]
    res = 100
    assert(res == Solution().maxAscendingSum(nums))
}
