/*
 * @lc app=leetcode.cn id=652 lang=swift
 *
 * [652] 寻找重复的子树
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
    private var ans = [TreeNode]()
    private var trees = [String: Int]()
    
    func findDuplicateSubtrees(_ root: TreeNode?) -> [TreeNode?] {
        _ = inorderTravel(root)
        return ans
    }
    
    func inorderTravel(_ root: TreeNode?) -> String {
        guard let root = root else {
            return "#"
        }
        
        let left = inorderTravel(root.left)
        let right = inorderTravel(root.right)
        
        let id = "\(left)_\(right)_\(root.val)"
        let val = trees[id] ?? 0
        if val ==  1 {
            ans.append(root)
        }
        trees[id] = val + 1
        return id
    }
}
// @lc code=end

func main() {
}
