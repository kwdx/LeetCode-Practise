//
//  _99_恢复二叉搜索树.swift
//  LeetCode-Swift
//
//  Created by warden on 2020/2/17.
//  Copyright © 2020 warden. All rights reserved.
//

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
