//
//  _101_对称二叉树.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/12/16.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/symmetric-tree/solution/dui-cheng-er-cha-shu-guan-fang-ti-jie-fu-zhi-cban-/

import Foundation

class _101_对称二叉树 {
    
    func isMirror(_ left: TreeNode?, _ right: TreeNode?) -> Bool {
        guard left != nil && right != nil else {
            return (left == nil) && (right == nil)
        }
        return (left?.val == right?.val) && isMirror(left?.left, right?.right) && isMirror(left?.right, right?.left)
    }
    
    func isSymmetric1(_ root: TreeNode?) -> Bool {
        return isMirror(root, root)
    }
    
    func isSymmetric(_ root: TreeNode?) -> Bool {
        var nodes = [root, root]
        while !nodes.isEmpty {
            let t1 = nodes.removeFirst()
            let t2 = nodes.removeFirst()
            if t1 == nil && t2 == nil {
                continue
            } else if (t1 == nil || t2 == nil) {
                return false
            } else if (t1?.val != t2?.val) {
                return false
            }
            nodes.append(t1?.left)
            nodes.append(t2?.right)
            nodes.append(t1?.right)
            nodes.append(t2?.left)
        }
        return true
    }
}

