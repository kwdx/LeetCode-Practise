//
//  _110_平衡二叉树.swift
//  LeetCode-Swift
//
//  Created by warden on 2020/2/17.
//  Copyright © 2020 warden. All rights reserved.
//

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
