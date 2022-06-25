/*
 * @lc app=leetcode.cn id=515 lang=swift
 *
 * [515] 在每个树行中找最大值
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
    func largestValues(_ root: TreeNode?) -> [Int] {
        guard let root = root else { return [] }
        var ans: [Int] = []
        var nodes: [TreeNode] = [root]
        while !nodes.isEmpty {
            let cnt = nodes.count
            var val = nodes.first!.val
            for _ in 0..<cnt {
                let node = nodes.removeFirst()
                val = max(val, node.val)
                if node.left != nil {
                    nodes.append(node.left!)
                }
                if node.right != nil {
                    nodes.append(node.right!)
                }
            }
            ans.append(val)
        }
        return ans
    }
}
// @lc code=end

func main() {
    var root: TreeNode?
    var res: [Int]
    
    /**
     输入: root = [1,3,2,5,3,null,9]
     输出: [1,3,9]
     */
    root = generateBinaryTreeByLevel([1,3,2,5,3,nil,9])
    res = [1,3,9]
    assert(res == Solution().largestValues(root))
    
    /**
     输入: root = [1,2,3]
     输出: [1,3]
     */
    root = generateBinaryTreeByLevel([1,2,3])
    res = [1,3]
    assert(res == Solution().largestValues(root))
}
