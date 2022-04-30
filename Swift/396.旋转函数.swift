/*
 * @lc app=leetcode.cn id=396 lang=swift
 *
 * [396] 旋转函数
 */

// @lc code=start
class Solution {
    func maxRotateFunction(_ nums: [Int]) -> Int {
        var ans = 0
        var sum = 0
        for i in 0..<nums.count {
            ans += nums[i] * i
            sum += nums[i]
        }
        var cur = ans
        for i in (0..<nums.count).reversed() {
            cur += sum - nums[i] * nums.count
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
     输入: nums = [4,3,2,6]
     输出: 26
     解释:
     F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
     F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
     F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
     F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
     所以 F(0), F(1), F(2), F(3) 中的最大值是 F(3) = 26 。
     */
    nums = [4,3,2,6]
    res = 26
    assert(res == Solution().maxRotateFunction(nums))
    
    /**
     输入: nums = [100]
     输出: 0
     */
    nums = [100]
    res = 0
    assert(res == Solution().maxRotateFunction(nums))
}
