//
//  _21_合并两个有序链表.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/merge-two-sorted-lists

import Foundation

class _21_合并两个有序链表 {
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

/**
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/
func test_21() {
    let node1 = generateListNode(1, 2, 4)
    let node2 = generateListNode(1, 3, 4)
    let solution = _21_合并两个有序链表()
    let result = solution.mergeTwoLists(node1, node2)
    printListNode(result)
}
