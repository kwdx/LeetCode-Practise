/*
 * @lc app=leetcode.cn id=1161 lang=swift
 *
 * [1161] 最大层内元素和
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
    func maxLevelSum(_ root: TreeNode?) -> Int {
        var ans = 1
        var level = 1
        var q: [TreeNode] = [root!]
        var maxVal = Int.min
        while !q.isEmpty {
            let sz = q.count
            var tmp = 0
            for _ in 0..<sz {
                let node = q.removeFirst()
                tmp += node.val
                if let child = node.left {
                    q.append(child)
                }
                if let child = node.right {
                    q.append(child)
                }
            }
            if tmp > maxVal {
                maxVal = tmp
                ans = level
            }
            level += 1
        }
        return ans
    }
}
// @lc code=end

func main() {
    var root: TreeNode?
    var res: Int
    
    /**
     输入：root = [1,7,0,7,-8,null,null]
     输出：2
     解释：
     第 1 层各元素之和为 1，
     第 2 层各元素之和为 7 + 0 = 7，
     第 3 层各元素之和为 7 + -8 = -1，
     所以我们返回第 2 层的层号，它的层内元素之和最大。
     */
    root = generateTreeByLevel([1,7,0,7,-8])
    res = 2
    assert(res == Solution().maxLevelSum(root))
    
    /**
     输入：root = [989,null,10250,98693,-89388,null,null,null,-32127]
     输出：2
     */
    root = generateTreeByLevel([989,nil,10250,98693,-89388,nil,nil,nil,-32127]);
    res = 2
    assert(res == Solution().maxLevelSum(root))
}
