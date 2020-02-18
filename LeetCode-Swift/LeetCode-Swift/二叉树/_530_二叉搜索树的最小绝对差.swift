//
//  _530_二叉搜索树的最小绝对差.swift
//  LeetCode-Swift
//
//  Created by warden on 2020/1/5.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/

import Foundation

class _530_二叉搜索树的最小绝对差 {
    func getMinimumDifference(_ root: TreeNode?) -> Int {
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
 输入:

    1
     \
      3
     /
    2

 输出:
 1

 解释:
 最小绝对差为1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
 */
func test_530() {
//    let nodes = generateTreeByLevel([1, nil, 3, 2])
//    let nodes = generateTreeByLevel([236, 104, 701, nil, 227, nil, 911])
    let nodes = generateTreeByLevel([0, nil, 2236, 1277, 2776, 519])
    let solution = _530_二叉搜索树的最小绝对差()
    print(solution.getMinimumDifference(nodes))
}

