/*
 * @lc app=leetcode.cn id=654 lang=swift
 *
 * [654] 最大二叉树
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
    func constructMaximumBinaryTree(_ nums: [Int]) -> TreeNode? {
        return buildTree(nums, left: 0, right: nums.count)
    }
    
    private func buildTree(_ nums: [Int], left: Int, right: Int) -> TreeNode? {
        guard left < right else { return nil }
        var val = nums[left]
        var index = left
        for i in left..<right {
            if nums[i] > val {
                val = nums[i]
                index = i
            }
        }
        let node = TreeNode(val)
        node.left = buildTree(nums, left: left, right: index)
        node.right = buildTree(nums, left: index + 1, right: right)
        return node
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var node: TreeNode?
    var res: [Int?]

    /**
     输入：nums = [3,2,1,6,0,5]
     输出：[6,3,5,null,2,0,null,null,1]
     解释：递归调用如下所示：
     - [3,2,1,6,0,5] 中的最大值是 6 ，左边部分是 [3,2,1] ，右边部分是 [0,5] 。
         - [3,2,1] 中的最大值是 3 ，左边部分是 [] ，右边部分是 [2,1] 。
             - 空数组，无子节点。
             - [2,1] 中的最大值是 2 ，左边部分是 [] ，右边部分是 [1] 。
                 - 空数组，无子节点。
                 - 只有一个元素，所以子节点是一个值为 1 的节点。
         - [0,5] 中的最大值是 5 ，左边部分是 [0] ，右边部分是 [] 。
             - 只有一个元素，所以子节点是一个值为 0 的节点。
             - 空数组，无子节点。
     */
    nums = [3,2,1,6,0,5]
    res = [6,3,5,nil,2,0,nil,nil,1]
    node = Solution().constructMaximumBinaryTree(nums)
    assert(res == getTreeByLevel(node))

    /**
     输入：nums = [3,2,1]
     输出：[3,null,2,null,1]
     */
    nums = [3,2,1]
    res = [3,nil,2,nil,1]
    node = Solution().constructMaximumBinaryTree(nums)
    assert(res == getTreeByLevel(node))
}
