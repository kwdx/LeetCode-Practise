/*
 * @lc app=leetcode.cn id=1664 lang=swift
 *
 * [1664] 生成平衡数组的方案数
 */

// @lc code=start
class Solution {
    func waysToMakeFair(_ nums: [Int]) -> Int {
        var odd1 = 0, even1 = 0
        var  odd2 = 0, even2 = 0
        for i in 0..<nums.count {
            if i & 1 == 1 {
                odd2 += nums[i]
            } else {
                even2 += nums[i]
            }
        }
        var ans = 0
        for i in 0..<nums.count {
            if i & 1 == 1 {
                odd2 -= nums[i]
            } else {
                even2 -= nums[i]
            }
            if odd1 + even2 == odd2 + even1 {
                ans += 1
            }
            if i & 1 == 1 {
                odd1 += nums[i]
            } else {
                even1 += nums[i]
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
     输入：nums = [2,1,6,4]
     输出：1
     解释：
     删除下标 0 ：[1,6,4] -> 偶数元素下标为：1 + 4 = 5 。奇数元素下标为：6 。不平衡。
     删除下标 1 ：[2,6,4] -> 偶数元素下标为：2 + 4 = 6 。奇数元素下标为：6 。平衡。
     删除下标 2 ：[2,1,4] -> 偶数元素下标为：2 + 4 = 6 。奇数元素下标为：1 。不平衡。
     删除下标 3 ：[2,1,6] -> 偶数元素下标为：2 + 6 = 8 。奇数元素下标为：1 。不平衡。
     只有一种让剩余数组成为平衡数组的方案。
     */
    nums = [2,1,6,4]
    res = 1
    assert(res == Solution().waysToMakeFair(nums))
    
    /**
     输入：nums = [1,1,1]
     输出：3
     解释：你可以删除任意元素，剩余数组都是平衡数组。
     */
    nums = [1,1,1]
    res = 3
    assert(res == Solution().waysToMakeFair(nums))
    
    /**
     输入：nums = [1,2,3]
     输出：0
     解释：不管删除哪个元素，剩下数组都不是平衡数组。
     */
    nums = [1,2,3]
    res = 0
    assert(res == Solution().waysToMakeFair(nums))
}
