/*
 * @lc app=leetcode.cn id=2006 lang=swift
 *
 * [2006] 差的绝对值为 K 的数对数目
 */

// @lc code=start
class Solution {
    func countKDifference(_ nums: [Int], _ k: Int) -> Int {
        var cnts: [Int: Int] = [:]
        var ans = 0
        for num in nums {
            ans += (cnts[num - k] ?? 0) + (cnts[num + k] ?? 0)
            cnts[num] = 1 + (cnts[num] ?? 0)
        }
        return ans
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var k: Int
    var res: Int
    
    /**
     输入：nums = [1,2,2,1], k = 1
     输出：4
     解释：差的绝对值为 1 的数对为：
     - [1,2,2,1]
     - [1,2,2,1]
     - [1,2,2,1]
     - [1,2,2,1]
     */
    nums = [1,2,2,1]
    k = 1
    res = 4
    assert(res == Solution().countKDifference(nums, k))
    
    /**
     输入：nums = [1,3], k = 3
     输出：0
     解释：没有任何数对差的绝对值为 3 。
     */
    nums = [1,3]
    k = 3
    res = 0
    assert(res == Solution().countKDifference(nums, k))
    
    /**
     输入：nums = [3,2,1,5,4], k = 2
     输出：3
     解释：差的绝对值为 2 的数对为：
     - [3,2,1,5,4]
     - [3,2,1,5,4]
     - [3,2,1,5,4]
     */
    nums = [3,2,1,5,4]
    k = 2
    res = 3
    assert(res == Solution().countKDifference(nums, k))
}
