/*
 * @lc app=leetcode.cn id=1296 lang=swift
 *
 * [1296] 划分数组为连续数字的集合
 */

// @lc code=start
class Solution {
    func isPossibleDivide(_ nums: [Int], _ k: Int) -> Bool {
        var pq = PriorityQueue<Int>()
        var maps: [Int: Int] = [:]
        for num in nums {
            pq.push(num)
            maps[num] = 1 + (maps[num] ?? 0)
        }
        while let val = pq.pop() {
            if maps[val]! == 0 {
                continue
            }
            maps[val] = maps[val]! - 1
            for i in 1..<k {
                if let cnt = maps[val - i], cnt > 0 {
                    maps[val - i] = maps[val - i]! - 1
                } else {
                    return false
                }
            }
        }
        return true
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var k: Int
    var res: Bool
    
    /**
     输入：nums = [1,2,3,3,4,4,5,6], k = 4
     输出：true
     解释：数组可以分成 [1,2,3,4] 和 [3,4,5,6]。
     */
    nums = [1,2,3,3,4,4,5,6]
    k = 4
    res = true
    assert(res == Solution().isPossibleDivide(nums, k))
    
    /**
     输入：nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
     输出：true
     解释：数组可以分成 [1,2,3] , [2,3,4] , [3,4,5] 和 [9,10,11]。
     */
    nums = [3,2,1,2,3,4,3,4,5,9,10,11]
    k = 3
    res = true
    assert(res == Solution().isPossibleDivide(nums, k))
    
    /**
     输入：nums = [3,3,2,2,1,1], k = 3
     输出：true
     */
    nums = [3,3,2,2,1,1]
    k = 3
    res = true
    assert(res == Solution().isPossibleDivide(nums, k))
    
    /**
     输入：nums = [1,2,3,4], k = 3
     输出：false
     解释：数组不能分成几个大小为 3 的子数组。
     */
    nums = [1,2,3,4]
    k = 3
    res = false
    assert(res == Solution().isPossibleDivide(nums, k))
}
