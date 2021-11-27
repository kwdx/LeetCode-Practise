/*
 * @lc app=leetcode.cn id=700 lang=swift
 *
 * [700] 二叉搜索树中的搜索
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init() { self.val = 0; self.left = nil; self.right = nil; }
 *     public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
 *     public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
 *         self.val = val
 *         self.left = left
 *         self.right = right
 *     }
 * }
 */
class Solution {
    func searchBST(_ root: TreeNode?, _ val: Int) -> TreeNode? {
        var node = root
        while node != nil {
            if node!.val == val {
                return node
            }
            node = node!.val > val ? node?.left : node?.right
        }
        return nil
    }
}
// @lc code=end

func main() {
    var root: TreeNode
    var val: Int
    var res: TreeNode?
    
    /**
     给定二叉搜索树:

             4
            / \
           2   7
          / \
         1   3

     和值: 2
     */
    let node1 = TreeNode(1)
    let node3 = TreeNode(3)
    let node2 = TreeNode(2, node1, node3)
    let node7 = TreeNode(7)
    root = TreeNode(4, node2, node7)
    val = 2
    res = node2
    assert(res === Solution().searchBST(root, val))
}
