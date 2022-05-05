/*
 * @lc app=leetcode.cn id=713 lang=swift
 *
 * [713] 乘积小于K的子数组
 */

// @lc code=start
class Solution {
    func numSubarrayProductLessThanK(_ nums: [Int], _ k: Int) -> Int {
        if k <= 1 {
            return 0
        }
        var ans = 0
        var j = 0, cur = 1
        for i in 0..<nums.count {
            cur *= nums[i]
            while cur >= k {
                cur /= nums[j]
                j += 1
            }
            ans += i - j + 1
        }
        return ans
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var k: Int
    var res: Int
    
    /**
     输入：nums = [10,5,2,6], k = 100
     输出：8
     解释：8 个乘积小于 100 的子数组分别为：[10]、[5]、[2],、[6]、[10,5]、[5,2]、[2,6]、[5,2,6]。
     需要注意的是 [10,5,2] 并不是乘积小于 100 的子数组。
     */
    nums = [10,5,2,6]
    k = 100
    res = 8
    assert(res == Solution().numSubarrayProductLessThanK(nums, k))
    
    /**
     输入：nums = [1,2,3], k = 0
     输出：0
     */
    nums = [1,2,3]
    k = 0
    res = 0
    assert(res == Solution().numSubarrayProductLessThanK(nums, k))
}
