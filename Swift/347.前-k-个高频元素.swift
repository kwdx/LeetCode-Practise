/*
 * @lc app=leetcode.cn id=347 lang=swift
 *
 * [347] 前 K 个高频元素
 */

import Foundation

// @lc code=start
class Solution {
    func topKFrequent(_ nums: [Int], _ k: Int) -> [Int] {
        var counts = [Int: Int]()
        for num in nums {
            counts[num] = (counts[num] ?? 0) + 1
        }
        var entries = [(Int, Int)]()
        for item in counts {
            entries.append(item)
        }
        
        var begin = 0
        var end = entries.count
        var pivotIdx = 0
        let resultIndex = k - 1;
        pivotIdx = pivotIndex(&entries, begin, end)
        while pivotIdx != resultIndex {
            if pivotIdx > resultIndex {
                end = pivotIdx;
            } else {
                begin = pivotIdx + 1;
            }
            pivotIdx = pivotIndex(&entries, begin, end)
        }
        
        var result = [Int]()
        for i in 0..<k {
            result.append(entries[i].0)
        }
        
        return result
    }
    
    private func pivotIndex(_ entries : inout [(Int, Int)], _ begin: Int, _ end: Int) -> Int {
//        var entries = entries
        var begin = begin
        var end = end
        
        let newBegin = begin + Int(arc4random()) % (end - begin)
        let tmp = entries[begin]
        entries[begin] = entries[newBegin]
        entries[newBegin] = tmp
        
        let pivot = entries[begin]
        end -= 1
        while begin < end {
            while begin < end {
                if pivot.1 > entries[end].1 {
                    end -= 1
                } else {
                    entries[begin] = entries[end]
                    begin += 1
                    break
                }
            }
            while begin < end {
                if pivot.1 < entries[begin].1 {
                    begin += 1
                } else {
                    entries[end] = entries[begin]
                    end -= 1
                    break
                }
            }
        }
        entries[begin] = pivot;
        return begin;
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var k: Int
    var res: [Int]
    
    /**
     输入: nums = [1,1,1,2,2,3], k = 2
     输出: [1,2]
     */
    nums = [1,1,1,2,2,3]
    k = 2
    res = [1,2]
    assert(res == Solution().topKFrequent(nums, k))
    
    /**
     输入: nums = [1], k = 1
     输出: [1]
     */
    nums = [1]
    k = 1
    res = [1]
    assert(res == Solution().topKFrequent(nums, k))
}
