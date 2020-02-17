//
//  _230_二叉搜索树中第K小的元素.swift
//  LeetCode-Swift
//
//  Created by warden on 2020/2/17.
//  Copyright © 2020 warden. All rights reserved.
//

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
