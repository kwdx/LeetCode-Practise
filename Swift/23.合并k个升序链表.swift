/*
 * @lc app=leetcode.cn id=23 lang=swift
 *
 * [23] 合并K个升序链表
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
    func mergeKLists(_ lists: [ListNode?]) -> ListNode? {
        let count = lists.count
        if count == 0 {
            return nil
        }
        
        var result = lists
        var step = 1
        while step < count {
            let nextStep = step << 1
            for i in stride(from: 0, to: count - step, by: nextStep) {
                result[i] = mergeTwoLists(result[i], result[i + step])
            }
            step = nextStep
        }
        
        return result.first!
    }
    
    private func mergeTwoLists(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
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
    var lists: [[Int]]
    var res: [Int]
    
    /**
     输入：lists = [[1,4,5],[1,3,4],[2,6]]
     输出：[1,1,2,3,4,4,5,6]
     解释：链表数组如下：
     [
       1->4->5,
       1->3->4,
       2->6
     ]
     将它们合并到一个有序链表中得到。
     1->1->2->3->4->4->5->6
     */
    lists = [[1,4,5],[1,3,4],[2,6]]
    res = [1,1,2,3,4,4,5,6]
    assert(res == Solution().mergeKLists(generateListNode(lists))?.nodes)
    
    /**
     输入：lists = []
     输出：[]
     */
    lists = []
    res = []
    assert(res == (Solution().mergeKLists(generateListNode(lists))?.nodes ?? []))
    
    /**
     输入：lists = [[]]
     输出：[]
     */
    lists = [[]]
    res = []
    assert(res == (Solution().mergeKLists(generateListNode(lists))?.nodes ?? []))
}
