/*
 * @lc app=leetcode.cn id=662 lang=swift
 *
 * [662] 二叉树最大宽度
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
    private var map: [Int: Int] = [:]
    private var ans = 0

    func widthOfBinaryTree(_ root: TreeNode?) -> Int {
        dfs(root, 1, 0)
        return ans
    }
    
    private func dfs(_ root: TreeNode?, _ idx: Int, _ depth: Int) {
        guard let root = root else {
            return
        }
        if map[depth] == nil {
            map[depth] = idx
        }
        ans = max(ans, idx - map[depth]! + 1)
        let idx = idx - map[depth]! + 1
        dfs(root.left, idx << 1, depth + 1)
        dfs(root.right, idx << 1 | 1, depth + 1)
    }
}
// @lc code=end

func main() {
    var root: TreeNode?
    var res: Int
    
    /**
     输入：root = [1,3,2,5,3,null,9]
     输出：4
     解释：最大宽度出现在树的第 3 层，宽度为 4 (5,3,null,9) 。
     */
    root = generateTreeByLevel([1,3,2,5,3,nil,9])
    res = 4
    assert(res == Solution().widthOfBinaryTree(root))
    
    /**
     输入：root = [1,3,2,5,null,null,9,6,null,7]
     输出：7
     解释：最大宽度出现在树的第 4 层，宽度为 7 (6,null,null,null,null,null,7) 。
     */
    root = generateTreeByLevel([1,3,2,5,nil,nil,9,6,nil,7])
    res = 7
    assert(res == Solution().widthOfBinaryTree(root))
    
    /**
     输入：root = [1,3,2,5]
     输出：2
     解释：最大宽度出现在树的第 2 层，宽度为 2 (3,2) 。
     */
    root = generateTreeByLevel([1,3,2,5])
    res = 2
    assert(res == Solution().widthOfBinaryTree(root))
}
