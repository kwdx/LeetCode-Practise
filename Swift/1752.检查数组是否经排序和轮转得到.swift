/*
 * @lc app=leetcode.cn id=1752 lang=swift
 *
 * [1752] 检查数组是否经排序和轮转得到
 */

// @lc code=start
class Solution {
    func check(_ nums: [Int]) -> Bool {
        var ans = false
        for i in 0..<(nums.count - 1) {
            if nums[i] > nums[i + 1] {
                if !ans {
                    ans = true
                } else {
                    return false
                }
            }
        }
        return !ans || (nums.last! <= nums.first!)
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: Bool
    
    /**
     输入：nums = [3,4,5,1,2]
     输出：true
     解释：[1,2,3,4,5] 为有序的源数组。
     可以轮转 x = 3 个位置，使新数组从值为 3 的元素开始：[3,4,5,1,2] 。
     */
    nums = [3,4,5,1,2]
    res = true
    assert(res == Solution().check(nums))
    
    /**
     输入：nums = [2,1,3,4]
     输出：false
     解释：源数组无法经轮转得到 nums 。
     */
    nums = [2,1,3,4]
    res = false
    assert(res == Solution().check(nums))
    
    /**
     输入：nums = [1,2,3]
     输出：true
     解释：[1,2,3] 为有序的源数组。
     可以轮转 x = 0 个位置（即不轮转）得到 nums 。
     */
    nums = [1,2,3]
    res = true
    assert(res == Solution().check(nums))
}
