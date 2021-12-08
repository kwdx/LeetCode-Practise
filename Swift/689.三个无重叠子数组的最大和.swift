/*
 * @lc app=leetcode.cn id=689 lang=swift
 *
 * [689] 三个无重叠子数组的最大和
 */

// @lc code=start
class Solution {
    func maxSumOfThreeSubarrays(_ nums: [Int], _ k: Int) -> [Int] {
        var ans: [Int] = []
                
        var win1 = 0, winSum1 = 0, idx1 = 0
        var win2 = 0, winSum12 = 0, sum12Idx1 = 0
        var win3 = 0, winSum123 = 0, sum12Idx2 = 0
        for i in (k * 2)..<nums.count {
            win1 += nums[i - k * 2];
            win2 += nums[i - k];
            win3 += nums[i];
            if i >= k * 3 - 1 {
                if win1 > winSum1 {
                    winSum1 = win1
                    idx1 = i - k * 3 + 1;
                }
                if winSum1 + win2 > winSum12 {
                    winSum12 = winSum1 + win2
                    sum12Idx1 = idx1
                    sum12Idx2 = i - k * 2 + 1
                }
                if winSum12 + win3 > winSum123 {
                    winSum123 = winSum12 + win3
                    ans = [sum12Idx1, sum12Idx2, i - k + 1]
                }
                win1 -= nums[i - k * 3 + 1]
                win2 -= nums[i - k * 2 + 1]
                win3 -= nums[i - k + 1]
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var k: Int
    var res: [Int]
    
    /**
     输入：nums = [1,2,1,2,6,7,5,1], k = 2
     输出：[0,3,5]
     解释：子数组 [1, 2], [2, 6], [7, 5] 对应的起始下标为 [0, 3, 5]。
     也可以取 [2, 1], 但是结果 [1, 3, 5] 在字典序上更大。
     */
    nums = [1,2,1,2,6,7,5,1]
    k = 2
    res = [0,3,5]
    assert(res == Solution().maxSumOfThreeSubarrays(nums, k))
    
    /**
     输入：nums = [1,2,1,2,1,2,1,2,1], k = 2
     输出：[0,2,4]
     */
    nums = [1,2,1,2,1,2,1,2,1]
    k = 2
    res = [0,2,4]
    assert(res == Solution().maxSumOfThreeSubarrays(nums, k))

}
