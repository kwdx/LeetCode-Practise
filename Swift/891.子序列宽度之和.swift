/*
 * @lc app=leetcode.cn id=891 lang=swift
 *
 * [891] 子序列宽度之和
 */

// @lc code=start
class Solution {
    func sumSubseqWidths(_ nums: [Int]) -> Int {
        let nums = nums.sorted()
        var ans = 0
        let MOD = 1000000007
        var x = nums[0]
        var y = 2
        for j in 1..<nums.count {
            ans = (ans + nums[j] * (y - 1) - x) % MOD
            x = (x * 2 + nums[j]) % MOD
            y = y * 2 % MOD
        }
        return (ans + MOD) % MOD
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: Int
    
    /**
     输入：nums = [2,1,3]
     输出：6
     解释：子序列为 [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3] 。
     相应的宽度是 0, 0, 0, 1, 1, 2, 2 。
     宽度之和是 6 。
     */
    nums = [2,1,3]
    res = 6
    assert(res == Solution().sumSubseqWidths(nums))
    
    /**
     输入：nums = [2]
     输出：0
     */
    nums = [2]
    res = 0
    assert(res == Solution().sumSubseqWidths(nums))
}
