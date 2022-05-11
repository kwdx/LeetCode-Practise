/*
 * @lc app=leetcode.cn id=449 lang=swift
 *
 * [449] 序列化和反序列化二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *     }
 * }
 */

class Codec {
    // Encodes a tree to a single string.
    func serialize(_ root: TreeNode?) -> String {
        guard let node = root else {
            return "#"
        }
        return "\(node.val)_\(serialize(node.left))_\(serialize(node.right))"
    }
    
    // Decodes your encoded data to tree.
    func deserialize(_ data: String) -> TreeNode? {
        guard !data.isEmpty else { return nil }
        
        var datas: [String] = []
        var s: String = ""
        for c in data {
            if (c == "_") {
                datas.append(s)
                s = ""
            } else {
                s.append(c)
            }
        }
        if !s.isEmpty {
            datas.append(s)
        }
        
        var st: [TreeNode] = []
        let root = node(for: datas.removeFirst());
        var curNode: TreeNode? = root
        
        while !datas.isEmpty {
            while curNode != nil {
                st.append(curNode!)
                curNode?.left = node(for: datas.removeFirst())
                curNode = curNode?.left
            }
            curNode = st.removeLast();
            curNode?.right = node(for: datas.removeFirst())
            curNode = curNode?.right
        }
        
        return root
    }
    
    func node(for val: String) -> TreeNode? {
        if val == "#" {
            return nil
        }
        return TreeNode(Int(val)!)
    }
}

/**
 * Your Codec object will be instantiated and called as such:
 * let ser = Codec()
 * let deser = Codec()
 * let tree: String = ser.serialize(root)
 * let ans = deser.deserialize(tree)
 * return ans
*/
// @lc code=end

func main() {
    let ser = Codec()
    let deser = Codec()
    var root: TreeNode?
    var tree: String
    var ans: TreeNode?

    /**
     输入：root = [2,1,3]
     输出：[2,1,3]
     */
    root = generateBinaryTree([2,1,3])
    tree = ser.serialize(root)
    ans = deser.deserialize(tree)
    assert([2,1,3] == getTreeByLevel(ans))
    
    /**
     输入：root = []
     输出：[]
     */
    root = generateBinaryTree([])
    tree = ser.serialize(root)
    ans = deser.deserialize(tree)
    assert([] == getTreeByLevel(ans))
}
