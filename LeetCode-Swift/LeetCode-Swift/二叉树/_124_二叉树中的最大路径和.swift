//
//  _124_二叉树中的最大路径和.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/

import Foundation

class _124_二叉树中的最大路径和 {
    func maxPathSum(_ root: TreeNode?) -> Int {
        var maxValue = Int.min
        maxValue = max(curPathValue(root, &maxValue), maxValue);
        return maxValue;
    }
    
    private func curPathValue(_ node: TreeNode?, _ maxValue: inout Int) -> Int {
        if node == nil {
            return 0
        }
        
        let lv = max(curPathValue(node!.left, &maxValue), 0)
        let rv = max(curPathValue(node!.right, &maxValue), 0)
        let tv = node!.val + max(lv, rv);
        
        maxValue = max(maxValue, node!.val + lv + rv)
        maxValue = max(maxValue, tv)

        return tv;
    }
}
