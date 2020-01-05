//
//  _701_二叉搜索树中的插入操作.swift
//  LeetCode-Swift
//
//  Created by warden on 2020/1/5.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/

import Foundation

class _701_二叉搜索树中的插入操作 {
    func insertIntoBST(_ root: TreeNode?, _ val: Int) -> TreeNode? {
        guard root != nil else { return TreeNode(val) }
   
        var parent = root;
        while parent != nil {
            if parent!.val < val {
                if parent?.right == nil {
                    parent?.right = TreeNode(val)
                    break
                }
                parent = parent?.right
            } else {
                if parent?.left == nil {
                    parent?.left = TreeNode(val)
                    break
                }
                parent = parent?.left
            }
        }
        
        return root;
    }
}
