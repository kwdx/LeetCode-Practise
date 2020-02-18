//
//  _23_合并K个排序链表.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/merge-k-sorted-lists

import Foundation

class _23_合并K个排序链表 {
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

/**
 输入:
 [
   1->4->5,
   1->3->4,
   2->6
 ]
 输出: 1->1->2->3->4->4->5->6
*/
func test_23() {
    let node1 = generateListNode(1, 4, 5)
    let node2 = generateListNode(1, 3, 4)
    let node3 = generateListNode(2, 6)
    let solution = _23_合并K个排序链表()
    let result = solution.mergeKLists([node1, node2, node3])
    printListNode(result)
}
