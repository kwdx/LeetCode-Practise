/*
 * @lc app=leetcode.cn id=215 lang=swift
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
    func findKthLargest(_ nums: [Int], _ k: Int) -> Int {
        var numsArr = nums
        var numSize = nums.count
        for i in stride(from: numSize >> 1 - 1, through: 0, by: -1) {
            siftDown(&numsArr, numSize, i)
        }
        for i in 0..<k {
            let tmp = numsArr[numSize - 1]
            numsArr[numSize - 1] = numsArr[0]
            numsArr[0] = tmp
            numSize -= 1;
            if i < k - 1 {
                siftDown(&numsArr, numSize, 0);
            }
        }
        
        return numsArr[nums.count - k]
    }
    
    func siftDown(_ nums: inout [Int], _ size: Int, _ index: Int) {
        let num = nums[index]
        let half = size >> 1
        var idx = index
        while idx < half {
            var childIdx = (idx << 1) + 1
            var child = nums[childIdx]
            let rightIdx = childIdx + 1
            
            if rightIdx < size && nums[rightIdx] > child {
                child = nums[rightIdx]
                childIdx = rightIdx
            }
            if num >= child {
                break
            }
            nums[idx] = child
            idx = childIdx
        }
        nums[idx] = num
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var k: Int
    var res: Int
    
    /**
     输入: [3,2,1,5,6,4] 和 k = 2
     输出: 5
     */
    nums = [3,2,1,5,6,4]
    k = 2
    res = 5
    assert(res == Solution().findKthLargest(nums, k))
    
    /**
     输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
     输出: 4
     */
    nums = [3,2,3,1,2,4,5,5,6]
    k = 4
    res = 4
    assert(res == Solution().findKthLargest(nums, k))
}
