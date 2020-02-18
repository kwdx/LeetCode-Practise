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

/**
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
*/
func test_203() {
    var node = generateListNode(1, 2, 6, 3, 4, 5, 6)
    let solution = _203_移除链表元素()
    node = solution.removeElements(node, 6)
    printListNode(node)
}
