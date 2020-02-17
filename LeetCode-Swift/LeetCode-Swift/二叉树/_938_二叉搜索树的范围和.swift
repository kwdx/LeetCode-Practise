//
//  _938_二叉搜索树的范围和.swift
//  LeetCode-Swift
//
//  Created by warden on 2020/2/17.
//  Copyright © 2020 warden. All rights reserved.
//

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
