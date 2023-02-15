/*
 * @lc app=leetcode.cn id=1250 lang=swift
 *
 * [1250] 检查「好数组」
 */

// @lc code=start
class Solution {
    func isGoodArray(_ nums: [Int]) -> Bool {
        var divisor = nums[0]
        for num in nums {
            divisor = gcd(num, divisor)
            if (divisor == 1) {
                return true
            }
        }
        return false
    }
    
    private func gcd(_ a: Int, _ b: Int) -> Int {
        let r = a % b
        return r == 0 ? b : gcd(b, r)
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: Bool
    
    /**
     输入：nums = [12,5,7,23]
     输出：true
     解释：挑选数字 5 和 7。
     5*3 + 7*(-2) = 1
     */
    nums = [12,5,7,23]
    res = true
    assert(res == Solution().isGoodArray(nums))
    
    /**
     输入：nums = [29,6,10]
     输出：true
     解释：挑选数字 29, 6 和 10。
     29*1 + 6*(-3) + 10*(-1) = 1
     */
    nums = [29,6,10]
    res = true
    assert(res == Solution().isGoodArray(nums))
    
    /**
     输入：nums = [3,6]
     输出：false
     */
    nums = [3,6]
    res = false
    assert(res == Solution().isGoodArray(nums))
}
