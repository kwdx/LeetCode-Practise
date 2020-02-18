//
//  _108_将有序数组转换为二叉搜索树.swift
//  LeetCode-Swift
//
//  Created by warden on 2020/2/17.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/

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

/**
 给定有序数组: [-10,-3,0,5,9],

 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

       0
      / \
    -3   9
    /   /
  -10  5
 */
func test_108() {
    let solution = _108_将有序数组转换为二叉搜索树()
    let root = solution.sortedArrayToBST([-10, -3, 0, 5, 9])
    printTreeByLevel(root);
}
