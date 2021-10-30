/*
 * @lc app=leetcode.cn id=21 lang=swift
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init() { self.val = 0; self.next = nil; }
 *     public init(_ val: Int) { self.val = val; self.next = nil; }
 *     public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
 * }
 */
class Solution {
    func mergeTwoLists(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var list1 = l1
        var list2 = l2
        var p: ListNode?

        let head = ListNode(0)
        p = head
        
        while (list1 != nil && list2 != nil) {
            if (list1!.val < list2!.val) {
                p?.next = list1
                list1 = list1!.next
            } else {
                p?.next = list2
                list2 = list2?.next
            }
            p = p?.next
        }
        
        p?.next = list1 ?? list2
        
        return head.next
    }
}
// @lc code=end

func main() {
    var l1: ListNode?
    var l2: ListNode?
    var res: ListNode?
    
    /**
     输入：l1 = [1,2,4], l2 = [1,3,4]
     输出：[1,1,2,3,4,4]
     */
    l1 = generateListNode([1,2,4])
    l2 = generateListNode([1,3,4])
    res = generateListNode([1,1,2,3,4,4])
    assert(res == Solution().mergeTwoLists(l1, l2))
    
    /**
     输入：l1 = [], l2 = []
     输出：[]
     */
    l1 = generateListNode([])
    l2 = generateListNode([])
    res = generateListNode([])
    assert(res == Solution().mergeTwoLists(l1, l2))
    
    /**
     输入：l1 = [], l2 = [0]
     输出：[0]
     */
    l1 = generateListNode([])
    l2 = generateListNode([0])
    res = generateListNode([0])
    assert(res == Solution().mergeTwoLists(l1, l2))
}
