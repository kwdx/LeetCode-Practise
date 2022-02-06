/*
 * @lc app=leetcode.cn id=1748 lang=swift
 *
 * [1748] 唯一元素的和
 */

// @lc code=start
class Solution {
    func sumOfUnique(_ nums: [Int]) -> Int {
        var numSet: [Int: Int] = [:]
        return nums.reduce(0) {
            let cnt = numSet[$1] ?? 0
            numSet[$1] = 1 + cnt
            if cnt == 0 {
                return $0 + $1
            } else if cnt == 1 {
                return $0 - $1
            } else {
                return $0
            }
        }
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: Int
    
    /**
     输入：nums = [1,2,3,2]
     输出：4
     解释：唯一元素为 [1,3] ，和为 4 。
     */
    nums = [1,2,3,2]
    res = 4
    assert(res == Solution().sumOfUnique(nums))
    
    /**
     输入：nums = [1,1,1,1,1]
     输出：0
     解释：没有唯一元素，和为 0 。
     */
    nums = [1,1,1,1,1]
    res = 0
    assert(res == Solution().sumOfUnique(nums))
    
    /**
     输入：nums = [1,2,3,4,5]
     输出：15
     解释：唯一元素为 [1,2,3,4,5] ，和为 15 。
     */
    nums = [1,2,3,4,5]
    res = 15
    assert(res == Solution().sumOfUnique(nums))
}

