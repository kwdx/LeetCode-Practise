/*
 * @lc app=leetcode.cn id=1302 lang=swift
 *
 * [1302] 层数最深叶子节点的和
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
    func deepestLeavesSum(_ root: TreeNode?) -> Int {
        var ans = 0
        var q = [root!]
        while !q.isEmpty {
            let sz = q.count
            ans = 0
            for _ in 0..<sz {
                let node = q.removeFirst()
                ans += node.val
                if node.left != nil {
                    q.append(node.left!)
                }
                if node.right != nil {
                    q.append(node.right!)
                }
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var root: TreeNode?
    var res: Int
    
    /**
     输入：root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
     输出：19
     */
    root = generateTreeByLevel([50,nil,54,98,6,nil,nil,nil,34])
    res = 34
    assert(res == Solution().deepestLeavesSum(root))
    
    /**
     输入：root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
     输出：15
     */
    root = generateTreeByLevel([1,2,3,4,5,nil,6,7,nil,nil,nil,nil,8])
    res = 15
    assert(res == Solution().deepestLeavesSum(root))
    
    /**
     输入：root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
     输出：19
     */
    root = generateTreeByLevel([6,7,8,2,7,1,3,9,nil,1,4,nil,nil,nil,5])
    res = 19
    assert(res == Solution().deepestLeavesSum(root))
}
