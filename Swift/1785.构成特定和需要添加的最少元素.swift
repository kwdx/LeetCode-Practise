/*
 * @lc app=leetcode.cn id=1785 lang=swift
 *
 * [1785] 构成特定和需要添加的最少元素
 */

// @lc code=start
class Solution {
    func minElements(_ nums: [Int], _ limit: Int, _ goal: Int) -> Int {
        let sum = nums.reduce(0, +)
        let diff = abs(sum - goal)
        return (diff + limit - 1) / limit
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var limit: Int
    var goal: Int
    var res: Int
    
    /**
     输入：nums = [1,-1,1], limit = 3, goal = -4
     输出：2
     解释：可以将 -2 和 -3 添加到数组中，数组的元素总和变为 1 - 1 + 1 - 2 - 3 = -4 。
     */
    nums = [1,-1,1]
    limit = 3
    goal = -4
    res = 2
    assert(res == Solution().minElements(nums, limit, goal))
    
    /**
     输入：nums = [1,-10,9,1], limit = 100, goal = 0
     输出：1
     */
    nums = [1,-10,9,1]
    limit = 100
    goal = 0
    res = 1
    assert(res == Solution().minElements(nums, limit, goal))
}
