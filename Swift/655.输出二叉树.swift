/*
 * @lc app=leetcode.cn id=655 lang=swift
 *
 * [655] 输出二叉树
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
    private var h: Int = 0
    private var m: Int = 0
    private var n: Int = 0
    private var ans: [[String]] = []
    
    func printTree(_ root: TreeNode?) -> [[String]] {
        dfs1(root, 0)
        m = h + 1
        n = (1 << (h + 1)) - 1
        ans = .init(repeating: .init(repeating: "", count: n), count: m)
        dfs2(root, 0, (n - 1) / 2)
        return ans
    }
    
    private func dfs1(_ root: TreeNode?, _ depth: Int) {
        guard let root = root else { return }
        h = max(h, depth)
        dfs1(root.left, depth + 1)
        dfs1(root.right, depth + 1)
    }
    
    private func dfs2(_ root: TreeNode?, _ x: Int, _ y: Int) {
        guard let root = root else { return }
        ans[x][y] = String(root.val)
        dfs2(root.left, x + 1, y - (1 << max(h - x - 1, 0)))
        dfs2(root.right, x + 1, y + (1 << max(h - x - 1, 0)))
    }
    
}
// @lc code=end

func main() {
    var root: TreeNode?
    var res: [[String]]
    
    /**
     输入：root = [1,2]
     输出：
     [["","1",""],
      ["2","",""]]
     */
    root = generateTreeByLevel([1,2])
    res = [["","1",""],
           ["2","",""]]
    assert(res == Solution().printTree(root))
    
    /**
     输入：root = [1,2,3,null,4]
     输出：
     [["","","","1","","",""],
      ["","2","","","","3",""],
      ["","","4","","","",""]]
     */
    root = generateTreeByLevel([1,2,3,nil,4])
    res = [["","","","1","","",""],
           ["","2","","","","3",""],
           ["","","4","","","",""]]
    assert(res == Solution().printTree(root))
}
