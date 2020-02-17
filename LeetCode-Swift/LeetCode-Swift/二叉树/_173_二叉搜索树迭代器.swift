//
//  _173_二叉搜索树迭代器.swift
//  LeetCode-Swift
//
//  Created by warden on 2020/2/17.
//  Copyright © 2020 warden. All rights reserved.
//

import Foundation

class _173_二叉搜索树迭代器 {
    private var st = [TreeNode]()
    
    init(_ root: TreeNode?) {
        var node = root
        while node != nil {
            st.append(node!)
            node = node?.left
        }
    }
    
    /** @return the next smallest number */
    func next() -> Int {
        var node: TreeNode?
        node = st.removeLast()
        let res = node?.val ?? 0;
        node = node?.right
        while node != nil {
            st.append(node!);
            node = node?.left
        }
        return res;
    }
    
    /** @return whether we have a next smallest number */
    func hasNext() -> Bool {
        return !st.isEmpty
    }
}
