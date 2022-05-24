/*
 * @lc app=leetcode.cn id=965 lang=swift
 *
 * [965] 单值二叉树
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
    func isUnivalTree(_ root: TreeNode?) -> Bool {
        guard let node = root else { return true }
        if let left = root?.left?.val, left != node.val {
            return false
        }
        if let right = root?.right?.val, right != node.val {
            return false
        }
        return isUnivalTree(root?.left) && isUnivalTree(node.right)
    }
}
// @lc code=end

func main() {
    var root: TreeNode?
    var res: Bool
    
    /**
     输入：[1,1,1,1,1,null,1]
     输出：true
     */
    root = generateTreeByLevel([1,1,1,1,1,nil,1])
    res = true
    assert(res == Solution().isUnivalTree(root))
    
    /**
     输入：[2,2,2,5,2]
     输出：false
     */
    root = generateTreeByLevel([2,2,2,5,2])
    res = false
    assert(res == Solution().isUnivalTree(root))
}
