/*
 * @lc app=leetcode.cn id=658 lang=swift
 *
 * [658] 找到 K 个最接近的元素
 */

// @lc code=start
class Solution {
    func findClosestElements(_ arr: [Int], _ k: Int, _ x: Int) -> [Int] {
        let nums = arr.sorted { a, b in
            abs(a - x) < abs(b - x) || (abs(a - x) == abs(b - x) && a < b)
        }
        return nums[0..<k].sorted()
    }
}
// @lc code=end

func main() {
    var arr: [Int]
    var k: Int
    var x: Int
    var res: [Int]
    
    /**
     输入：arr = [1,2,3,4,5], k = 4, x = 3
     输出：[1,2,3,4]
     */
    arr = [1,2,3,4,5]
    k = 4
    x = 3
    res = [1,2,3,4]
    assert(res == Solution().findClosestElements(arr, k, x))
    
    /**
     输入：arr = [1,2,3,4,5], k = 4, x = -1
     输出：[1,2,3,4]
     */
    arr = [1,2,3,4,5]
    k = 4
    x = 1
    res = [1,2,3,4]
    assert(res == Solution().findClosestElements(arr, k, x))
}
