/*
 * @lc app=leetcode.cn id=563 lang=swift
 *
 * [563] 二叉树的坡度
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
    private var ans = 0
    private func dfs(_ node: TreeNode?) -> Int {
        guard let node_ = node else { return 0 }
        
        let leftSum = dfs(node_.left)
        let rightSum = dfs(node_.right)
        ans += abs(leftSum - rightSum)
        return leftSum + rightSum + node_.val
    }
    
    func findTilt(_ root: TreeNode?) -> Int {
        _ = dfs(root)
        return ans
    }
}
// @lc code=end

func main() {
    var root: TreeNode?
    var res: Int
    
    /**
     输入：root = [1,2,3]
     输出：1
     解释：
     节点 2 的坡度：|0-0| = 0（没有子节点）
     节点 3 的坡度：|0-0| = 0（没有子节点）
     节点 1 的坡度：|2-3| = 1（左子树就是左子节点，所以和是 2 ；右子树就是右子节点，所以和是 3 ）
     坡度总和：0 + 0 + 1 = 1
     */
    root = generateTreeByLevel([1,2,3])
    res = 1
    assert(res == Solution().findTilt(root))
    
    /**
     输入：root = [4,2,9,3,5,null,7]
     输出：15
     解释：
     节点 3 的坡度：|0-0| = 0（没有子节点）
     节点 5 的坡度：|0-0| = 0（没有子节点）
     节点 7 的坡度：|0-0| = 0（没有子节点）
     节点 2 的坡度：|3-5| = 2（左子树就是左子节点，所以和是 3 ；右子树就是右子节点，所以和是 5 ）
     节点 9 的坡度：|0-7| = 7（没有左子树，所以和是 0 ；右子树正好是右子节点，所以和是 7 ）
     节点 4 的坡度：|(3+5+2)-(9+7)| = |10-16| = 6（左子树值为 3、5 和 2 ，和是 10 ；右子树值为 9 和 7 ，和是 16 ）
     坡度总和：0 + 0 + 0 + 2 + 7 + 6 = 15
     */
    root = generateTreeByLevel([4,2,9,3,5,nil,7])
    res = 15
    assert(res == Solution().findTilt(root))
    
    /**
     输入：root = [21,7,14,1,1,2,2,3,3]
     输出：9
     */
    root = generateTreeByLevel([21,7,14,1,1,2,2,3,3])
    res = 9
    assert(res == Solution().findTilt(root))
}
