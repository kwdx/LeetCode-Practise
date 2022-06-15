/*
 * @lc app=leetcode.cn id=719 lang=swift
 *
 * [719] 找出第 k 小的距离对
 */

// @lc code=start
class Solution {
    func smallestDistancePair(_ nums: [Int], _ k: Int) -> Int {
        let nums_ = nums.sorted()
        var left = 0, right = nums_.last! - nums_.first!
        
        while left <= right {
            let mid = (left + right) >> 1
            var cnt = 0
            var i = 0
            for j in 0..<nums_.count {
                while nums_[j] - nums_[i] > mid {
                    i += 1
                }
                cnt += j - i
            }
            if cnt >= k {
                right = mid - 1
            } else {
                left = mid + 1
            }
        }
        return left
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var k: Int
    var res: Int
    
    /**
     输入：nums = [1,3,1], k = 1
     输出：0
     解释：数对和对应的距离如下：
     (1,3) -> 2
     (1,1) -> 0
     (3,1) -> 2
     距离第 1 小的数对是 (1,1) ，距离为 0 。
     */
    nums = [1,3,1]
    k = 1
    res = 0
    assert(res == Solution().smallestDistancePair(nums, k))
    
    /**
     输入：nums = [1,1,1], k = 2
     输出：0
     */
    nums = [1,1,1]
    k = 2
    res = 0
    assert(res == Solution().smallestDistancePair(nums, k))
    
    /**
     输入：nums = [1,6,1], k = 3
     输出：5
     */
    nums = [1,6,1]
    k = 3
    res = 5
    assert(res == Solution().smallestDistancePair(nums, k))
}
