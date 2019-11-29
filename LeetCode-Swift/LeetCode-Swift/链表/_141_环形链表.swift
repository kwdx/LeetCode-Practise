//
//  _141_环形链表.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/11/29.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/linked-list-cycle/

import Foundation

class _141_环形链表 {
    func hasCycle(_ head: ListNode) -> Bool {
        var slow = head
        var fast = head.next
        while (fast != nil) && (fast?.next != nil) {
            if slow === fast! {
                return true
            }
            slow = slow.next!
            fast = fast?.next?.next
        }
        return false
    }
}
