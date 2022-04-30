/*
 * @lc app=leetcode.cn id=908 lang=swift
 *
 * [908] 最小差值 I
 */

// @lc code=start
class Solution {
    func smallestRangeI(_ nums: [Int], _ k: Int) -> Int {
        var a = nums[0], b = nums[0]
        for num in nums {
            a = max(a, num)
            b = min(b, num)
        }
        return max(0, a - b - 2 * k)
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var k: Int
    var res: Int
    
    /**'
     输入：nums = [1], k = 0
     输出：0
     解释：分数是 max(nums) - min(nums) = 1 - 1 = 0。
     */
    nums = [1]
    k = 0
    res = 0
    assert(res == Solution().smallestRangeI(nums, k))
    
    /**'
     输入：nums = [0,10], k = 2
     输出：6
     解释：将 nums 改为 [2,8]。分数是 max(nums) - min(nums) = 8 - 2 = 6。
     */
    nums = [0,10]
    k = 2
    res = 6
    assert(res == Solution().smallestRangeI(nums, k))
    
    /**'
     输入：nums = [1,3,6], k = 3
     输出：0
     解释：将 nums 改为 [4,4,4]。分数是 max(nums) - min(nums) = 4 - 4 = 0。
     */
    nums = [1,3,6]
    k = 3
    res = 0
    assert(res == Solution().smallestRangeI(nums, k))
}
