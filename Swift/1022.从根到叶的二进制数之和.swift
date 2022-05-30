/*
 * @lc app=leetcode.cn id=1022 lang=swift
 *
 * [1022] 从根到叶的二进制数之和
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
    func sumRootToLeaf(_ root: TreeNode?) -> Int {
        return dfs(root!, 0)
    }
    
    func dfs(_ root: TreeNode, _ value: Int) -> Int {
        var ans = 0
        let x = (value << 1) + root.val
        if let left = root.left {
            ans += dfs(left, x)
        }
        if let right = root.right {
            ans += dfs(right, x)
        }
        return root.left == nil && root.right == nil ? x : ans
    }
}
// @lc code=end

func main() {
    var root: TreeNode?
    var res: Int
    
    /**
     输入：root = [1,0,1,0,1,0,1]
     输出：22
     解释：(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
     */
    root = generateTreeByLevel([1,0,1,0,1,0,1])
    res = 22
    assert(res == Solution().sumRootToLeaf(root))
    
    /**
     输入：root = [0]
     输出：0
     */
    root = TreeNode(0)
    res = 0
    assert(res == Solution().sumRootToLeaf(root))
}
