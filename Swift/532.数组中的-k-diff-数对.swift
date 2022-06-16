/*
 * @lc app=leetcode.cn id=532 lang=swift
 *
 * [532] 数组中的 k-diff 数对
 */

// @lc code=start
class Solution {
    func findPairs(_ nums: [Int], _ k: Int) -> Int {
        guard nums.count > 1 else {
            return 0
        }
        var ans = 0
        let n = nums.count
        let nums_ = nums.sorted()
        var left = 0, right = 0
        while left < n - 1 && right < n {
            if left > 0 && nums_[left] == nums_[left - 1] {
                left += 1
                continue
            }
            while right <= left {
                right += 1
            }
            while right < n && (nums_[right] < nums_[left] + k) {
                right += 1
            }
            if right < n && (nums_[right] == nums_[left] + k) {
                ans += 1
            }
            left += 1
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
     输入：nums = [3, 1, 4, 1, 5], k = 2
     输出：2
     解释：数组中有两个 2-diff 数对, (1, 3) 和 (3, 5)。
     尽管数组中有两个1，但我们只应返回不同的数对的数量。
     */
    nums = [3, 1, 4, 1, 5]
    k = 2
    res = 2
//    assert(res == Solution().findPairs(nums, k))
    
    /**
     输入：nums = [1, 2, 3, 4, 5], k = 1
     输出：4
     解释：数组中有四个 1-diff 数对, (1, 2), (2, 3), (3, 4) 和 (4, 5)。
     */
    nums = [1, 2, 3, 4, 5]
    k = 1
    res = 4
    assert(res == Solution().findPairs(nums, k))
    
    /**
     输入：nums = [1, 3, 1, 5, 4], k = 0
     输出：1
     解释：数组中只有一个 0-diff 数对，(1, 1)。
     */
    nums = [1, 3, 1, 5, 4]
    k = 0
    res = 1
    assert(res == Solution().findPairs(nums, k))
}
