/*
 * @lc app=leetcode.cn id=698 lang=swift
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
class Solution {
    func canPartitionKSubsets(_ nums: [Int], _ k: Int) -> Bool {
        let sum = nums.reduce(0, +)
        if sum % k > 0 {
            return false
        }
        let per = sum / k
        let nums = nums.sorted()
        if nums.last! > per {
            return false
        }
        let n = nums.count
        let m = 1 << n
        var dp = [Bool](repeating: false, count: m)
        var curSum = [Int](repeating: 0, count: m)
        dp[0] = true
        for i in 0..<m {
            if !dp[i] {
                continue
            }
            for j in 0..<n {
                if curSum[i] + nums[j] > per {
                    break
                }
                if ((i >> j) & 1) == 0 {
                    let next = i | (1 << j)
                    if !dp[next] {
                        curSum[next] = (curSum[i] + nums[j]) % per
                        dp[next] = true
                    }
                }
            }
        }

        return dp[m - 1]
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var k: Int
    var res: Bool
        
    /**
     输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
     输出： True
     说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。
     */
    nums = [4,3,2,3,5,2,1]
    k = 4
    res = true
    assert(res == Solution().canPartitionKSubsets(nums, k))
    
    /**
     输入: nums = [1,2,3,4], k = 3
     输出: false
     */
    nums = [1,2,3,4]
    k = 3
    res = false
    assert(res == Solution().canPartitionKSubsets(nums, k))
}
