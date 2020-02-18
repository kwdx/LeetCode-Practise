//
//  _99_恢复二叉搜索树.swift
//  LeetCode-Swift
//
//  Created by warden on 2020/2/17.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/recover-binary-search-tree/

import Foundation

class _99_恢复二叉搜索树 {
    func recoverTree(_ root: TreeNode?) {
        var first: TreeNode?
        var last: TreeNode?
        var prev: TreeNode?
        var node = root
        while (node != nil) {
            var tmp = node?.left
            while (tmp != nil && tmp!.right != nil && tmp?.right !== node) {
                tmp = tmp!.right
            }
            if (tmp == nil || tmp?.right === node) {
                if (tmp != nil) {
                    tmp?.right = nil
                }
                if (prev != nil && node!.val < prev!.val) {
                    last = node
                    first = first == nil ? prev : first
                }
                prev = node
                node = node?.right
            } else {
                tmp?.right = node
                node = node?.left
            }
        }
        if first != nil && last != nil {
            let tmp = last!.val
            last!.val = first!.val
            first!.val = tmp
        }
    }
}

/**
 输入: [1,3,null,null,2]

    1
   /
  3
   \
    2

 输出: [3,1,null,null,2]

    3
   /
  1
   \
    2
 示例 2:

 输入: [3,1,4,null,null,2]

   3
  / \
 1   4
    /
   2

 输出: [2,1,4,null,null,3]

   2
  / \
 1   4
    /
   3
 */
func test_99() {
    let solution = _99_恢复二叉搜索树();
    var root = generateTreeByLevel([1,3,nil,nil,2])
//    solution.recoverTree(root)
//    printTreeByLevel(root)
    root = generateTreeByLevel([3,1,4,nil,nil,2])
    solution.recoverTree(root)
    printTreeByLevel(root)
}
