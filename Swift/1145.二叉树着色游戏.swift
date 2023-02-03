/*
 * @lc app=leetcode.cn id=1145 lang=swift
 *
 * [1145] 二叉树着色游戏
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
    func btreeGameWinningMove(_ root: TreeNode?, _ n: Int, _ x: Int) -> Bool {
        let xNode = findNode(root, x)
        let val = (n + 1) / 2
        let leftSize = getSubtreeSize(xNode?.left)
        if leftSize >= val {
            return true
        }
        let rightSize = getSubtreeSize(xNode?.right)
        if rightSize >= val {
            return true
        }
        let remain = n - 1 - leftSize - rightSize
        return remain >= val
    }
    
    func findNode(_ node: TreeNode?, _ x: Int) -> TreeNode? {
        guard let node = node else {
            return nil
        }
        if node.val == x {
            return node
        }
        return findNode(node.left, x) ?? findNode(node.right, x)
    }
    
    func getSubtreeSize(_ node: TreeNode?) -> Int {
        guard let node = node else {
            return 0
        }
        return 1 + getSubtreeSize(node.left) + getSubtreeSize(node.right)
    }
}
// @lc code=end

func main() {
    var root: TreeNode?
    var n: Int
    var x: Int
    var res: Bool
    
    /**
     输入：root = [1,2,3,4,5,6,7,8,9,10,11], n = 11, x = 3
     输出：true
     解释：第二个玩家可以选择值为 2 的节点。
     */
    root = generateTreeByLevel([1,2,3,4,5,6,7,8,9,10,11])
    n = 11
    x = 3
    res = true
    assert(res == Solution().btreeGameWinningMove(root, n, x))
    
    /**
     输入：root = [1,2,3], n = 3, x = 1
     输出：false
     */
    root = generateTreeByLevel([1,2,3])
    n = 3
    x = 1
    res = false
    assert(res == Solution().btreeGameWinningMove(root, n, x))
}
