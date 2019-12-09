//
//  _144_二叉树的前序遍历.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/12/7.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/binary-tree-preorder-traversal/

import Foundation

class _144_二叉树的前序遍历 {
    func preorderTraversal(_ root: TreeNode?) -> [Int] {
        var result = [Int]()
        
        var nodes = [TreeNode]()
        var p = root;
        while p != nil || !nodes.isEmpty {
            while p != nil {
                result.append(p!.val)
                nodes.append(p!)
                p = p?.left
            }
            p = nodes.removeLast()
            p = p?.right;
        }
        
        return result
    }
}
