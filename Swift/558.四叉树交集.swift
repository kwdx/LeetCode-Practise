/*
 * @lc app=leetcode.cn id=558 lang=swift
 *
 * [558] 四叉树交集
 */

public class Node {
    public var val: Bool
    public var isLeaf: Bool
    public var topLeft: Node?
    public var topRight: Node?
    public var bottomLeft: Node?
    public var bottomRight: Node?
    public init(_ val: Bool, _ isLeaf: Bool) {
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = nil
        self.topRight = nil
        self.bottomLeft = nil
        self.bottomRight = nil
    }
}

// @lc code=start
/**
 * Definition for a Node.
 * public class Node {
 *     public var val: Bool
 *     public var isLeaf: Bool
 *     public var topLeft: Node?
 *     public var topRight: Node?
 *     public var bottomLeft: Node?
 *     public var bottomRight: Node?
 *     public init(_ val: Bool, _ isLeaf: Bool) {
 *         self.val = val
 *         self.isLeaf = isLeaf
 *         self.topLeft = nil
 *         self.topRight = nil
 *         self.bottomLeft = nil
 *         self.bottomRight = nil
 *     }
 * }
 */

class Solution {
    func intersect(_ quadTree1: Node?, _ quadTree2: Node?) -> Node? {
        if let node1 = quadTree1, node1.isLeaf {
            if node1.val {
                return Node(true, true)
            }
            let node = Node(quadTree2?.val ?? false, quadTree2?.isLeaf ?? false)
            node.topLeft = quadTree2?.topLeft
            node.topRight = quadTree2?.topRight
            node.bottomLeft = quadTree2?.bottomLeft
            node.bottomRight = quadTree2?.bottomRight
            return node
        }
        if quadTree2?.isLeaf ?? false {
            return intersect(quadTree2, quadTree1)
        }
        let o1 = intersect(quadTree1?.topLeft, quadTree2?.topLeft)
        let o2 = intersect(quadTree1?.topRight, quadTree2?.topRight)
        let o3 = intersect(quadTree1?.bottomLeft, quadTree2?.bottomLeft)
        let o4 = intersect(quadTree1?.bottomRight, quadTree2?.bottomRight)
        
        if let o1 = o1, let o2 = o2, let o3 = o3, let o4 = o4,
           o1.isLeaf && o2.isLeaf && o3.isLeaf && o4.isLeaf,
           o1.val == o2.val, o1.val == o3.val, o1.val == o4.val {
            return Node(o1.val, true)
        }
        let node = Node(false, false)
        node.topLeft = o1
        node.topRight = o2
        node.bottomLeft = o3
        node.bottomRight = o4
        return node
    }
}
// @lc code=end

func main() {
    
}
