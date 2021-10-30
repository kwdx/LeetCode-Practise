/*
 * @lc app=leetcode.cn id=260 lang=swift
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
    func singleNumber(_ nums: [Int]) -> [Int] {
        var freq: [Int: Int] = [:]
        for num in nums {
            freq[num] = (freq[num] ?? 0) + 1;
        }
        var ans: [Int] = freq.compactMap { (k, v) in
            return v == 1 ? k : nil
        }
        ans.sort()
        return ans;
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: [Int]
    
    /**
     输入：nums = [1,2,1,3,2,5]
     输出：[3,5]
     解释：[5, 3] 也是有效的答案。
     */
    nums = [1,2,1,3,2,5]
    res = [3,5]
    
    /**
     输入：nums = [-1,0]
     输出：[-1,0]
     */
    nums = [-1,0]
    res = [-1,0]
    assert(res == Solution().singleNumber(nums))
    
    /**
     输入：nums = [0,1]
     输出：[1,0]
     */
    nums = [0,1]
    res = [0,1]
    assert(res == Solution().singleNumber(nums))
}
