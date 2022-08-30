/*
 * @lc app=leetcode.cn id=998 lang=swift
 *
 * [998] 最大二叉树 II
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
    func insertIntoMaxTree(_ root: TreeNode?, _ val: Int) -> TreeNode? {
        var parent: TreeNode?
        var cur = root
        while let cur_ = cur {
            if val > cur_.val {
                if parent == nil {
                    return TreeNode(val, root, nil)
                }
                let node = TreeNode(val, cur, nil)
                parent?.right = node
                return root
            } else {
                parent = cur_
                cur = cur_.right
            }
        }
        parent?.right = TreeNode(val)
        return root
    }
}
// @lc code=end

func main() {
    var root: TreeNode?
    var val: Int
    var res: [Int?]
    
    /**
     输入：root = [4,1,3,null,null,2], val = 5
     输出：[5,4,null,1,3,null,null,2]
     解释：a = [1,4,2,3], b = [1,4,2,3,5]
     */
    root = generateTreeByLevel([4,1,3,nil,nil,2])
    val = 5
    res = [5,4,nil,1,3,nil,nil,2]
    assert(res == getTreeByLevel(Solution().insertIntoMaxTree(root, val)))

    /**
     输入：root = [5,2,4,null,1], val = 3
     输出：[5,2,4,null,1,null,3]
     解释：a = [2,1,5,4], b = [2,1,5,4,3]
     */
    root = generateTreeByLevel([5,2,4,nil,1])
    val = 3
    res = [5,2,4,nil,1,nil,3]
    assert(res == getTreeByLevel(Solution().insertIntoMaxTree(root, val)))
    
    /**
     输入：root = [5,2,3,null,1], val = 4
     输出：[5,2,4,null,1,3]
     解释：a = [2,1,5,3], b = [2,1,5,3,4]
     */
    root = generateTreeByLevel([5,2,3,nil,1])
    val = 4
    res = [5,2,4,nil,1,3]
    assert(res == getTreeByLevel(Solution().insertIntoMaxTree(root, val)))
}
