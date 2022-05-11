//
//  TreeNode.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//

import Foundation

public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init(_ val: Int, _ left: TreeNode? = nil, _ right: TreeNode?  = nil) {
        self.val = val
        self.left = left
        self.right = right
    }
}

// 生成二叉搜索树
func generateBinaryTree(_ nodes: [Int]) -> TreeNode? {
    if nodes.count == 0 {
        return nil;
    }
    let root = Optional(TreeNode(nodes[0]))
    for i in 1..<nodes.count {
        var parent = root
        var node = root
        while node != nil {
            parent = node
            if nodes[i] < node!.val {
                node = node!.left
            } else {
                node = node!.right
            }
        }
        
        if (nodes[i] < parent!.val) {
            parent!.left = TreeNode(nodes[i]);
        } else {
            parent!.right = TreeNode(nodes[i]);
        }
    }
    return root;
}

/// 按照层序遍历生成二叉树
func generateTreeByLevel(_ nodes: [Int?]) -> TreeNode? {
    guard nodes.count > 0 else {
        return nil
    }
    let root = TreeNode(nodes[0]!)
    var nodeArr = [root]
    var isLeft = true
    for i in 1..<nodes.count {
        let parent = nodeArr.first
        if nodes[i] != nil {
            let child = TreeNode(nodes[i]!)
            if isLeft {
                parent?.left = child
            } else {
                parent?.right = child
            }
            nodeArr.append(child)
        }
        if !isLeft {
            nodeArr.removeFirst()
        }
        
        isLeft = !isLeft
    }
    return root
}

/// 按照层序遍历打印二叉树
func printTreeByLevel(_ root: TreeNode?) {
    guard root != nil else {
        return
    }
    var nodes = [root]
    var vals = [Int]()
    while !nodes.isEmpty {
        let node = nodes.removeFirst()
        if node != nil {
            vals.append(node!.val)
            nodes.append(node!.left)
            nodes.append(node!.right)
        }
    }
    print(vals)
}

/// 按照层序遍历打印二叉树
func getTreeByLevel(_ root: TreeNode?) -> [Int] {
    var vals = [Int]()

    guard root != nil else {
        return vals
    }
    var nodes = [root]
    while !nodes.isEmpty {
        let node = nodes.removeFirst()
        if node != nil {
            vals.append(node!.val)
            nodes.append(node!.left)
            nodes.append(node!.right)
        }
    }
    return vals
}
