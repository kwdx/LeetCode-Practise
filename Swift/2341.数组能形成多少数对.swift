/*
 * @lc app=leetcode.cn id=2341 lang=swift
 *
 * [2341] 数组能形成多少数对
 */

// @lc code=start
class Solution {
    func numberOfPairs(_ nums: [Int]) -> [Int] {
        var numCnt = [Int: Int]()
        for num in nums {
            numCnt[num] = 1 + (numCnt[num] ?? 0)
        }
        var ans = [0, 0]
        for (_, cnt) in numCnt {
            ans[0] += cnt / 2
            if (cnt & 1) == 1 {
                ans[1] += 1
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: [Int]
    
    /**
     输入：nums = [1,3,2,1,3,2,2]
     输出：[3,1]
     解释：
     nums[0] 和 nums[3] 形成一个数对，并从 nums 中移除，nums = [3,2,3,2,2] 。
     nums[0] 和 nums[2] 形成一个数对，并从 nums 中移除，nums = [2,2,2] 。
     nums[0] 和 nums[1] 形成一个数对，并从 nums 中移除，nums = [2] 。
     无法形成更多数对。总共形成 3 个数对，nums 中剩下 1 个数字。
     */
    nums = [1,3,2,1,3,2,2]
    res = [3,1]
    assert(res == Solution().numberOfPairs(nums))
    
    /**
     输入：nums = [1,1]
     输出：[1,0]
     解释：nums[0] 和 nums[1] 形成一个数对，并从 nums 中移除，nums = [] 。
     无法形成更多数对。总共形成 1 个数对，nums 中剩下 0 个数字。
     */
    nums = [1,1]
    res = [1,0]
    assert(res == Solution().numberOfPairs(nums))
    
    /**
     输入：nums = [0]
     输出：[0,1]
     解释：无法形成数对，nums 中剩下 1 个数字。
     */
    nums = [0]
    res = [0,1]
    assert(res == Solution().numberOfPairs(nums))
}
