/*
 * @lc app=leetcode.cn id=missing-two-lcci lang=swift
 *
 * [面试题] 17.19. 消失的两个数字
 */

// @lc code=start
class Solution {
    func missingTwo(_ nums: [Int]) -> [Int] {
        let n = nums.count + 2
        let sum = nums.reduce(0, +)
        
        let ans = (1 + n) * n / 2 - sum
        let half = ans / 2
        var a = (1 + half) * half / 2
        for num in nums {
            if num <= half {
                a -= num
            }
        }
        return [a, ans - a]
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: [Int]
    
    /**
     输入: [1]
     输出: [2,3]
     */
    nums = [1]
    res = [2,3]
    assert(res == Solution().missingTwo(nums))
    
    /**
     输入: [2,3]
     输出: [1,4]
     */
    nums = [2,3]
    res = [1,4]
    assert(res == Solution().missingTwo(nums))
}
