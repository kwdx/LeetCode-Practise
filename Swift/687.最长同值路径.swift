/*
 * @lc app=leetcode.cn id=687 lang=swift
 *
 * [687] 最长同值路径
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
    private var ans = 0
    
    func longestUnivaluePath(_ root: TreeNode?) -> Int {
        _ = dfs(root)
        return ans
    }
    
    private func dfs(_ root: TreeNode?) -> Int {
        guard let root = root else { return 0 }
        
        let left = dfs(root.left)
        let right = dfs(root.right)
        
        var left1 = 0
        var right1 = 0
        if root.left?.val == root.val {
            left1 = left + 1
        }
        if root.right?.val == root.val {
            right1 = right + 1
        }
        ans = max(ans, left1 + right1)
        return max(left1, right1)
    }
}
// @lc code=end

func main() {
    var root: TreeNode?
    var res: Int
    
    /**
     输入：root = [5,4,5,1,1,5]
     输出：2
     */
    root = generateTreeByLevel([5,4,5,1,1,nil,5])
    res = 2
    assert(res == Solution().longestUnivaluePath(root))
    
    /**
     输入：root = [1,4,5,4,4,5]
     输出：2
     */
    root = generateTreeByLevel([1,4,5,4,4,nil,5])
    res = 2
    assert(res == Solution().longestUnivaluePath(root))
}
