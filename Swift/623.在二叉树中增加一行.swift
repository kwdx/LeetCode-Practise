/*
 * @lc app=leetcode.cn id=623 lang=swift
 *
 * [623] 在二叉树中增加一行
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
    func addOneRow(_ root: TreeNode?, _ val: Int, _ depth: Int) -> TreeNode? {
        if depth == 1 {
            let node = TreeNode(val)
            node.left = root
            return node
        }
        var q = [root!]
        var level = 1
        while !q.isEmpty && level < depth {
            let sz = q.count
            for _ in 0..<sz {
                let node = q.removeFirst()
                if level == depth - 1 {
                    let a = TreeNode(val), b = TreeNode(val)
                    a.left = node.left
                    b.right = node.right
                    node.left = a
                    node.right = b
                } else {
                    if node.left != nil {
                        q.append(node.left!)
                    }
                    if node.right != nil {
                        q.append(node.right!)
                    }
                }
            }
            level += 1
        }
        return root
    }
}
// @lc code=end

func main() {
    var root: TreeNode?
    var val: Int
    var depth: Int
    var res: TreeNode?
    
    /**
     输入: root = [4,2,6,3,1,5], val = 1, depth = 2
     输出: [4,1,1,2,null,null,6,3,1,5]
     */
    root = generateTreeByLevel([4,2,6,3,1,5])
    val = 1
    depth = 2
    res = Solution().addOneRow(root, val, depth)
    printTreeByLevel(res)
    
    /**
     输入: root = [4,2,null,3,1], val = 1, depth = 3
     输出:  [4,2,null,1,1,3,null,null,1]
     */
    root = generateTreeByLevel([4,2,nil,3,1])
    val = 1
    depth = 3
    res = Solution().addOneRow(root, val, depth)
    printTreeByLevel(res)
}
