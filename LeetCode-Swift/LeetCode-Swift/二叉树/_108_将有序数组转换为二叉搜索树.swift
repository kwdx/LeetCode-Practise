//
//  _108_将有序数组转换为二叉搜索树.swift
//  LeetCode-Swift
//
//  Created by warden on 2020/2/17.
//  Copyright © 2020 warden. All rights reserved.
//

import Foundation

class _108_将有序数组转换为二叉搜索树 {
    func sortedArrayToBST(_ nums: [Int]) -> TreeNode? {
        return merge(nums, 0, nums.count - 1)
    }
    
    func merge(_ nums: [Int], _ left: Int, _ right: Int) -> TreeNode? {
        if left > right {
            return nil
        }
        let mid = (left + right + 1) >> 1
        let node = TreeNode(nums[mid])
        node.left = merge(nums, left, mid - 1)
        node.right = merge(nums, mid + 1, right)
        return node
    }
}
