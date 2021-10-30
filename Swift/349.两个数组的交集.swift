/*
 * @lc app=leetcode.cn id=349 lang=swift
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
    func intersection(_ nums1: [Int], _ nums2: [Int]) -> [Int] {
        var set1 = Set(nums1)
        var res = [Int]()
        for num in nums2 {
            if set1.remove(num) != nil {
                res.append(num)
            }
        }
        return res
    }
}
// @lc code=end

func main() {
    var nums1: [Int]
    var nums2: [Int]
    var res: [Int]
    
    /**
     输入：nums1 = [1,2,2,1], nums2 = [2,2]
     输出：[2]
     */
    nums1 = [1,2,2,1]
    nums2 = [2,2]
    res = [2]
    assert(res == Solution().intersection(nums1, nums2))
    
    /**
     输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
     输出：[9,4]
     */
    nums1 = [4,9,5]
    nums2 = [9,4,9,8,4]
    res = [9,4]
    assert(res == Solution().intersection(nums1, nums2))
}
