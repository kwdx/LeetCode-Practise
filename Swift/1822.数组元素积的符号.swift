/*
 * @lc app=leetcode.cn id=1822 lang=swift
 *
 * [1822] 数组元素积的符号
 */

// @lc code=start
class Solution {
    func arraySign(_ nums: [Int]) -> Int {
        var sign = 1
        for num in nums {
            if num == 0 {
                return 0
            }
            if num < 0 {
                sign = -sign
            }
        }
        return sign
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: Int
    
    /**
     输入：nums = [-1,-2,-3,-4,3,2,1]
     输出：1
     解释：数组中所有值的乘积是 144 ，且 signFunc(144) = 1
     */
    nums = [-1,-2,-3,-4,3,2,1]
    res = 1
    assert(res == Solution().arraySign(nums))
    
    /**
     输入：nums = [1,5,0,2,-3]
     输出：0
     解释：数组中所有值的乘积是 0 ，且 signFunc(0) = 0
     */
    nums = [1,5,0,2,-3]
    res = 0
    assert(res == Solution().arraySign(nums))
    
    /**
     输入：nums = [-1,1,-1,1,-1]
     输出：-1
     解释：数组中所有值的乘积是 -1 ，且 signFunc(-1) = -1
     */
    nums = [-1,1,-1,1,-1]
    res = -1
    assert(res == Solution().arraySign(nums))
}
