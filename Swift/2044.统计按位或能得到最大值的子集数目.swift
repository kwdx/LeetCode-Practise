/*
 * @lc app=leetcode.cn id=2044 lang=swift
 *
 * [2044] 统计按位或能得到最大值的子集数目
 */

// @lc code=start
class Solution {
    private var nums: [Int] = []
    private var maxVal = 0
    private var cnt = 0
    
    func countMaxOrSubsets(_ nums: [Int]) -> Int {
        self.nums = nums
        dfs(0, 0)
        return cnt
    }
    
    private func dfs(_ pos: Int, _ val: Int) {
        if pos == nums.count {
            if val > maxVal {
                maxVal = val
                cnt = 1
            } else if val == maxVal {
                cnt += 1
            }
            return
        }
        dfs(pos + 1, val)
        dfs(pos + 1, val | nums[pos])
    }
}
// @lc code=end

func main() {
    // insert code here...
    
    var nums: [Int]
    var res: Int
    
    /**
     输入：nums = [3,1]
     输出：2
     解释：子集按位或能得到的最大值是 3 。有 2 个子集按位或可以得到 3 ：
     - [3]
     - [3,1]
     */
    nums = [3,1]
    res = 2
    assert(res == Solution().countMaxOrSubsets(nums))
    
    /**
     输入：nums = [2,2,2]
     输出：7
     解释：[2,2,2] 的所有非空子集的按位或都可以得到 2 。总共有 23 - 1 = 7 个子集。
     */
    nums = [2,2,2]
    res = 7
    assert(res == Solution().countMaxOrSubsets(nums))
    
    /**
     输入：nums = [3,2,1,5]
     输出：6
     解释：子集按位或可能的最大值是 7 。有 6 个子集按位或可以得到 7 ：
     - [3,5]
     - [3,1,5]
     - [3,2,5]
     - [3,2,1,5]
     - [2,5]
     - [2,1,5]
     */
    nums = [3,2,1,5]
    res = 6
    assert(res == Solution().countMaxOrSubsets(nums))
}

