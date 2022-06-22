/*
 * @lc app=leetcode.cn id=513 lang=swift
 *
 * [513] 找树左下角的值
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
    func findBottomLeftValue(_ root: TreeNode?) -> Int {
        var ans = root!.val
        var q: [TreeNode] = [root!]
        while !q.isEmpty {
            ans = q.first!.val
            for _ in 0..<q.count {
                let node = q.removeFirst()
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
     输入: root = [2,1,3]
     输出: 1
     */
    root = generateTreeByLevel([2,1,3])
    res = 1
    assert(res == Solution().findBottomLeftValue(root))
    
    /**
     输入: [1,2,3,4,null,5,6,null,null,7]
     输出: 7
     */
    root = generateTreeByLevel([1,2,3,4,nil,5,6,nil,nil,7])
    res = 7
    assert(res == Solution().findBottomLeftValue(root))
}
