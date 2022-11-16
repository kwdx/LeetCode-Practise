/*
 * @lc app=leetcode.cn id=775 lang=swift
 *
 * [775] 全局倒置与局部倒置
 */

// @lc code=start
class Solution {
    func isIdealPermutation(_ nums: [Int]) -> Bool {
        var minSuff = nums[nums.count - 1]
        var i = nums.count - 3
        while i >= 0 {
            if nums[i] > minSuff {
                return false
            }
            minSuff = min(minSuff, nums[i + 1])
            i -= 1
        }
        return true
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: Bool
    
    /**
     输入：nums = [1,0,2]
     输出：true
     解释：有 1 个全局倒置，和 1 个局部倒置。
     */
    nums = [1,0,2]
    res = true
    assert(res == Solution().isIdealPermutation(nums))
    
    /**
     输入：nums = [1,2,0]
     输出：false
     解释：有 2 个全局倒置，和 1 个局部倒置。
     */
    nums = [1,2,0]
    res = false
    assert(res == Solution().isIdealPermutation(nums))
}
