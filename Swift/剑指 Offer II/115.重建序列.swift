//
//  115.重建序列.swift
//  Cpp
//
//  Created by warden on 2022/7/23.
//

import Foundation

// @lc code=start
class Solution {
    func sequenceReconstruction(_ nums: [Int], _ sequences: [[Int]]) -> Bool {
        let n = nums.count
        var indegress = [Int](repeating: 0, count: n + 1)
        var graph = [Set<Int>](repeating: [], count: n + 1)
        for sequence in sequences {
            for i in 1..<sequence.count {
                let prev = sequence[i - 1], next = sequence[i]
                if !graph[prev].contains(next) {
                    graph[prev].insert(next)
                    indegress[next] += 1
                }
            }
        }
        var q = [Int]()
        for i in 1...n {
            if indegress[i] == 0 {
                q.append(i)
            }
        }
        while !q.isEmpty {
            if q.count > 1 {
                return false
            }
            let num = q.removeFirst()
            for next in graph[num] {
                indegress[next] -= 1
                if indegress[next] == 0 {
                    q.append(next)
                }
            }
        }
        return true
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var sequences: [[Int]]
    var res: Bool

    /**
     输入：nums = [1,2,3], sequences = [[1,2],[1,3]]
     输出：false
     解释：有两种可能的超序列：[1,2,3]和[1,3,2]。
     序列 [1,2] 是[1,2,3]和[1,3,2]的子序列。
     序列 [1,3] 是[1,2,3]和[1,3,2]的子序列。
     因为 nums 不是唯一最短的超序列，所以返回false。
     */
    nums = [1,2,3]
    sequences = [[1,2],[1,3]]
    res = false
    assert(res == Solution().sequenceReconstruction(nums, sequences))

    /**
     输入：nums = [1,2,3], sequences = [[1,2]]
     输出：false
     解释：最短可能的超序列为 [1,2]。
     序列 [1,2] 是它的子序列：[1,2]。
     因为 nums 不是最短的超序列，所以返回false。
     */
    nums = [1,2,3]
    sequences = [[1,2]]
    res = false
    assert(res == Solution().sequenceReconstruction(nums, sequences))
    
    /**
     输入：nums = [1,2,3], sequences = [[1,2],[1,3],[2,3]]
     输出：true
     解释：最短可能的超序列为[1,2,3]。
     序列 [1,2] 是它的一个子序列：[1,2,3]。
     序列 [1,3] 是它的一个子序列：[1,2,3]。
     序列 [2,3] 是它的一个子序列：[1,2,3]。
     因为 nums 是唯一最短的超序列，所以返回true。
     */
    nums = [1,2,3]
    sequences = [[1,2],[1,3],[2,3]]
    res = true
    assert(res == Solution().sequenceReconstruction(nums, sequences))
}
