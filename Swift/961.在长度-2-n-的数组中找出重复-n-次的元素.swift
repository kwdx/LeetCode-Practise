/*
 * @lc app=leetcode.cn id=961 lang=swift
 *
 * [961] 在长度 2N 的数组中找出重复 N 次的元素
 */

// @lc code=start
class Solution {
    func repeatedNTimes(_ nums: [Int]) -> Int {
        for i in 0..<nums.count {
            if i + 1 < nums.count && nums[i] == nums[i + 1] {
                return nums[i]
            }
            if i + 2 < nums.count && nums[i] == nums[i + 2] {
                return nums[i]
            }
            if i + 3 < nums.count && nums[i] == nums[i + 3] {
                return nums[i]
            }
        }
        return nums[0]
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: Int
    
    /**
     输入：nums = [1,2,3,3]
     输出：3
     */
    nums = [1,2,3,3]
    res = 3
    assert(res == Solution().repeatedNTimes(nums))
    
    /**
     输入：nums = [2,1,2,5,3,2]
     输出：2
     */
    nums = [2,1,2,5,3,2]
    res = 2
    assert(res == Solution().repeatedNTimes(nums))
    
    /**
     输入：nums = [5,1,5,2,5,3,5,4]
     输出：5
     */
    nums = [5,1,5,2,5,3,5,4]
    res = 5
    assert(res == Solution().repeatedNTimes(nums))
}
