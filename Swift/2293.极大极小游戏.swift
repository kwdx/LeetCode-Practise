/*
 * @lc app=leetcode.cn id=2293 lang=swift
 *
 * [2293] 极大极小游戏
 */

// @lc code=start
class Solution {
    func minMaxGame(_ nums: [Int]) -> Int {
        var nums = nums
        var n = nums.count
        while n != 1 {
            let m = n >> 1
            for i in 0..<m {
                if i % 2 == 0 {
                    nums[i] = min(nums[2 * i], nums[2 * i + 1])
                } else {
                    nums[i] = max(nums[2 * i], nums[2 * i + 1])
                }
            }
            n = m
        }
        return nums[0]
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: Int
    
    /**
     输入：nums = [1,3,5,2,4,8,2,2]
     输出：1
     解释：重复执行算法会得到下述数组。
     第一轮：nums = [1,5,4,2]
     第二轮：nums = [1,4]
     第三轮：nums = [1]
     1 是最后剩下的那个数字，返回 1 。
     */
    nums = [1,3,5,2,4,8,2,2]
    res = 1
    assert(res == Solution().minMaxGame(nums))
    
    /**
     输入：nums = [3]
     输出：3
     解释：3 就是最后剩下的数字，返回 3 。
     */
    nums = [3]
    res = 3
    assert(res == Solution().minMaxGame(nums))
}
