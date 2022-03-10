/*
 * @lc app=leetcode.cn id=590 lang=swift
 *
 * [590] N 叉树的后序遍历
 */

import Darwin

// @lc code=start
/**
 * Definition for a Node.
 * public class Node {
 *     public var val: Int
 *     public var children: [Node]
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.children = []
 *     }
 * }
 */

class Solution {
    private var ans: [Int] = []
    func postorder(_ root: Node?) -> [Int] {
    	dfs(root)
        return ans
    }
    private func dfs(_ node: Node?) {
        guard let n = node else { return }
        for child in n.children {
            dfs(child)
        }
        ans.append(n.val)
    }
}
// @lc code=end

func main() {
    
}
