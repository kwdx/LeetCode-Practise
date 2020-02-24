//
//  _215_数组中的第K个最大元素.swift
//  LeetCode-Swift
//
//  Created by warden on 2020/2/23.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/kth-largest-element-in-an-array/

import Foundation

class _215_数组中的第K个最大元素 {
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

/**
示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
 
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
*/
func test_215() {
    let nums = [3,2,1,5,6,4]
    let k = 2
//    let nums = [3,2,3,1,2,4,5,5,6]
//    let k = 4
    let solution = _215_数组中的第K个最大元素()
    print(solution.findKthLargest(nums, k))
}

