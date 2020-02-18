//
//  _105_从前序与中序遍历序列构造二叉树.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/12/12.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

import Foundation

class _105_从前序与中序遍历序列构造二叉树 {
    func buildTree(_ preorder: [Int], _ inorder: [Int]) -> TreeNode? {
        if preorder.count == 0 {
            return nil
        }
        let root = TreeNode(preorder.first!)
        var nodes = [root]
        var j = 0
        for i in 1..<preorder.count {
            var parentNode: TreeNode?
            let curNode = TreeNode(preorder[i])
            while !nodes.isEmpty && nodes.last!.val == inorder[j] {
                parentNode = nodes.removeLast()
                j += 1
            }
            if parentNode != nil {
                parentNode?.right = curNode
            } else {
                nodes.last?.left = curNode
            }
            nodes.append(curNode)
        }
        return root
    }
}

/**
 前序遍历 preorder = [3,9,20,15,7]
 中序遍历 inorder = [9,3,15,20,7]
 返回如下的二叉树：

        3
       / \
      9  20
        /  \
       15   7
 */
func test_105() {
    let solution = _105_从前序与中序遍历序列构造二叉树()
    let root = solution.buildTree([3, 9, 20, 15, 7], [9, 3, 15, 20, 7])
    print(root!)
}
