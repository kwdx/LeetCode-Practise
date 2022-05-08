/*
 * @lc app=leetcode.cn id=442 lang=swift
 *
 * [442] 数组中重复的数据
 */

import Darwin

// @lc code=start
class Solution {
    func findDuplicates(_ nums: [Int]) -> [Int] {
        var ans: [Int] = []
        var visited: [Bool] = .init(repeating: false, count: nums.count)
        for num in nums {
            if visited[num - 1] == true {
                ans.append(num)
            } else {
                visited[num - 1] = true
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
     输入：nums = [4,3,2,7,8,2,3,1]
     输出：[2,3]
     */
    nums = [4,3,2,7,8,2,3,1]
    res = [2,3]
    assert(res == Solution().findDuplicates(nums))
    
    /**
     输入：nums = [1,1,2]
     输出：[1]
     */
    nums = [1,1,2]
    res = [1]
    assert(res == Solution().findDuplicates(nums))
    
    /**
     输入：nums = [1]
     输出：[]
     */
    nums = [1]
    res = []
    assert(res == Solution().findDuplicates(nums))
}
