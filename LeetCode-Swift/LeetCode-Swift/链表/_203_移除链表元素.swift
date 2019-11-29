//
//  _203_移除链表元素.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/11/29.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/remove-linked-list-elements/

import Foundation

class _203_移除链表元素 {
    func removeElements(_ head: ListNode?, _ val: Int) -> ListNode? {
        let virtualNode = ListNode(0)
        virtualNode.next = head
        var node = virtualNode
        while node.next != nil {
            if node.next!.val == val {
                node.next = node.next?.next
            } else {
                node = node.next!
            }
        }
        return virtualNode.next
    }
}
