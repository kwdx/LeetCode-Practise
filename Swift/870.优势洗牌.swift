/*
 * @lc app=leetcode.cn id=870 lang=swift
 *
 * [870] 优势洗牌
 */

// @lc code=start
class Solution {
    func advantageCount(_ nums1: [Int], _ nums2: [Int]) -> [Int] {
        var q = PriorityQueue<(Int, Int)> { $0.0 < $1.0 }
        for i in 0..<nums2.count {
            q.push((nums2[i], i))
        }
        let nums1 = nums1.sorted()
        var ans = nums1
        var left = 0
        var right = nums1.count - 1
        while left <= right {
            let top = q.pop()!
            if nums1[right] > top.0 {
                // 够大
                ans[top.1] = nums1[right]
                right -= 1
            } else {
                // 不够大
                ans[top.1] = nums1[left]
                left += 1
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var nums1: [Int]
    var nums2: [Int]
    var res: [Int]
    
    /**
     输入：nums1 = [2,7,11,15], nums2 = [1,10,4,11]
     输出：[2,11,7,15]
     */
    nums1 = [2,7,11,15]
    nums2 = [1,10,4,11]
    res = [2,11,7,15]
    assert(res == Solution().advantageCount(nums1, nums2))
    
    /**
     输入：nums1 = [12,24,8,32], nums2 = [13,25,32,11]
     输出：[24,32,8,12]
     */
    nums1 = [12,24,8,32]
    nums2 = [13,25,32,11]
    res = [24,32,8,12]
    assert(res == Solution().advantageCount(nums1, nums2))
}
