/*
 * @lc app=leetcode.cn id=1775 lang=swift
 *
 * [1775] 通过最少操作次数使数组的和相等
 */

// @lc code=start
class Solution {
    func minOperations(_ nums1: [Int], _ nums2: [Int]) -> Int {
        var nums1 = nums1
        var nums2 = nums2
        var sum1 = nums1.reduce(0, +)
        var sum2 = nums2.reduce(0, +)
        if sum1 == sum2 {
            return 0
        }
        if sum1 < sum2 {
            swap(&sum1, &sum2)
            swap(&nums1, &nums2)
        }
        
        var diff = sum1 - sum2
        let n1 = nums1.count
        let n2 = nums2.count
        
        nums1 = nums1.sorted()
        nums2 = nums2.sorted()
        
        var ans = 0
        var i = n1 - 1
        var j = 0
        // nums1从后到前变小，nums2从前到后变大
        while i >= 0 || j < n2 {
            var diff1 = 0
            var diff2 = 0
            
            if i >= 0 {
                diff1 = nums1[i] - 1
            }
            if j < n2 {
                diff2 = 6 - nums2[j]
            }
            
            let maxDiff = max(diff1, diff2)
            if maxDiff == 0 {
                return -1
            }
            if maxDiff >= diff {
                return ans + 1
            }
            if diff1 == maxDiff {
                i -= 1
            } else {
                j += 1
            }
            
            diff -= maxDiff
            ans += 1
        }
        return -1
    }
}
// @lc code=end

func main() {
    var nums1: [Int]
    var nums2: [Int]
    var res: Int

    /**
     输入：nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
     输出：3
     解释：你可以通过 3 次操作使 nums1 中所有数的和与 nums2 中所有数的和相等。以下数组下标都从 0 开始。
     - 将 nums2[0] 变为 6 。 nums1 = [1,2,3,4,5,6], nums2 = [6,1,2,2,2,2] 。
     - 将 nums1[5] 变为 1 。 nums1 = [1,2,3,4,5,1], nums2 = [6,1,2,2,2,2] 。
     - 将 nums1[2] 变为 2 。 nums1 = [1,2,2,4,5,1], nums2 = [6,1,2,2,2,2] 。
     */
    nums1 = [1,2,3,4,5,6]
    nums2 = [1,1,2,2,2,2]
    res = 3
    assert(res == Solution().minOperations(nums1, nums2))
    
    /**
     输入：nums1 = [1,1,1,1,1,1,1], nums2 = [6]
     输出：-1
     解释：没有办法减少 nums1 的和或者增加 nums2 的和使二者相等。
     */
    nums1 = [1,1,1,1,1,1,1]
    nums2 = [6]
    res = -1
    assert(res == Solution().minOperations(nums1, nums2))
    
    /**
     输入：nums1 = [6,6], nums2 = [1]
     输出：3
     解释：你可以通过 3 次操作使 nums1 中所有数的和与 nums2 中所有数的和相等。以下数组下标都从 0 开始。
     - 将 nums1[0] 变为 2 。 nums1 = [2,6], nums2 = [1] 。
     - 将 nums1[1] 变为 2 。 nums1 = [2,2], nums2 = [1] 。
     - 将 nums2[0] 变为 4 。 nums1 = [2,2], nums2 = [4] 。
     */
    nums1 = [6,6]
    nums2 = [1]
    res = 3
    assert(res == Solution().minOperations(nums1, nums2))
}
