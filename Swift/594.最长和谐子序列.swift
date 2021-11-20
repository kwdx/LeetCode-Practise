/*
 * @lc app=leetcode.cn id=594 lang=swift
 *
 * [594] 最长和谐子序列
 */

// @lc code=start
class Solution {
    func findLHS(_ nums: [Int]) -> Int {
        var cnts: [Int: Int] = [:]
        for num in nums {
            cnts[num] = (cnts[num] ?? 0) + 1
        }
        var ans = 0
        for item in cnts {
            if let val = cnts[item.key + 1] {
                ans = max(ans, item.value + val)
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
     输入：nums = [1,3,2,2,5,2,3,7]
     输出：5
     解释：最长的和谐子序列是 [3,2,2,2,3]
     */
    nums = [1,3,2,2,5,2,3,7]
    res = 5
    assert(res == Solution().findLHS(nums))
    
    /**
     输入：nums = [1,2,3,4]
     输出：2
     */
    nums = [1,2,3,4]
    res = 2
    assert(res == Solution().findLHS(nums))
    
    /**
     输入：nums = [1,1,1,1]
     输出：0
     */
    nums = [1,1,1,1]
    res = 0
    assert(res == Solution().findLHS(nums))
}
