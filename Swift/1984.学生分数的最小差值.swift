/*
 * @lc app=leetcode.cn id=1984 lang=swift
 *
 * [1984] 学生分数的最小差值
 */

// @lc code=start
class Solution {
    func minimumDifference(_ nums: [Int], _ k: Int) -> Int {
        let nums_ = nums.sorted()
        var ans = nums_.last!
        for i in 0...nums_.count-k {
            ans = min(ans, nums_[i + k - 1] - nums_[i])
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
     输入：nums = [90], k = 1
     输出：0
     解释：选出 1 名学生的分数，仅有 1 种方法：
     - [90] 最高分和最低分之间的差值是 90 - 90 = 0
     可能的最小差值是 0
     */
    nums = [90]
    k = 1
    res = 0
    assert(res == Solution().minimumDifference(nums, k))
    
    /**
     输入：nums = [9,4,1,7], k = 2
     输出：2
     解释：选出 2 名学生的分数，有 6 种方法：
     - [9,4,1,7] 最高分和最低分之间的差值是 9 - 4 = 5
     - [9,4,1,7] 最高分和最低分之间的差值是 9 - 1 = 8
     - [9,4,1,7] 最高分和最低分之间的差值是 9 - 7 = 2
     - [9,4,1,7] 最高分和最低分之间的差值是 4 - 1 = 3
     - [9,4,1,7] 最高分和最低分之间的差值是 7 - 4 = 3
     - [9,4,1,7] 最高分和最低分之间的差值是 7 - 1 = 6
     可能的最小差值是 2
     */
    nums = [9,4,1,7]
    k = 2
    res = 2
    assert(res == Solution().minimumDifference(nums, k))
}
