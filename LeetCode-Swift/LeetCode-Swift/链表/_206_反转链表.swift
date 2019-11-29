//
//  _206_反转链表.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/11/27.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/reverse-linked-list/

import Foundation

class _206_反转链表 {
    func reverseList(_ head: ListNode?) -> ListNode? {
        var node = head?.next
        var pre = head
        while head?.next != nil {
            head?.next = node?.next
            node?.next = pre
            pre = node
            node = head?.next
        }
        head?.next = nil
        return pre
    }
}
