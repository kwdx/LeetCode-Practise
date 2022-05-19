/*
 * @lc app=leetcode.cn id=462 lang=swift
 *
 * [462] 最少移动次数使数组元素相等 II
 */

// @lc code=start
class Solution {
    func minMoves2(_ nums: [Int]) -> Int {
        let nums_ = nums.sorted()
        var ans = 0
        let mid = (0 + nums_.count - 1) >> 1
        let avg = nums_[mid]
        for num in nums_ {
            ans += abs(num - avg)
        }
        return ans
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: Int
    
    /**
     输入：nums = [1,2,3]
     输出：2
     解释：
     只需要两步操作（每步操作指南使一个元素加 1 或减 1）：
     [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
     */
    nums = [1,2,3]
    res = 2
    assert(res == Solution().minMoves2(nums))
    
    /**
     输入：nums = [1,10,2,9]
     输出：16
     */
    nums = [1,10,2,9]
    res = 16
    assert(res == Solution().minMoves2(nums))
}
