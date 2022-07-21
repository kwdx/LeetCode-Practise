/*
 * @lc app=leetcode.cn id=814 lang=swift
 *
 * [814] 二叉树剪枝
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
    func pruneTree(_ root: TreeNode?) -> TreeNode? {
        guard let node = root else { return nil }
        node.left = pruneTree(node.left)
        node.right = pruneTree(node.right)
        if node.left == nil && node.right == nil && node.val == 0 {
            return nil
        }
        return node
    }
}
// @lc code=end

func main() {
    var root: TreeNode?
    
    /**
     输入：root = [1,null,0,0,1]
     输出：[1,null,0,null,1]
     解释：
     只有红色节点满足条件“所有不包含 1 的子树”。 右图为返回的答案。
     */
    root = generateTreeByLevel([1,nil,0,0,1])
    printTreeByLevel(Solution().pruneTree(root))

    /**
     输入：root = [1,0,1,0,0,0,1]
     输出：[1,null,1,null,1]
     */
    root = generateTreeByLevel([1,0,1,0,0,0,1])
    printTreeByLevel(Solution().pruneTree(root))
    
    /**
     输入：root = [1,1,0,1,1,0,1,0]
     输出：[1,1,0,1,1,null,1]
     */
    root = generateTreeByLevel([1,1,0,1,1,0,1,0])
    printTreeByLevel(Solution().pruneTree(root))
}
