//
//  _104_二叉树的最大深度.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/12/11.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/

import Foundation

class _104_二叉树的最大深度 {
    func maxDepth(_ root: TreeNode?) -> Int {
        if root == nil {
            return 0
        }
        var depth = 0
        var nodes = [root!]
        var size = 0
        while !nodes.isEmpty {
            if size == 0 {
                size = nodes.count
                depth += 1
            }
            let p = nodes.removeFirst()
            if p.left != nil {
                nodes.append(p.left!)
            }
            if p.right != nil {
                nodes.append(p.right!)
            }
            size -= 1
        }
        return depth
    }
}
