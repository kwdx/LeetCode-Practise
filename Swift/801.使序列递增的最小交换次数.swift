/*
 * @lc app=leetcode.cn id=801 lang=swift
 *
 * [801] 使序列递增的最小交换次数
 */

// @lc code=start
class Solution {
    func minSwap(_ nums1: [Int], _ nums2: [Int]) -> Int {
        let n = nums1.count
        var a = 0
        var b = 1
        for i in 1..<n {
            let at = a
            let bt = b
            a = n
            b = n
            if nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1] {
                a = min(a, at)
                b = min(b, bt + 1)
            }
            if nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1] {
                a = min(a, bt)
                b = min(b, at + 1)
            }
        }
        return min(a, b)
    }
}
// @lc code=end

func main() {
    var nums1: [Int]
    var nums2: [Int]
    var res: Int
    
    /**
     输入: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
     输出: 1
     解释:
     交换 A[3] 和 B[3] 后，两个数组如下:
     A = [1, 3, 5, 7] ， B = [1, 2, 3, 4]
     两个数组均为严格递增的。
     */
    nums1 = [1,3,5,4]
    nums2 = [1,2,3,7]
    res = 1
    assert(res == Solution().minSwap(nums1, nums2))
    
    /**
     输入: nums1 = [0,3,5,8,9], nums2 = [2,1,4,6,9]
     输出: 1
     */
    nums1 = [0,3,5,8,9]
    nums2 = [2,1,4,6,9]
    res = 1
    assert(res == Solution().minSwap(nums1, nums2))
}
