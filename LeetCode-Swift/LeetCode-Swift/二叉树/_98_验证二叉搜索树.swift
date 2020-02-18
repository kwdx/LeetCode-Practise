//
//  _98_验证二叉搜索树.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/validate-binary-search-tree/

import Foundation

class _98_验证二叉搜索树 {
    
    func isValidBST(_ root: TreeNode?) -> Bool {
        var p = root;
        var nodes = [TreeNode]()
        
        var inorder = Int.min
        while p != nil || nodes.count > 0 {
            while p != nil {
                nodes.append(p!)
                p = p!.left
            }
            p = nodes.popLast()
            guard p!.val > inorder else { return false }
            
            inorder = p!.val
            p = p?.right
        }
        
        return true
    }
    
    var last: Int?
    func isValidBST1(_ root: TreeNode?) -> Bool {
        if root == nil {
            return true;
        }
        if !isValidBST(root?.left) {
            return false
        }
        if (last != nil && (last! > root!.val)) {
            return false
        }
        last = root?.val
        if !isValidBST(root?.right) {
            return false
        }
        return true
    }
}

/**
 输入:
     2
    / \
   1   3
 输出: true
 */
func test_98() {
    let root = TreeNode(2)
    root.left = TreeNode(1)
    root.right = TreeNode(3)
    let solution = _98_验证二叉搜索树()
    print(solution.isValidBST(root))
}
