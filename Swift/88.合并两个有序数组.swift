/*
 * @lc app=leetcode.cn id=88 lang=swift
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
    func merge(_ nums1: inout [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
        for i in (n..<(m+n)).reversed() {
            nums1[i] = nums1[i - n];
        }
        var idx1 = 0
        var idx2 = 0
        while idx1 < m && idx2 < n {
            if nums1[idx1 + n] <= nums2[idx2] {
                nums1[idx1 + idx2] = nums1[idx1 + n]
                idx1 += 1
            } else {
                nums1[idx1 + idx2] = nums2[idx2]
                idx2 += 1
            }
        }
        while idx2 < n {
            nums1[idx1 + idx2] = nums2[idx2]
            idx2 += 1
        }
    }
}
// @lc code=end

func main() {
    var nums1: [Int]
    var m: Int
    var nums2: [Int]
    var n: Int
    var res: [Int]
    
    /**
     输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
     输出：[1,2,2,3,5,6]
     解释：需要合并 [1,2,3] 和 [2,5,6] 。
     合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。
     */
    nums1 = [1,2,3,0,0,0]
    m = 3
    nums2 = [2,5,6]
    n = 3
    res = [1,2,2,3,5,6]
    Solution().merge(&nums1, m, nums2, n)
    assert(res == nums1)
    
    /**
     输入：nums1 = [1], m = 1, nums2 = [], n = 0
     输出：[1]
     解释：需要合并 [1] 和 [] 。
     合并结果是 [1] 。
     */
    nums1 = [1]
    m = 1
    nums2 = []
    n = 0
    res = [1]
    Solution().merge(&nums1, m, nums2, n)
    assert(res == nums1)
}
