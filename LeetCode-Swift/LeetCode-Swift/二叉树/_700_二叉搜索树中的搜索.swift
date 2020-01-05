//
//  _700_二叉搜索树中的搜索.swift
//  LeetCode-Swift
//
//  Created by warden on 2020/1/5.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/search-in-a-binary-search-tree/

import Foundation

class _700_二叉搜索树中的搜索 {
    func searchBST(_ root: TreeNode?, _ val: Int) -> TreeNode? {
        var node = root;
        while node != nil {
            if node!.val == val {
                return node
            }
            node = node!.val > val ? node?.left : node?.right
        }
        return nil;
    }
}
