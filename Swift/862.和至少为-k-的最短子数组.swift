/*
 * @lc app=leetcode.cn id=862 lang=swift
 *
 * [862] 和至少为 K 的最短子数组
 */

// @lc code=start
class Solution {
    func shortestSubarray(_ nums: [Int], _ k: Int) -> Int {
        let n = nums.count
        var preSums = [Int](repeating: 0, count: n + 1)
        for i in 0..<n {
            preSums[i + 1] = preSums[i] + nums[i]
        }
        var ans = n + 1
        var q = [Int]()
        for i in 0...n {
            let curSum = preSums[i]
            while !q.isEmpty && curSum - preSums[q.first!] >= k {
                ans = min(ans, i - q.removeFirst())
            }
            while !q.isEmpty && preSums[q.last!] >= curSum {
                q.removeLast()
            }
            q.append(i)
        }
        return ans < n + 1 ? ans : -1
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var k: Int
    var res: Int
    
    /**
     输入：nums = [1], k = 1
     输出：1
     */
    nums = [1]
    k = 1
    res = 1
    assert(res == Solution().shortestSubarray(nums, k))
    
    /**
     输入：nums = [1,2], k = 4
     输出：-1
     */
    nums = [1,2]
    k = 4
    res = -1
    assert(res == Solution().shortestSubarray(nums, k))
    
    /**
     输入：nums = [2,-1,2], k = 3
     输出：3
     */
    nums = [2,-1,2]
    k = 3
    res = 3
    assert(res == Solution().shortestSubarray(nums, k))
}
