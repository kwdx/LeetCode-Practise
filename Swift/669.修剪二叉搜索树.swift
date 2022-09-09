/*
 * @lc app=leetcode.cn id=669 lang=swift
 *
 * [669] 修剪二叉搜索树
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
    func trimBST(_ root: TreeNode?, _ low: Int, _ high: Int) -> TreeNode? {
        var root = root
        while let node = root,
              node.val < low || node.val > high {
            if node.val < low {
                root = node.right
            } else {
                root = node.left
            }
        }
        guard root != nil else {
            return nil
        }
        var node = root
        while let left = node?.left {
            if left.val < low {
                node?.left = left.right
            } else {
                node = left
            }
        }
        node = root
        while let right = node?.right {
            if right.val > high {
                node?.right = right.left
            } else {
                node = right
            }
        }
        return root
    }
}
// @lc code=end

func main() {
    var root: TreeNode?
    var low: Int
    var high: Int
    var res: TreeNode?
    
    /**
     输入：root = [1,0,2], low = 1, high = 2
     输出：[1,null,2]
     */
    root = generateTreeByLevel([1,0,2])
    low = 1
    high = 2
    res = Solution().trimBST(root, low, high)
    assert([1,nil,2] == getTreeByLevel(res))
    
    /**
     输入：root = [3,0,4,null,2,null,null,1], low = 1, high = 3
     输出：[3,2,null,1]
     */
    root = generateTreeByLevel([3,0,4,nil,2,nil,nil,1])
    low = 1
    high = 3
    res = Solution().trimBST(root, low, high)
    assert([3,2,nil,1] == getTreeByLevel(res))
}
