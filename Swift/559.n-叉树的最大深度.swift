/*
 * @lc app=leetcode.cn id=559 lang=swift
 *
 * [559] N 叉树的最大深度
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
    func maxDepth(_ root: Node?) -> Int {
        guard let node_ = root else { return 0 }
        
        var q: [Node] = [node_]
        var cur: Node
        
        var ans = 0
        
        while (!q.isEmpty) {
            let n = q.count
            for _ in 0..<n {
                cur = q.removeFirst()
                q.append(contentsOf: cur.children)
            }
            ans += 1
        }
        return ans
    }
}
// @lc code=end

func main() {
    var root: Node?
    var res: Int
    
    /**
     输入：root = [1,null,3,2,4,null,5,6]
     输出：3
     */
    do {
        let node3 = Node(3, [Node(5), Node(6)])
        root = Node(1, [node3, Node(2), Node(4)])
    }
    res = 3
    assert(res == Solution().maxDepth(root));
    
    /**
     输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
     输出：5
     */
    do {
        let node11 = Node(1, [Node(14)])
        let node6 = Node(6)
        let node7 = Node(7, [node11])
        let node8 = Node(8, [Node(12)])
        let node9 = Node(9, [Node(13)])

        root = Node(1, [Node(2), Node(3, [node6, node7]), Node(4, [node8]),Node(5, [node9, Node(10)])])
    }
    res = 5
    assert(res == Solution().maxDepth(root))
}
