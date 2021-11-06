/*
 * @lc app=leetcode.cn id=268 lang=swift
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution {
    func missingNumber(_ nums: [Int]) -> Int {
        var ans = 0
        for i in 0...nums.count {
            ans ^= i
        }
        for num in nums {
            ans ^= num
        }
        return ans
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: Int
    
    /**
     输入：nums = [3,0,1]
     输出：2
     解释：n = 3，因为有 3 个数字，所以所有的数字都在范围 [0,3] 内。2 是丢失的数字，因为它没有出现在 nums 中。
     */
    nums = [3,0,1]
    res = 2
    assert(res == Solution().missingNumber(nums))
    
    /**
     输入：nums = [0,1]
     输出：2
     解释：n = 2，因为有 2 个数字，所以所有的数字都在范围 [0,2] 内。2 是丢失的数字，因为它没有出现在 nums 中。
     */
    nums = [0,1]
    res = 2
    assert(res == Solution().missingNumber(nums))
    
    /**
     输入：nums = [9,6,4,2,3,5,7,0,1]
     输出：8
     解释：n = 9，因为有 9 个数字，所以所有的数字都在范围 [0,9] 内。8 是丢失的数字，因为它没有出现在 nums 中。
     */
    nums = [9,6,4,2,3,5,7,0,1]
    res = 8
    assert(res == Solution().missingNumber(nums))
    
    /**
     输入：nums = [0]
     输出：1
     解释：n = 1，因为有 1 个数字，所以所有的数字都在范围 [0,1] 内。1 是丢失的数字，因为它没有出现在 nums 中。
     */
    nums = [0]
    res = 1
    assert(res == Solution().missingNumber(nums))
}
