/*
 * @lc app=leetcode.cn id=1760 lang=swift
 *
 * [1760] 袋子里最少数目的球
 */

// @lc code=start
class Solution {
    func minimumSize(_ nums: [Int], _ maxOperations: Int) -> Int {
        var left = 1
        var right = nums.max()!
        var ans = 0
        while left <= right {
            let y = (left + right) / 2
            var ops = 0
            for num in nums {
                ops += (num - 1) / y
            }
            if ops <= maxOperations {
                ans = y
                right = y - 1
            } else {
                left = y + 1
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var maxOperations: Int
    var res: Int
    
    /**
     输入：nums = [9], maxOperations = 2
     输出：3
     解释：
     - 将装有 9 个球的袋子分成装有 6 个和 3 个球的袋子。[9] -> [6,3] 。
     - 将装有 6 个球的袋子分成装有 3 个和 3 个球的袋子。[6,3] -> [3,3,3] 。
     装有最多球的袋子里装有 3 个球，所以开销为 3 并返回 3 。
     */
    nums = [9]
    maxOperations = 2
    res = 3
    assert(res == Solution().minimumSize(nums, maxOperations))
    
    /**
     输入：nums = [2,4,8,2], maxOperations = 4
     输出：2
     解释：
     - 将装有 8 个球的袋子分成装有 4 个和 4 个球的袋子。[2,4,8,2] -> [2,4,4,4,2] 。
     - 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,4,4,4,2] -> [2,2,2,4,4,2] 。
     - 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,2,2,4,4,2] -> [2,2,2,2,2,4,2] 。
     - 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,2,2,2,2,4,2] -> [2,2,2,2,2,2,2,2] 。
     装有最多球的袋子里装有 2 个球，所以开销为 2 并返回 2 。
     */
    nums = [2,4,8,2]
    maxOperations = 4
    res = 2
    assert(res == Solution().minimumSize(nums, maxOperations))
    
    /**
     输入：nums = [7,17], maxOperations = 2
     输出：7
     */
    nums = [2,4,8,2]
    maxOperations = 4
    res = 2
    assert(res == Solution().minimumSize(nums, maxOperations))
}
