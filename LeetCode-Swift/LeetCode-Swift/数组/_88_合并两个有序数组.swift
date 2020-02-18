//
//  _88_合并两个有序数组.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/11/28.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/merge-sorted-array/

import Foundation

class _88_合并两个有序数组 {
    func merge(_ nums1: inout [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
        for i in (n..<(m+n)).reversed() {
            nums1[i] = nums1[i - n];
        }
        var idx1 = 0
        var idx2 = 0
        while idx1 < m && idx2 < n {
            if nums1[idx1 + n] <= nums2[idx2] {
                nums1[idx1 + idx2] = nums1[idx1 + n]
                idx1 += 1
            } else {
                nums1[idx1 + idx2] = nums2[idx2]
                idx2 += 1
            }
        }
        while idx2 < n {
            nums1[idx1 + idx2] = nums2[idx2]
            idx2 += 1
        }
    }
}

/**
 输入:
 nums1 = [1,2,3,0,0,0], m = 3
 nums2 = [2,5,6],       n = 3

 输出: [1,2,2,3,5,6]
*/
func test_88() {
    let solution = _88_合并两个有序数组()
    var nums1 = [1, 2, 3, 0, 0, 0]
    var nums2 = [2, 5, 6]
    solution.merge(&nums1, 3, nums2, 3)
    print(nums1)
    
    nums1 = [1, 2, 4, 5, 6, 0]
    nums2 = [3]
    solution.merge(&nums1, 5, nums2, 1)
    print(nums1)
    
    nums1 = [2, 0]
    nums2 = [1]
    solution.merge(&nums1, 1, nums2, 1)
    print(nums1)
}
