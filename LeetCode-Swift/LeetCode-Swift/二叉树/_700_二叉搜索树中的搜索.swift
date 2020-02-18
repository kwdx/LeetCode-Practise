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

/**
 给定二叉搜索树:

         4
        / \
       2   7
      / \
     1   3

 和值: 2
 你应该返回如下子树:

       2
      / \
     1   3
 */
func test_700() {
    let nodes = generateTreeByLevel([4, 2, 7, 1, 3])
    let solution = _700_二叉搜索树中的搜索()
    printTreeByLevel(solution.searchBST(nodes, 2))
}
