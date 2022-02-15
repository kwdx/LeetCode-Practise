/*
 * @lc app=leetcode.cn id=540 lang=swift
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
class Solution {
    func singleNonDuplicate(_ nums: [Int]) -> Int {
        for i in stride(from: 0, to: nums.count - 1, by: 2) {
            if nums[i] != nums[i + 1] {
                return nums[i]
            }
        }
        return nums.last!
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res = 0
    
    /**
     输入: nums = [1,1,2,3,3,4,4,8,8]
     输出: 2
     */
    nums = [1,1,2,3,3,4,4,8,8]
    res = 2
    assert(res == Solution().singleNonDuplicate(nums))
    
    /**
     输入: nums =  [3,3,7,7,10,11,11]
     输出: 10
     */
    nums = [3,3,7,7,10,11,11]
    res = 10
    assert(res == Solution().singleNonDuplicate(nums))
}
