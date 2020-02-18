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

/**
 输入: [1,null,2,3]
    1
     \
      2
     /
    3

 输出: [1,2,3]
 输入: [2,1,3,null,4]
 输出: [2,1,4,3]
 */
func test_144() {
    let root = generateTreeByLevel([2, 1, 3, nil, 4])
    let solution = _144_二叉树的前序遍历()
    print(solution.preorderTraversal(root))
}
