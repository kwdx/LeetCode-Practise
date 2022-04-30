/*
 * @lc app=leetcode.cn id=429 lang=swift
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/**
 * Definition for a Node.
 * public class Node {
 *     public var val: Int
 *     public var children: [Node]
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.children = []
 *     }
 * }
 */

class Solution {
    func levelOrder(_ root: Node?) -> [[Int]] {
        var ans: [[Int]] = []
        
        guard root != nil else {
            return ans
        }
        
        var q: [Node] = [root!]
        
        while !q.isEmpty {
            let n = q.count
            var v: [Int] = []
            for _ in 0..<n {
                let node = q.removeFirst()
                v.append(node.val)
                q.append(contentsOf: node.children)
            }
            ans.append(v)
        }
        return ans
    }
}
// @lc code=end

func main() {
    var root: Node?
    var res: [[Int]]
    
    /**
     输入：root = [1,null,3,2,4,null,5,6]
     输出：[[1],[3,2,4],[5,6]]
     */
    root = generateTreeByLevel([1,nil,3,2,4,nil,5,6])
    res = [[1],[3,2,4],[5,6]]
    assert(res == Solution().levelOrder(root))
    
    /**
     输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
     输出：[[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
     */
    root = generateTreeByLevel([1,nil,2,3,4,5,nil,nil,6,7,nil,8,nil,9,10,nil,nil,11,nil,12,nil,13,nil,nil,14]);
    res = [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
    assert(res == Solution().levelOrder(root))
}
