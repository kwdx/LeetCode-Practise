/*
 * @lc app=leetcode.cn id=915 lang=swift
 *
 * [915] 分割数组
 */

// @lc code=start
class Solution {
    func partitionDisjoint(_ nums: [Int]) -> Int {
        let n = nums.count
        var minValues = [Int](repeating: 0, count: n)
        minValues[n - 1] = nums[n - 1]
        for i in (0..<(n-1)).reversed() {
            minValues[i] = min(minValues[i + 1], nums[i])
        }
        var maxValue = nums[0]
        for i in 0..<(n - 1) {
            maxValue = max(maxValue, nums[i])
            if maxValue <= minValues[i + 1] {
                return i + 1
            }
        }
        return -1
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: Int
    
    /**
     输入：nums = [5,0,3,8,6]
     输出：3
     解释：left = [5,0,3]，right = [8,6]
     */
    nums = [5,0,3,8,6]
    res = 3
    assert(res == Solution().partitionDisjoint(nums))
    
    /**
     输入：nums = [1,1,1,0,6,12]
     输出：4
     解释：left = [1,1,1,0]，right = [6,12]
     */
    nums = [1,1,1,0,6,12]
    res = 4
    assert(res == Solution().partitionDisjoint(nums))
}
