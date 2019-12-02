//
//  _876_链表的中间结点.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/12/2.
//  Copyright © 2019 warden. All rights reserved.
//
// // https://leetcode-cn.com/problems/middle-of-the-linked-list/

import Foundation

class _876_链表的中间结点 {
    func middleNode(_ head: ListNode?) -> ListNode? {
        var slow = head
        var fast = head?.next
        while fast != nil && fast?.next != nil {
            slow = slow?.next
            fast = fast?.next?.next
        }
        return fast != nil ? slow?.next : slow
    }
}
