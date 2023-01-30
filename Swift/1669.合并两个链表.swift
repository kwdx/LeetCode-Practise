/*
 * @lc app=leetcode.cn id=1669 lang=swift
 *
 * [1669] 合并两个链表
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
    func mergeInBetween(_ list1: ListNode?, _ a: Int, _ b: Int, _ list2: ListNode?) -> ListNode? {
        var list2 = list2
        var preNode: ListNode?
        var nextNode = list1
        for i in 1...b {
            if i == a {
                preNode = nextNode
            }
            nextNode = nextNode?.next
        }
        preNode?.next = list2
        while list2?.next != nil {
            list2 = list2?.next
        }
        list2?.next = nextNode?.next
        return list1
    }
}
// @lc code=end

func main() {
    var list1: ListNode?
    var a: Int
    var b: Int
    var list2: ListNode?
    var res: [Int]
    
    /**
     输入：list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
     输出：[0,1,2,1000000,1000001,1000002,5]
     解释：我们删除 list1 中下标为 3 和 4 的两个节点，并将 list2 接在该位置。上图中蓝色的边和节点为答案链表。
     */
    list1 = generateListNode([0,1,2,3,4,5])
    a = 3
    b = 4
    list2 = generateListNode([1000000,1000001,1000002])
    res = [0,1,2,1000000,1000001,1000002,5]
    assert(res == getNodes(Solution().mergeInBetween(list1, a, b, list2)));
    
    /**
     输入：list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
     输出：[0,1,1000000,1000001,1000002,1000003,1000004,6]
     解释：上图中蓝色的边和节点为答案链表。
     */
    list1 = generateListNode([0,1,2,3,4,5,6])
    a = 2
    b = 5
    list2 = generateListNode([1000000,1000001,1000002,1000003,1000004])
    res = [0,1,1000000,1000001,1000002,1000003,1000004,6]
    assert(res == getNodes(Solution().mergeInBetween(list1, a, b, list2)))
}
