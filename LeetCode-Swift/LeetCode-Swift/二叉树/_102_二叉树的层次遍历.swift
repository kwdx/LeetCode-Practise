//
//  _102_二叉树的层次遍历.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/12/11.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

import Foundation

class _102_二叉树的层次遍历 {
    func levelOrder(_ root: TreeNode?) -> [[Int]] {
        var result = [[Int]]()
        if root == nil {
            return result
        }
        var nodes = [root!]
        var size = nodes.count
        var level = [Int]()
        while !nodes.isEmpty {
            if size == 0 {
                size = nodes.count
                result.append(level)
                level.removeAll()
            }
            let p = nodes.removeFirst()
            level.append(p.val)
            if p.left != nil {
                nodes.append(p.left!)
            }
            if p.right != nil {
                nodes.append(p.right!)
            }
            size -= 1
        }
        if level.count > 0 {
            result.append(level)
        }
        return result
    }
}

/**
 给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
 */
func test_102() {
    let root = generateTreeByLevel([3, 9, 20, nil, nil, 15, 7])
    let solution = _102_二叉树的层次遍历()
    print(solution.levelOrder(root))
}

