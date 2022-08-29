/*
 * @lc app=leetcode.cn id=1470 lang=swift
 *
 * [1470] 重新排列数组
 */

// @lc code=start
class Solution {
    func shuffle(_ nums: [Int], _ n: Int) -> [Int] {
        var ans = [Int]()
        var i = 0, j = n
        while i < n {
            ans.append(nums[i])
            ans.append(nums[j])
            i += 1
            j += 1
        }
        return ans
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var n: Int
    var res: [Int]
    
    /**
     输入：nums = [2,5,1,3,4,7], n = 3
     输出：[2,3,5,4,1,7]
     解释：由于 x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 ，所以答案为 [2,3,5,4,1,7]
     */
    nums = [2,5,1,3,4,7]
    n = 3
    res = [2,3,5,4,1,7]
    assert(res == Solution().shuffle(nums, n))
    
    /**
     输入：nums = [1,2,3,4,4,3,2,1], n = 4
     输出：[1,4,2,3,3,2,4,1]
     */
    nums = [1,2,3,4,4,3,2,1]
    n = 4
    res = [1,4,2,3,3,2,4,1]
    assert(res == Solution().shuffle(nums, n))
    
    /**
     输入：nums = [1,1,2,2], n = 2
     输出：[1,2,1,2]
     */
    nums = [1,1,2,2]
    n = 2
    res = [1,2,1,2]
    assert(res == Solution().shuffle(nums, n))
}
