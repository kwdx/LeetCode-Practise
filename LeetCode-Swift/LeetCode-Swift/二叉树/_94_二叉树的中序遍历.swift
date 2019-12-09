//
//  _94_二叉树的中序遍历.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/12/9.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/binary-tree-inorder-traversal/%20/

import Foundation

class _94_二叉树的中序遍历 {
    func inorderTraversal(_ root: TreeNode?) -> [Int] {
        var results = [Int]()
        var nodes = [TreeNode]()
        var p = root
        while p != nil || !nodes.isEmpty {
            while p != nil {
                nodes.append(p!)
                p = p?.left
            }
            if !nodes.isEmpty {
                results.append(nodes.last!.val)
                p = nodes.removeLast().right;
            }
        }
        return results
    }
}
