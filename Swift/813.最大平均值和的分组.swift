/*
 * @lc app=leetcode.cn id=813 lang=swift
 *
 * [813] 最大平均值和的分组
 */

// @lc code=start
class Solution {
    func largestSumOfAverages(_ nums: [Int], _ k: Int) -> Double {
//        let n = nums.count
//        var prefix = [Double](repeating: 0, count: n + 1)
//        for i in 0..<n {
//            prefix[i + 1] = prefix[i] + Double(nums[i])
//        }
//        var dp = [[Double]](repeating: [Double](repeating: 0, count: k + 1), count: n + 1)
//        for i in 1...n {
//            dp[i][1] = prefix[i] / Double(i)
//        }
//        var j = 2
//        while j <= k {
//            var i = j
//            while i <= n {
//                var x = j - 1
//                while x < i {
//                    dp[i][j] = max(dp[i][j], dp[x][j - 1] + (prefix[i] - prefix[x]) / Double(i - x))
//                    x += 1
//                }
//                i += 1
//            }
//            j += 1
//        }
//        return dp[n][k]
        
        let n = nums.count
        var prefix = [Double](repeating: 0, count: n + 1)
        for i in 0..<n {
            prefix[i + 1] = prefix[i] + Double(nums[i])
        }
        var dp = [Double](repeating: 0, count: n + 1)
        for i in 1...n {
            dp[i] = prefix[i] / Double(i)
        }
        var j = 2
        while j <= k {
            for i in (j...n).reversed() {
                var x = j - 1
                while x < i {
                    dp[i] = max(dp[i], dp[x] + (prefix[i] - prefix[x]) / Double(i - x))
                    x += 1
                }
            }
            j += 1
        }
        return dp[n]
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var k: Int
    var res: Double
    
    /**
     输入: nums = [9,1,2,3,9], k = 3
     输出: 20.00000
     解释:
     nums 的最优分组是[9], [1, 2, 3], [9]. 得到的分数是 9 + (1 + 2 + 3) / 3 + 9 = 20.
     我们也可以把 nums 分成[9, 1], [2], [3, 9].
     这样的分组得到的分数为 5 + 2 + 6 = 13, 但不是最大值.
     */
    nums = [9,1,2,3,9]
    k = 3
    res = 20.00000
    assert(res == Solution().largestSumOfAverages(nums, k))
    
    /**
     输入: nums = [1,2,3,4,5,6,7], k = 4
     输出: 20.50000
     */
    nums = [1,2,3,4,5,6,7]
    k = 4
    res = 20.50000
    assert(res == Solution().largestSumOfAverages(nums, k))
}
