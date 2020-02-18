//
//  _230_二叉搜索树中第K小的元素.swift
//  LeetCode-Swift
//
//  Created by warden on 2020/2/17.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/

import Foundation

class _230_二叉搜索树中第K小的元素 {
    private var n = 0
    private var res = 0
    func kthSmallest(_ root: TreeNode?, _ k: Int) -> Int {
        n = 0
        res = 0
        dfs(root, k)
        return res
    }
    
    func dfs(_ root: TreeNode?, _ k: Int) {
        if root == nil {
            return
        }
        dfs(root?.left, k)
        n += 1
        if (n == k) {
            res = root!.val
            return
        }
        dfs(root?.right, k)
    }
}

/**
 输入: root = [3,1,4,null,2], k = 1
    3
   / \
  1   4
   \
    2
 输出: 1
 示例 2:

 输入: root = [5,3,6,2,4,null,null,1], k = 3
        5
       / \
      3   6
     / \
    2   4
   /
  1
 输出: 3
 */
func test_230() {
    let solution = _230_二叉搜索树中第K小的元素()
    let root = generateTreeByLevel([3, 1, 4, nil, 2])
    print(solution.kthSmallest(root, 1))
    let root1 = generateTreeByLevel([5,3,6,2,4,nil,nil,1])
    print(solution.kthSmallest(root1, 3))
}
