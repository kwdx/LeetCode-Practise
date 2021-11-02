/*
 * @lc app=leetcode.cn id=237 lang=swift
 *
 * [237] 删除链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *     }
 * }
 */

class Solution {
    func deleteNode(_ node: ListNode?) {
        node?.val = node?.next?.val ?? 0
        node?.next = node?.next?.next
    }
}
// @lc code=end

func main() {
    var node: ListNode?
    var res: [Int]
    
    /**
     输入：head = [4,5,1,9], node = 5
     输出：[4,1,9]
     解释：给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
     */
    node = generateListNode([4,5,1,9])
    res = [4,1,9]
    Solution().deleteNode(node?.next)
    assert(res == getNodes(node))
    
    /**
     输入：head = [4,5,1,9], node = 1
     输出：[4,5,9]
     解释：给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
     */
    node = generateListNode([4,5,1,9])
    res = [4,5,9]
    Solution().deleteNode(node?.next?.next)
    assert(res == getNodes(node))
}
