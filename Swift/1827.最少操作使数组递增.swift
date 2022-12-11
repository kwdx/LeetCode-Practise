/*
 * @lc app=leetcode.cn id=1827 lang=swift
 *
 * [1827] 最少操作使数组递增
 */

// @lc code=start
class Solution {
    func minOperations(_ nums: [Int]) -> Int {
        var ans = 0
        var pre = nums[0] - 1
        for num in nums {
            pre = max(pre + 1, num)
            ans += pre - num
        }
        return ans
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: Int
    
    /**
     输入：nums = [1,1,1]
     输出：3
     解释：你可以进行如下操作：
     1) 增加 nums[2] ，数组变为 [1,1,2] 。
     2) 增加 nums[1] ，数组变为 [1,2,2] 。
     3) 增加 nums[2] ，数组变为 [1,2,3] 。
     */
    nums = [1,1,1]
    res = 3
    assert(res == Solution().minOperations(nums))
    
    /**
     输入：nums = [1,5,2,4,1]
     输出：14
     */
    nums = [1,5,2,4,1]
    res = 14
    assert(res == Solution().minOperations(nums))
    
    /**
     输入：nums = [8]
     输出：0
     */
    nums = [8]
    res = 0
    assert(res == Solution().minOperations(nums))
}
