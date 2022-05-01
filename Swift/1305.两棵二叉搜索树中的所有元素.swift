/*
 * @lc app=leetcode.cn id=1305 lang=swift
 *
 * [1305] 两棵二叉搜索树中的所有元素
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
    func preorderTraversal(_  root: TreeNode?) -> [Int] {
        var ans: [Int] = []
        var st: [TreeNode] = []
        var node = root
        while node != nil || !st.isEmpty  {
            while node != nil {
                st.append(node!)
                node = node?.left
            }
            node = st.removeLast()
            ans.append(node!.val)
            node = node?.right
        }
        return ans
    }
    
    func getAllElements(_ root1: TreeNode?, _ root2: TreeNode?) -> [Int] {
        let a = preorderTraversal(root1)
        let b = preorderTraversal(root2)
        return (a + b).sorted()
    }
}
// @lc code=end

func main() {
    var root1: TreeNode?
    var root2: TreeNode?
    var res: [Int]
    
    /**'
     输入：root1 = [2,1,4], root2 = [1,0,3]
     输出：[0,1,1,2,3,4]
     */
    root1 = generateBinaryTree([2,1,4])
    root2 = generateBinaryTree([1,0,3])
    res = [0,1,1,2,3,4]
    assert(res == Solution().getAllElements(root1, root2))
    
    /**'
     输入：root1 = [1,null,8], root2 = [8,1]
     输出：[1,1,8,8]
     */
    root1 = generateBinaryTree([1,8])
    root2 = generateBinaryTree([8,1])
    res = [1,1,8,8]
    assert(res == Solution().getAllElements(root1, root2))
}
