//
//  _110_平衡二叉树.swift
//  LeetCode-Swift
//
//  Created by warden on 2020/2/17.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/balanced-binary-tree/

import Foundation

class _110_平衡二叉树 {
    func isBalanced(_ root: TreeNode?) -> Bool {
        
        return treeDepth(root) != -1
    }
    
    func treeDepth(_ root: TreeNode?) -> Int {
        if root == nil {
            return 0
        }
        if root?.left == nil && root?.right == nil {
            return 1
        }
        let leftDepth = treeDepth(root?.left)
        if leftDepth < 0 {
            return -1
        }
        let rightDepth = treeDepth(root?.right)
        if rightDepth < 0 {
            return -1
        }
        if abs(leftDepth - rightDepth) > 1 {
            return -1
        }
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1
    }
}

/**
 示例 1:

 给定二叉树 [3,9,20,null,null,15,7]

     3
    / \
   9  20
     /  \
    15   7
 返回 true 。

 示例 2:

 给定二叉树 [1,2,2,3,3,null,null,4,4]

        1
       / \
      2   2
     / \
    3   3
   / \
  4   4
 返回 false 。
 */
func test_110() {
    let solution = _110_平衡二叉树();
    print(solution.isBalanced(generateTreeByLevel([3,9,20,nil,nil,15,7])))
    print(solution.isBalanced(generateTreeByLevel([1,2,2,3,3,nil,nil,4,4])))
}

