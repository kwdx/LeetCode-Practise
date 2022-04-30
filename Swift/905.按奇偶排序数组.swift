/*
 * @lc app=leetcode.cn id=905 lang=swift
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start
class Solution {
    func sortArrayByParity(_ nums: [Int]) -> [Int] {
        var ans = nums
        var left = 0, right = nums.count - 1
        while left < right {
            while left < right && (ans[left] & 1) == 0 {
                left += 1
            }
            while left < right && (ans[right] & 1) == 1 {
                right -= 1
            }
            let tmp = ans[left]
            ans[left] = ans[right]
            ans[right] = tmp;
        }
        return ans
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: [Int]
    
    /**
     输入：nums = [3,1,2,4]
     输出：[2,4,3,1]
     解释：[4,2,3,1]、[2,4,1,3] 和 [4,2,1,3] 也会被视作正确答案。
     */
    nums = [3,1,2,4]
    res = [4,2,1,3]
    assert(res == Solution().sortArrayByParity(nums))
    
    /**
     输入：nums = [0]
     输出：[0]
     */
    nums = [0]
    res = [0]
    assert(res == Solution().sortArrayByParity(nums))
}
