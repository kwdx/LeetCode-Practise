/*
 * @lc app=leetcode.cn id=1658 lang=swift
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

// @lc code=start
class Solution {
    func minOperations(_ nums: [Int], _ x: Int) -> Int {
        let n = nums.count
        
        var lSum = 0
        var rSum = nums.reduce(0, +)
        var ans = n + 1
        
        if rSum < x {
            return -1
        }
        
        var r = 0
        for l in -1..<n {
            if l != -1 {
                lSum += nums[l]
            }
            while r < n && lSum + rSum > x {
                rSum -= nums[r]
                r += 1
            }
            if (lSum + rSum == x) {
                ans = min(ans, (l + 1) + (n - r))
            }
        }
        
        return ans > n ? -1 : ans
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var x: Int
    var res: Int
    
    /**
     输入：nums = [1,1,4,2,3], x = 5
     输出：2
     解释：最佳解决方案是移除后两个元素，将 x 减到 0 。
     */
    nums = [1,1,4,2,3]
    x = 5
    res = 2
    assert(res == Solution().minOperations(nums, x))
    
    /**
     输入：nums = [5,6,7,8,9], x = 4
     输出：-1
     */
    nums = [5,6,7,8,9]
    x = 4
    res = -1
    assert(res == Solution().minOperations(nums, x))
    
    /**
     输入：nums = [3,2,20,1,1,3], x = 10
     输出：5
     解释：最佳解决方案是移除后三个元素和前两个元素（总共 5 次操作），将 x 减到 0 。
     */
    nums = [3,2,20,1,1,3]
    x = 10
    res = 5
    assert(res == Solution().minOperations(nums, x))
}
