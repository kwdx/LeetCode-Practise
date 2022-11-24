/*
 * @lc app=leetcode.cn id=795 lang=swift
 *
 * [795] 区间子数组个数
 */

// @lc code=start
class Solution {
    func numSubarrayBoundedMax(_ nums: [Int], _ left: Int, _ right: Int) -> Int {
        func count(_ lower: Int) -> Int {
            var cur = 0
            var ans = 0
            for num in nums {
                if num <= lower {
                    cur += 1
                } else {
                    cur = 0
                }
                ans += cur
            }
            return ans
        }
        return count(right) - count(left - 1)
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var left: Int
    var right: Int
    var res: Int
        
    /**
     输入：nums = [2,1,4,3], left = 2, right = 3
     输出：3
     解释：满足条件的三个子数组：[2], [2, 1], [3]
     */
    nums = [2,1,4,3]
    left = 2
    right = 3
    res = 3
    assert(res == Solution().numSubarrayBoundedMax(nums, left, right))
    
    /**
     输入：nums = [2,9,2,5,6], left = 2, right = 8
     输出：7
     */
    nums = [2,9,2,5,6]
    left = 2
    right = 8
    res = 7
    assert(res == Solution().numSubarrayBoundedMax(nums, left, right))
}
