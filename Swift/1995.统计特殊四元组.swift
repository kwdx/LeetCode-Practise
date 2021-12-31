/*
 * @lc app=leetcode.cn id=1995 lang=swift
 *
 * [1995] 统计特殊四元组
 */

// @lc code=start
class Solution {
    func countQuadruplets(_ nums: [Int]) -> Int {
        var ans = 0
        for i in (3..<nums.count) {
            let sum = nums[i]
            for j in 2..<i {
                let target = sum - nums[j]
                if target <= 1 {
                    continue
                }
                for left in 0..<(j - 1) {
                    if target - nums[left] < 1 {
                        continue
                    }
                    var right = j - 1
                    while left < right {
                        if nums[right] + nums[left] == target {
                            ans += 1
                        }
                        right -= 1
                    }
                }
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: Int
    
    /**
     输入：nums = [1,2,3,6]
     输出：1
     解释：满足要求的唯一一个四元组是 (0, 1, 2, 3) 因为 1 + 2 + 3 == 6 。
     */
    nums = [1,2,3,6]
    res = 1
    assert(res == Solution().countQuadruplets(nums))
    
    /**
     输入：nums = [3,3,6,4,5]
     输出：0
     解释：[3,3,6,4,5] 中不存在满足要求的四元组。
     */
    nums = [3,3,6,4,5]
    res = 0
    assert(res == Solution().countQuadruplets(nums))
    
    /**
     输入：nums = [1,1,1,3,5]
     输出：4
     解释：满足要求的 4 个四元组如下：
     - (0, 1, 2, 3): 1 + 1 + 1 == 3
     - (0, 1, 3, 4): 1 + 1 + 3 == 5
     - (0, 2, 3, 4): 1 + 1 + 3 == 5
     - (1, 2, 3, 4): 1 + 1 + 3 == 5
     */
    nums = [1,1,1,3,5]
    res = 4
    assert(res == Solution().countQuadruplets(nums))
    
    /**
     输入：nums = [35,15,38,1,10,26]
     输出：1
     */
    nums = [35,15,38,1,10,26]
    res = 1
    assert(res == Solution().countQuadruplets(nums))
}
