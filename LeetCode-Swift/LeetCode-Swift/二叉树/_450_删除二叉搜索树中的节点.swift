//
//  _450_删除二叉搜索树中的节点.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/12/18.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/delete-node-in-a-bst/

import Foundation

class _450_删除二叉搜索树中的节点 {
    func deleteNode(_ root: TreeNode?, _ key: Int) -> TreeNode? {
        var fatherNode: TreeNode?
        let deleteNode = findDeleteNode(root, key, &fatherNode)
        if let result = removeNode(deleteNode, fatherNode) {
            return result
        }
        if nil != root && key == root!.val  {
            return nil
        }
        return root
    }
        
    func findDeleteNode(_ root: TreeNode?, _ key: Int, _ father: inout TreeNode?) -> TreeNode? {
        guard root != nil, root?.val != key else { return root }
        var node = root
        while node != nil && node?.val != key {
            father = node
            if node!.val < key {
                node = node?.right
            } else {
                node = node?.left
            }
        }
        if node == nil {
            father = nil
        }
        return node
    }

    /// 删除节点，如果删除的是根节点，则返回新的根节点
    /// - Parameters:
    ///   - node: 要删除的节点
    ///   - father: 被删除节点的父节点
    func removeNode(_ node: TreeNode?, _ father: TreeNode?) -> TreeNode? {
        guard node != nil else { return nil }
        
        var child: TreeNode?    // 新的子节点，替代node位置的新节点
        if node?.left == nil || node?.right == nil {
            // 只有1个子节点或叶子节点
            child = node?.left ?? node?.right
            if father?.left === node {
                father?.left = child
            } else {
                father?.right = child
            }
            return father == nil ? child : nil
        } else {
            // 将右子节点作为新的子节点，并将原左子节点嫁接给右子节点当左子节点
            var dNode = node?.left
            child = node?.right
            while dNode?.right != nil {
                dNode = dNode?.right
            }
            dNode?.right = child?.left
            child?.left = node?.left
            if father?.left === node {
                father?.left = child
            } else {
                father?.right = child
            }
        }
        
        return father == nil ? child : nil
    }
}
