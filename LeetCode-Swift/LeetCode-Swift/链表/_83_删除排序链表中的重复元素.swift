//
//  _83_删除排序链表中的重复元素.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/12/2.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/

import Foundation

class _83_删除排序链表中的重复元素 {
    func deleteDuplicates(_ head: ListNode?) -> ListNode? {
        var node = head
        while node?.next != nil {
            if node?.val == node?.next?.val {
                node?.next = node?.next?.next
            } else {
                node = node?.next
            }
        }
        return head
    }
}

/**
示例 1:
输入: 1->1->2
输出: 1->2

示例 2:
输入: 1->1->2->3->3
输出: 1->2->3
*/
func test_83() {
    let node = generateListNode(1)
    let solution = _83_删除排序链表中的重复元素()
    printListNode(solution.deleteDuplicates(node))
}
