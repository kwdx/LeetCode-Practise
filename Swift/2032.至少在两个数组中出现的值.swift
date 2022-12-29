/*
 * @lc app=leetcode.cn id=2032 lang=swift
 *
 * [2032] 至少在两个数组中出现的值
 */

// @lc code=start
class Solution {
    func twoOutOfThree(_ nums1: [Int], _ nums2: [Int], _ nums3: [Int]) -> [Int] {
        var map = [Int: Int]()
        for num in nums1 {
            map[num] = 1
        }
        for num in nums2 {
            map[num] = 2 | (map[num] ?? 0)
        }
        for num in nums3 {
            map[num] = 4 | (map[num] ?? 0)
        }
        var ans = [Int]()
        for (key, value) in map {
            if (value & (value - 1)) > 0 {
                ans.append(key)
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var nums1: [Int]
    var nums2: [Int]
    var nums3: [Int]
    var res: [Int]
    
    /**
     输入：nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
     输出：[3,2]
     解释：至少在两个数组中出现的所有值为：
     - 3 ，在全部三个数组中都出现过。
     - 2 ，在数组 nums1 和 nums2 中出现过。
     */
    nums1 = [1,1,3,2]
    nums2 = [2,3]
    nums3 = [3]
    res = [3,2]
    assert(res.sorted() == Solution().twoOutOfThree(nums1, nums2, nums3).sorted())
    
    /**
     输入：nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
     输出：[2,3,1]
     解释：至少在两个数组中出现的所有值为：
     - 2 ，在数组 nums2 和 nums3 中出现过。
     - 3 ，在数组 nums1 和 nums2 中出现过。
     - 1 ，在数组 nums1 和 nums3 中出现过。
     */
    nums1 = [3,1]
    nums2 = [2,3]
    nums3 = [1,2]
    res = [2,3,1]
    assert(res.sorted() == Solution().twoOutOfThree(nums1, nums2, nums3).sorted())

    /**
     输入：nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
     输出：[]
     解释：不存在至少在两个数组中出现的值。
     */
    nums1 = [1,2,2]
    nums2 = [4,3,3]
    nums3 = [5]
    res = []
    assert(res.sorted() == Solution().twoOutOfThree(nums1, nums2, nums3).sorted())
}
