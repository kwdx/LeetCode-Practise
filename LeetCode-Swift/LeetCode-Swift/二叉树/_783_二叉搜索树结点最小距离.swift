//
//  _783_二叉搜索树结点最小距离.swift
//  LeetCode-Swift
//
//  Created by warden on 2020/1/5.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/

import Foundation

class _783_二叉搜索树结点最小距离 {
    func minDiffInBST(_ root: TreeNode?) -> Int {
        var pre: Int?
        var nodes = [TreeNode]()
        var p = root
        var val: Int?
        while p != nil || !nodes.isEmpty {
            while p != nil {
                nodes.append(p!)
                p = p?.left
            }
            if !nodes.isEmpty {
                p = nodes.removeLast()
                if pre != nil {
                    if val != nil {
                        val = min(val!, p!.val - pre!)
                    } else {
                        val = p!.val - pre!
                    }
                }
                pre = p?.val
                p = p?.right
            }
        }
        return val!
    }
}
