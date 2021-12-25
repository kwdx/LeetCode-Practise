/*
 * @lc app=leetcode.cn id=1609 lang=swift
 *
 * [1609] 奇偶树
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
    func isEvenOddTree(_ root: TreeNode?) -> Bool {
        guard var node = root else { return true }
        var queue: [TreeNode] = [node]
        var isOdd = false
        while !queue.isEmpty {
            let n = queue.count
            var preVal = isOdd ? queue.first!.val + 1 : 0
            for _ in 0..<n {
                node = queue.removeFirst()
                if isOdd {
                    // 基数层，偶数、递减
                    if node.val >= preVal || node.val & 0x1 == 1 {
                        return false
                    }
                } else {
                    // 偶数层，奇数、递增
                    if node.val <= preVal || node.val & 0x1 == 0 {
                        return false
                    }
                }
                preVal = node.val
                if let leftN = node.left {
                    queue.append(leftN)
                }
                if let rightN = node.right {
                    queue.append(rightN)
                }
            }
            isOdd.toggle()
        }
        return true
    }
}
// @lc code=end

func main() {
    var nodes: [Int?]
    var root: TreeNode?
    var res: Bool
    
    /**
     输入：root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
     输出：true
     解释：每一层的节点值分别是：
     0 层：[1]
     1 层：[10,4]
     2 层：[3,7,9]
     3 层：[12,8,6,2]
     由于 0 层和 2 层上的节点值都是奇数且严格递增，而 1 层和 3 层上的节点值都是偶数且严格递减，因此这是一棵奇偶树。
     */
//    nodes = [1,10,4,3,nil,7,9,12,8,6,nil,nil,2]
//    root = generateTreeByLevel(nodes)
//    res = true
//    assert(res == Solution().isEvenOddTree(root))
    
    /**
     输入：root = [5,4,2,3,3,7]
     输出：false
     解释：每一层的节点值分别是：
     0 层：[5]
     1 层：[4,2]
     2 层：[3,3,7]
     2 层上的节点值不满足严格递增的条件，所以这不是一棵奇偶树。
     */
    nodes = [5,4,2,3,3,7]
    root = generateTreeByLevel(nodes)
    res = false
    assert(res == Solution().isEvenOddTree(root))
    
    /**
     输入：root = [5,9,1,3,5,7]
     输出：false
     解释：1 层上的节点值应为偶数。
     */
    nodes = [5,9,1,3,5,7]
    root = generateTreeByLevel(nodes)
    res = false
    assert(res == Solution().isEvenOddTree(root))
    
    /**
     输入：root = [1]
     输出：true
     */
    nodes = [1]
    root = generateTreeByLevel(nodes)
    res = true
    assert(res == Solution().isEvenOddTree(root))
    
    /**
     输入：root = [11,8,6,1,3,9,11,30,20,18,16,12,10,4,2,17]
     输出：true
     */
    nodes = [11,8,6,1,3,9,11,30,20,18,16,12,10,4,2,17]
    root = generateTreeByLevel(nodes)
    res = true
    assert(res == Solution().isEvenOddTree(root))
}
