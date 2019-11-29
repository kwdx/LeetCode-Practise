//
//  _114_二叉树展开为链表.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/

import Foundation

class _114_二叉树展开为链表 {
    func flatten(_ root: TreeNode?) {
        guard root != nil else {
            return
        }
        
        if root?.left != nil {
            // 保留right
            let right = root?.right
            // 将left嫁接到right
            root?.right = root?.left
            // 清空left
            root?.left = nil
            // 将旧的right嫁接到root的最右下角
            var rightMost = root?.right
            while rightMost?.right != nil {
                rightMost = rightMost?.right
            }
            rightMost?.right = right
        }
        flatten(root?.right)
    }
}
