//
//  _106_从中序与后序遍历序列构造二叉树.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/12/12.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

import Foundation

class _106_从中序与后序遍历序列构造二叉树 {
    func buildTree(_ inorder: [Int], _ postorder: [Int]) -> TreeNode? {
        guard !postorder.isEmpty else { return nil }
        let root = TreeNode(postorder.last!)
        var nodes = [root]
        var j = inorder.count - 1
        for i in stride(from: postorder.count - 2, through: 0, by: -1) {
            var parentNode: TreeNode?
            let curNode = TreeNode(postorder[i])
            while !nodes.isEmpty && nodes.last!.val == inorder[j] {
                parentNode = nodes.removeLast()
                j -= 1
            }
            if parentNode != nil {
                parentNode?.left = curNode
            } else {
                nodes.last?.right = curNode
            }
            nodes.append(curNode)
        }
        return root
    }
}

/**
 中序遍历 inorder = [9,3,15,20,7]
 后序遍历 postorder = [9,15,7,20,3]
 返回如下的二叉树：

        3
       / \
      9  20
        /  \
       15   7
 */
func test_106() {
    let solution = _106_从中序与后序遍历序列构造二叉树()
    let root = solution.buildTree([9, 3, 15, 20, 7], [9, 15, 7, 20, 3])
    print(root!)
}

