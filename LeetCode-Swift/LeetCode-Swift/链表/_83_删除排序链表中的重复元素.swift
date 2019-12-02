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
