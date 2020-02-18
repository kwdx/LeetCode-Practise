//
//  _173_二叉搜索树迭代器.swift
//  LeetCode-Swift
//
//  Created by warden on 2020/2/17.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/binary-search-tree-iterator/

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

/**
 示例：
        7
       /\
      3  15
         /\
        9 20


 BSTIterator iterator = new BSTIterator(root);
 iterator.next();    // 返回 3
 iterator.next();    // 返回 7
 iterator.hasNext(); // 返回 true
 iterator.next();    // 返回 9
 iterator.hasNext(); // 返回 true
 iterator.next();    // 返回 15
 iterator.hasNext(); // 返回 true
 iterator.next();    // 返回 20
 iterator.hasNext(); // 返回 false
 */
func test_173() {
    let root = generateTreeByLevel([7,3,15,nil,nil,9,20]);
    
    let solution = _173_二叉搜索树迭代器(root);
    print(solution.next())      // 返回3
    print(solution.next())      // 返回7
    print(solution.hasNext())   // 返回true
    print(solution.next())      // 返回9
    print(solution.hasNext())   // 返回true
    print(solution.next())      // 返回15
    print(solution.hasNext())   // 返回true
    print(solution.next())      // 返回20
    print(solution.hasNext())   // 返回false
}
