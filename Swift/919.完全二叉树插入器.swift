/*
 * @lc app=leetcode.cn id=919 lang=swift
 *
 * [919] 完全二叉树插入器
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

class CBTInserter {
    
    private var n = 0
    private let root: TreeNode?

    init(_ root: TreeNode?) {
        self.root = root
        var q: [TreeNode] = []
        if let node = root {
            q.append(node)
        }
        while !q.isEmpty {
            n += 1
            let node = q.removeFirst()
            if let l = node.left {
                q.append(l)
            }
            if let r = node.right {
                q.append(r)
            }
        }
    }
    
    func insert(_ val: Int) -> Int {
        var node = root
        n += 1
        let idx = n
        var index = idx, bits = 0
        while index > 0 {
            bits += 1
            index >>= 1
        }
        bits -= 2
        while bits > 0 {
            if idx & (1 << bits) != 0 {
                node = node?.right
            } else {
                node = node?.left
            }
            bits -= 1
        }
        if idx & 1 == 1 {
            node?.right = TreeNode(val)
        } else {
            node?.left = TreeNode(val)
        }
        return node?.val ?? 0
    }
    
    func get_root() -> TreeNode? {
        return root
    }
}

/**
 * Your CBTInserter object will be instantiated and called as such:
 * let obj = CBTInserter(root)
 * let ret_1: Int = obj.insert(val)
 * let ret_2: TreeNode? = obj.get_root()
 */
// @lc code=end

func main() {
    /**
     输入
     ["CBTInserter", "insert", "insert", "get_root"]
     [[[1, 2]], [3], [4], []]
     输出
     [null, 1, 2, [1, 2, 3, 4]]

     解释
     CBTInserter cBTInserter = new CBTInserter([1, 2]);
     cBTInserter.insert(3);  // 返回 1
     cBTInserter.insert(4);  // 返回 2
     cBTInserter.get_root(); // 返回 [1, 2, 3, 4]
     */
    var root = generateBinaryTreeByLevel([1,2])
    let cBTInserter = CBTInserter(root)
    assert(cBTInserter.insert(3) == 1)
    assert(cBTInserter.insert(4) == 2)
    root = cBTInserter.get_root()
    assert(getTreeByLevel(root) == [1,2,3,4])
}
