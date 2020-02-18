//
//  _783_二叉搜索树结点最小距离.swift
//  LeetCode-Swift
//
//  Created by warden on 2020/1/5.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/

import Foundation

class _783_二叉搜索树结点最小距离 {
    func minDiffInBST(_ root: TreeNode?) -> Int {
        var pre: Int?
        var nodes = [TreeNode]()
        var p = root
        var val: Int?
        while p != nil || !nodes.isEmpty {
            while p != nil {
                nodes.append(p!)
                p = p?.left
            }
            if !nodes.isEmpty {
                p = nodes.removeLast()
                if pre != nil {
                    if val != nil {
                        val = min(val!, p!.val - pre!)
                    } else {
                        val = p!.val - pre!
                    }
                }
                pre = p?.val
                p = p?.right
            }
        }
        return val!
    }
}

/**
 输入: root = [4,2,6,1,3,null,null]
 输出: 1
 解释:
 注意，root是树结点对象(TreeNode object)，而不是数组。

 给定的树 [4,2,6,1,3,null,null] 可表示为下图:

           4
         /   \
       2      6
      / \
     1   3

 最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。
 */
func test_783() {
    let nodes = generateTreeByLevel([4, 2, 6, 1, 3])
    let solution = _783_二叉搜索树结点最小距离()
    print(solution.minDiffInBST(nodes))
}
