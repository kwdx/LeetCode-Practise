/*
 * @lc app=leetcode.cn id=1814 lang=swift
 *
 * [1814] 统计一个数组中好对子的数目
 */

// @lc code=start
class Solution {
    func countNicePairs(_ nums: [Int]) -> Int {
        let MOD = 1_000_000_007
        var ans = 0
        var h = [Int: Int]()
        for num in nums {
            var temp = num
            var rever = 0
            while temp > 0 {
                rever = rever * 10 + temp % 10
                temp /= 10;
            }
            ans = (ans + (h[num - rever] ?? 0)) % MOD
            h[num - rever] = 1 + (h[num - rever] ?? 0)
        }
        return ans
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: Int

    /**
     输入：nums = [42,11,1,97]
     输出：2
     解释：两个坐标对为：
      - (0,3)：42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121 。
      - (1,2)：11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12 。
     */
    nums = [42,11,1,97]
    res = 2
    assert(res == Solution().countNicePairs(nums))
    
    /**
     输入：nums = [13,10,35,24,76]
     输出：4
     */
    nums = [13,10,35,24,76]
    res = 4
    assert(res == Solution().countNicePairs(nums))
}
