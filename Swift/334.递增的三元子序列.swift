/*
 * @lc app=leetcode.cn id=334 lang=swift
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
class Solution {
    func increasingTriplet(_ nums: [Int]) -> Bool {
        var tops: [Int] = []
        for num in nums {
            var left = 0
            var right = tops.count
            while left < right {
                let mid = (left + right) >> 1
                if tops[mid] < num {
                    left = mid + 1
                } else {
                    right = mid
                }
            }
            if left == tops.count {
                tops.append(num)
                if tops.count > 2 {
                    return true
                }
            } else {
                tops[left] = num
            }
        }
        return false
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: Bool
    
    /**
     输入：nums = [1,2,3,4,5]
     输出：true
     解释：任何 i < j < k 的三元组都满足题意
     */
    nums = [1,2,3,4,5]
    res = true
    assert(res == Solution().increasingTriplet(nums))
    
    /**
     输入：nums = [5,4,3,2,1]
     输出：false
     解释：不存在满足题意的三元组
     */
    nums = [5,4,3,2,1]
    res = false
    assert(res == Solution().increasingTriplet(nums))
    
    /**
     输入：nums = [2,1,5,0,4,6]
     输出：true
     解释：三元组 (3, 4, 5) 满足题意，因为 nums[3] == 0 < nums[4] == 4 < nums[5] == 6
     */
    nums = [2,1,5,0,4,6]
    res = true
    assert(res == Solution().increasingTriplet(nums))
    
    /**
     输入：nums =[0,4,2,1,0,-1,-3]
     输出：false
     */
    nums = [0,4,2,1,0,-1,-3]
    res = false
    assert(res == Solution().increasingTriplet(nums))
}
