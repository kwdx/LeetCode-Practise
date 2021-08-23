//
//  sorts.swift
//  Swift_
//
//  Created by warden on 2021/8/22.
//

import Foundation

/// 冒泡排序
/// - Parameter nums: 待排序数组
/// - Returns: 排好序的数组
func bubbleSort<T: Comparable>(_ nums: [T]) -> [T] {
    var res = nums;
    
    for i in 0..<res.count {
        var flag = false
        for j in 0..<(res.count - i - 1) {
            if res[j] > res[j+1] {
                res.swapAt(j, j + 1)
                flag = true
            }
        }
        if !flag {
            break
        }
    }
    return res
}

func test() {
    var nums: [Int] = []
    var res: [Int] = []
    
    nums = [1,5,9,8,7,2,4,3,0,6]
    res = [0,1,2,3,4,5,6,7,8,9]
    nums = bubbleSort(nums)
    assert(res == nums)
}
