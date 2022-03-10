/*
 * @lc app=leetcode.cn id=589 lang=swift
 *
 * [589] N 叉树的前序遍历
 */

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
    func preorder(_ root: Node?) -> [Int] {
        dfs(root)
        return ans
    }
    
    private func dfs(_ node: Node?) {
        guard let n = node else { return }
        ans.append(n.val)
        for child in n.children {
            dfs(child)
        }
    }
}
// @lc code=end

func main() {
    
}
