//
//  _349_两个数组的交集.swift
//  LeetCode-Swift
//
//  Created by warden on 2020/2/18.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/intersection-of-two-arrays/

import Foundation

class _349_两个数组的交集 {
    func intersection(_ nums1: [Int], _ nums2: [Int]) -> [Int] {
        var set1 = Set(nums1)
        var res = [Int]()
        for num in nums2 {
            if set1.remove(num) != nil {
                res.append(num)
            }
        }
        return res
    }
}

/**
 示例 1:

 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 输出: [2]
 示例 2:

 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 输出: [9,4]
 */
func test_349() {
    let solution = _349_两个数组的交集()

    let nums1 = [1, 2, 2, 1]
    let nums2 = [2, 2]
    print(solution.intersection(nums1, nums2))
}
