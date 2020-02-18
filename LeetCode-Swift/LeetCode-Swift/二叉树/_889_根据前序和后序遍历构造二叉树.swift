//
//  _889_根据前序和后序遍历构造二叉树.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/12/12.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

import Foundation

class _889_根据前序和后序遍历构造二叉树 {
    func constructFromPrePost(_ pre: [Int], _ post: [Int]) -> TreeNode? {
        guard !pre.isEmpty else { return nil }
        let root = TreeNode(pre.first!)
        var nodes = [root]
        var j = 0
        for i in 1..<pre.count {
            let curNode = TreeNode(pre[i])
            while nodes.last!.val == post[j] {
                nodes.removeLast()
                j += 1
            }
            if nodes.last?.left == nil {
                nodes.last?.left = curNode
            } else {
                nodes.last?.right = curNode
            }
            nodes.append(curNode)
        }
        return root
    }
}

/**
 输入：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
 输出：[1,2,3,4,5,6,7]
 */
func test_889() {
    let solution = _889_根据前序和后序遍历构造二叉树()
    let root = solution.constructFromPrePost([1, 2, 4, 5, 3, 6, 7], [4, 5, 2, 6, 7, 3, 1])
    print(root!)
}
