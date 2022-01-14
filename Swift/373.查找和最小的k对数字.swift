/*
 * @lc app=leetcode.cn id=373 lang=swift
 *
 * [373] 查找和最小的K对数字
 */

// @lc code=start
class Solution {
    var flag = true
    func kSmallestPairs(_ nums1: [Int], _ nums2: [Int], _ k: Int) -> [[Int]] {
        var ans: [[Int]] = []
        let n = nums1.count, m = nums2.count
        if n > m && flag {
            flag = false
            return kSmallestPairs(nums2, nums1, k)
        }
        var q = PriorityQueue<[Int]> {
            nums1[$0[0]] + nums2[$0[1]] > nums1[$1[0]] + nums2[$1[1]]
        }
        for i in 0..<min(n, k) {
            q.push([i, 0])
        }
        while ans.count < k, let element = q.pop() {
            if flag {
                ans.append([nums1[element[0]], nums2[element[1]]])
            } else {
                ans.append([nums2[element[1]], nums1[element[0]]])
            }
            if element[1] + 1 < m {
                q.push([element[0], element[1] + 1])
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var nums1: [Int]
    var nums2: [Int]
    var k: Int
    var res: [[Int]]
    
    /**
     输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
     输出: [1,2],[1,4],[1,6]
     解释: 返回序列中的前 3 对数：
          [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
     */
    nums1 = [1,7,11]
    nums2 = [2,4,6]
    k = 3
    res = [[1,2],[1,4],[1,6]]
    assert(res == Solution().kSmallestPairs(nums1, nums2, k))
    
    /**
     输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
     输出: [1,1],[1,1]
     解释: 返回序列中的前 2 对数：
          [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
     */
    nums1 = [1,1,2]
    nums2 = [1,2,3]
    k = 2
    res = [[1,1],[1,1]]
    assert(res == Solution().kSmallestPairs(nums1, nums2, k))
    
    /**
     输入: nums1 = [1,2], nums2 = [3], k = 3
     输出: [1,3],[2,3]
     解释: 也可能序列中所有的数对都被返回:[1,3],[2,3]
     */
    nums1 = [1,2]
    nums2 = [3]
    k = 3
    res = [[1,3],[2,3]]
    assert(res == Solution().kSmallestPairs(nums1, nums2, k))
}
