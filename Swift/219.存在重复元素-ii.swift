/*
 * @lc app=leetcode.cn id=219 lang=swift
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
    func containsNearbyDuplicate(_ nums: [Int], _ k: Int) -> Bool {
        var sets: Set<Int> = []
        for i in 0..<nums.count {
            if i > k {
                sets.remove(nums[i - k - 1])
            }
            if sets.contains(nums[i]) {
                return true
            }
            sets.insert(nums[i])
        }
        return false
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var k: Int
    var res: Bool
    
    /**
     输入：nums = [1,2,3,1], k = 3
     输出：true
     */
    nums = [1,2,3,1]
    k = 3
    res = true
    assert(res == Solution().containsNearbyDuplicate(nums, k))
    
    /**
     输入：nums = [1,0,1,1], k = 1
     输出：true
     */
    nums = [1,0,1,1]
    k = 1
    res = true
    assert(res == Solution().containsNearbyDuplicate(nums, k))
    
    /**
     输入：nums = [1,2,3,1,2,3], k = 2
     输出：false
     */
    nums = [1,2,3,1,2,3]
    k = 2
    res = false
    assert(res == Solution().containsNearbyDuplicate(nums, k))
}
