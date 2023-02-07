/*
 * @lc app=leetcode.cn id=2331 lang=swift
 *
 * [2331] 计算布尔二叉树的值
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
    func evaluateTree(_ root: TreeNode?) -> Bool {
        switch root?.val {
        case 0:
            return false
        case 1:
            return true
        case 2:
            return evaluateTree(root?.left) || evaluateTree(root?.right)
        case 3:
            return evaluateTree(root?.left) && evaluateTree(root?.right)
        default:
            return false
        }
    }
}
// @lc code=end

func main() {
    var root: TreeNode?
    var res: Bool
    
    /**
     输入：root = [2,1,3,null,null,0,1]
     输出：true
     解释：上图展示了计算过程。
     AND 与运算节点的值为 False AND True = False 。
     OR 运算节点的值为 True OR False = True 。
     根节点的值为 True ，所以我们返回 true 。
     */
    root = generateTreeByLevel([2,1,3,nil,nil,0,1])
    res = true
    assert(res == Solution().evaluateTree(root))
    
    /**
     输入：root = [0]
     输出：false
     解释：根节点是叶子节点，且值为 false，所以我们返回 false 。
     */
    root = generateTreeByLevel([0])
    res = false
    assert(res == Solution().evaluateTree(root))
}
