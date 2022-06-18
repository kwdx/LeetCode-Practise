//
//  029.排序的循环链表.swift
//  Swift_
//
//  Created by warden on 2022/6/18.
//

public class Node {
    public var val: Int
    public var next: Node?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

// @lc code=start
/**
 * Definition for a Node.
 * public class Node {
 *     public var val: Int
 *     public var next: Node?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *     }
 * }
 */

class Solution {
    func insert(_ head: Node?, _ insertVal: Int) -> Node? {
        let node = Node(insertVal)
        node.next = node
        guard var p = head else {
            return node
        }
        while p.next !== head {
            if p.val > p.next!.val {
                break
            }
            p = p.next!
        }
        if p.val <= insertVal || p.next!.val >= insertVal {
            node.next = p.next!
            p.next = node
        } else {
            while p.next!.val < insertVal {
                p = p.next!
            }
            node.next = p.next!
            p.next = node
        }
        return head
    }
}
// @lc code=end

func main() {
    var head: Node?
    var insertVal: Int
    var res: Node?
    
    /**
     输入：head = [3,4,1], insertVal = 2
     输出：[3,4,1,2]
     解释：在上图中，有一个包含三个元素的循环有序列表，你获得值为 3 的节点的指针，我们需要向表中插入元素 2 。新插入的节点应该在 1 和 3 之间，插入之后，整个列表如上图所示，最后返回节点 3 。
     */
    head = Node(3)
    head?.next = Node(4)
    head?.next?.next = Node(1)
    head?.next?.next?.next = head
    insertVal = 2
    res = head
    assert(res?.val == Solution().insert(head, insertVal)?.val)

    /**
     输入：head = [], insertVal = 1
     输出：[1]
     解释：列表为空（给定的节点是 null），创建一个循环有序列表并返回这个节点。
     */
    head = nil
    insertVal = 1
    res = Node(1)
    assert(res?.val == Solution().insert(head, insertVal)?.val)
    
    /**
     输入：head = [1], insertVal = 0
     输出：[1,0]
     */
    head = Node(1)
    head?.next = head
    insertVal = 0
    res = head
    assert(res?.val == Solution().insert(head, insertVal)?.val)
    
    /**
     输入：head = [3,4,1], insertVal = 2
     输出：[3,4,2,1]
     */
    head = Node(3)
    head?.next = Node(4)
    head?.next?.next = Node(1)
    head?.next?.next?.next = head
    insertVal = 2
    res = head
    assert(res?.val == Solution().insert(head, insertVal)?.val)
}
