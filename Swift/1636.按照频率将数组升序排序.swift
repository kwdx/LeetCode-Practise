/*
 * @lc app=leetcode.cn id=1636 lang=swift
 *
 * [1636] 按照频率将数组升序排序
 */

// @lc code=start
class Solution {
    func frequencySort(_ nums: [Int]) -> [Int] {
        var cnts = [Int: Int]()
        for num in nums {
            cnts[num] = 1 + (cnts[num] ?? 0)
        }
        return nums.sorted {
            if cnts[$0]! == cnts[$1]! {
                return $0 > $1
            }
            return cnts[$0]! < cnts[$1]!
        }
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: [Int]
    
    /**
     输入：nums = [1,1,2,2,2,3]
     输出：[3,1,1,2,2,2]
     解释：'3' 频率为 1，'1' 频率为 2，'2' 频率为 3 。
     */
    nums = [1,1,2,2,2,3]
    res = [3,1,1,2,2,2]
    assert(res == Solution().frequencySort(nums))
    
    /**
     输入：nums = [2,3,1,3,2]
     输出：[1,3,3,2,2]
     解释：'2' 和 '3' 频率都为 2 ，所以它们之间按照数值本身降序排序。
     */
    nums = [2,3,1,3,2]
    res = [1,3,3,2,2]
    assert(res == Solution().frequencySort(nums))
    
    /**
     输入：nums = [1,1,2,2,2,3]
     输出：[3,1,1,2,2,2]
     */
    nums = [1,1,2,2,2,3]
    res = [3,1,1,2,2,2]
    assert(res == Solution().frequencySort(nums))
}
