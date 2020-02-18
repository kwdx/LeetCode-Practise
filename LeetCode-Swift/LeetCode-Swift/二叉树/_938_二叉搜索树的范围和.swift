//
//  _938_二叉搜索树的范围和.swift
//  LeetCode-Swift
//
//  Created by warden on 2020/2/17.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/range-sum-of-bst/

import Foundation

class _938_二叉搜索树的范围和 {
    func rangeSumBST(_ root: TreeNode?, _ L: Int, _ R: Int) -> Int {
        guard root != nil else {
            return 0
        }
        switch root!.val {
        case L:
            return root!.val + rangeSumBST(root?.right, L, R)
        case R:
            return root!.val + rangeSumBST(root?.left, L, R)
            
        default:
            break
        }
        if R < root!.val {
            return rangeSumBST(root?.left, L, R)
        }
        if L > root!.val {
            return rangeSumBST(root?.right, L, R)
        }
        return root!.val + rangeSumBST(root?.left, L, R) + rangeSumBST(root?.right, L, R)
    }
}

/**
 示例 1：

 输入：root = [10,5,15,3,7,null,18], L = 7, R = 15
 输出：32
 示例 2：

 输入：root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
 输出：23
 */
func test_938() {
    let solution = _938_二叉搜索树的范围和()
    let root = generateTreeByLevel([10, 5, 15, 3, 7, nil, 18])
    print(solution.rangeSumBST(root, 7, 15))
    let root1 = generateTreeByLevel([10, 5, 15, 3, 7, 13, 18, 1, nil, 6])
    print(solution.rangeSumBST(root1, 6, 10))
}
