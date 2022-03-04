/*
 * @lc app=leetcode.cn id=2104 lang=swift
 *
 * [2104] 子数组范围和
 */

// @lc code=start
class Solution {
    func subArrayRanges(_ nums: [Int]) -> Int {
        let n = nums.count
        var minLeft = [Int](repeating: 0, count: n)
        var maxLeft = [Int](repeating: 0, count: n)
        var minRight = [Int](repeating: 0, count: n)
        var maxRight = [Int](repeating: 0, count: n)
        
        var minStack = [Int](), maxStack = [Int]()
        
        for i in 0..<n {
            while let top = minStack.last, nums[top] > nums[i] {
                minStack.removeLast()
            }
            minLeft[i] = minStack.isEmpty ? -1 : minStack.last!
            minStack.append(i)
            
            while let top = maxStack.last, nums[top] <= nums[i] {
                maxStack.removeLast()
            }
            maxLeft[i] = maxStack.isEmpty ? -1 : maxStack.last!
            maxStack.append(i)
        }
        
        minStack = []
        maxStack = []
        
        for i in (0..<n).reversed() {
            while let top = minStack.last, nums[top] >= nums[i] {
                minStack.removeLast()
            }
            minRight[i] = minStack.isEmpty ? n : minStack.last!
            minStack.append(i)
            
            while let top = maxStack.last, nums[top] < nums[i] {
                maxStack.removeLast()
            }
            maxRight[i] = maxStack.isEmpty ? n : maxStack.last!
            maxStack.append(i)
        }
        
        var sumMax = 0, sumMin = 0
        for i in 0..<n {
            sumMax += (maxRight[i] - i) * (i - maxLeft[i]) * nums[i]
            sumMin += (minRight[i] - i) * (i - minLeft[i]) * nums[i]
        }
        return sumMax - sumMin
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: Int
    
    /**
     输入：nums = [1,2,3]
     输出：4
     解释：nums 的 6 个子数组如下所示：
     [1]，范围 = 最大 - 最小 = 1 - 1 = 0
     [2]，范围 = 2 - 2 = 0
     [3]，范围 = 3 - 3 = 0
     [1,2]，范围 = 2 - 1 = 1
     [2,3]，范围 = 3 - 2 = 1
     [1,2,3]，范围 = 3 - 1 = 2
     所有范围的和是 0 + 0 + 0 + 1 + 1 + 2 = 4
     */
    nums = [1,2,3]
    res = 4
    assert(res == Solution().subArrayRanges(nums))
    
    /**
     输入：nums = [1,3,3]
     输出：4
     解释：nums 的 6 个子数组如下所示：
     [1]，范围 = 最大 - 最小 = 1 - 1 = 0
     [3]，范围 = 3 - 3 = 0
     [3]，范围 = 3 - 3 = 0
     [1,3]，范围 = 3 - 1 = 2
     [3,3]，范围 = 3 - 3 = 0
     [1,3,3]，范围 = 3 - 1 = 2
     所有范围的和是 0 + 0 + 0 + 2 + 0 + 2 = 4
     */
    nums = [1,3,3]
    res = 4
    assert(res == Solution().subArrayRanges(nums))
    
    /**
     输入：nums = [4,-2,-3,4,1]
     输出：59
     解释：nums 中所有子数组范围的和是 59
     */
    nums = [4,-2,-3,4,1]
    res = 59
    assert(res == Solution().subArrayRanges(nums))
}
