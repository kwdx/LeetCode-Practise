//
//  _347_前K个高频元素.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/top-k-frequent-elements/

import Foundation

class _347_前K个高频元素 {
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

/**
 输入: nums = [1,1,1,2,2,3], k = 2
 输出: [1,2]

 输入: nums = [1], k = 1
 输出: [1]
*/
func test_347() {
    let nums = [3, 1, 2, 1, 3, 2, 1, 3]
    let solution = _347_前K个高频元素()
    print(solution.topKFrequent(nums, 2))
}
