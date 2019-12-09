//
//  _145_二叉树的后序遍历.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/12/9.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/hou-xu-bian-li-jiu-shi-qian-xu-bian-li-de-ni-guo-c/

import Foundation

class _145_二叉树的后序遍历 {
    func postorderTraversal(_ root: TreeNode?) -> [Int] {
        var result = [Int]()
        var nodes = [TreeNode]()
        var p = root;
        while p != nil || !nodes.isEmpty {
            while p != nil {
                result.append(p!.val)
                nodes.append(p!)
                p = p?.right
            }
            p = nodes.removeLast().left
        }
        
        return result.reversed()
    }
}
