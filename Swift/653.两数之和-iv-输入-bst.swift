/*
 * @lc app=leetcode.cn id=653 lang=swift
 *
 * [653] 两数之和 IV - 输入 BST
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
    private var sets: Set<Int> = []
    func findTarget(_ root: TreeNode?, _ k: Int) -> Bool {
        guard let node = root else { return false }
        if sets.contains(k - node.val) {
            return true
        }
        sets.insert(node.val)
        return findTarget(node.left, k) || findTarget(node.right, k)
    }
}
// @lc code=end

func main() {
    var root: TreeNode?
    var k: Int
    var res: Bool
    
    /**
     输入: root = [5,3,6,2,4,null,7], k = 9
     输出: true
     */
    root = generateTreeByLevel([5,3,6,2,4,nil,7])
    k = 9
    res = true
    assert(res == Solution().findTarget(root, k))
    
    /**
     输入: root = [5,3,6,2,4,null,7], k = 28
     输出: false
     */
    root = generateTreeByLevel([5,3,6,2,4,nil,7])
    k = 28
    res = false
    assert(res == Solution().findTarget(root, k))
}
