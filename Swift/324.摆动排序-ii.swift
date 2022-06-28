/*
 * @lc app=leetcode.cn id=324 lang=swift
 *
 * [324] 摆动排序 II
 */

// @lc code=start
class Solution {
    func wiggleSort(_ nums: inout [Int]) {
        let arr = nums.sorted()
        var l = (nums.count - 1) / 2, r = nums.count - 1
        for i in 0..<nums.count {
            if i & 1 == 0 {
                nums[i] = arr[l]
                l -= 1
            } else {
                nums[i] = arr[r]
                r -= 1
            }
        }
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: [Int]
        
    /**
     输入：nums = [1,5,1,1,6,4]
     输出：[1,6,1,5,1,4]
     解释：[1,4,1,5,1,6] 同样是符合题目要求的结果，可以被判题程序接受。
     */
    nums = [1,5,1,1,6,4]
    res = [1,6,1,5,1,4]
    Solution().wiggleSort(&nums)
    assert(res == nums)
    
    /**
     输入：nums = [1,3,2,2,3,1]
     输出：[2,3,1,3,1,2]
     */
    nums = [1,3,2,2,3,1]
    res = [2,3,1,3,1,2]
    Solution().wiggleSort(&nums)
    assert(res == nums)
}
