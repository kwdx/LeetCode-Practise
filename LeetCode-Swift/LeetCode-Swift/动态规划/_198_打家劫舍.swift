//
//  _198_打家劫舍.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/house-robber/

import Foundation

class _198_打家劫舍 {
    func rob(_ nums: [Int]) -> Int {
        var first = 0
        var second = 0
        for num in nums {
            let tmp = second
            second = max(first + num, second)
            first = tmp
        }
        return max(first, second)
    }
}
