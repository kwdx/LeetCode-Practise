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

/**
输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。

输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。

输入：head = [1], pos = -1
输出：false
解释：链表中没有环。
*/
func test_141() {
    var node = generateListNode(3, 2, 0, -4)
    node?.next?.next?.next?.next = node?.next
    let solution = _141_环形链表()
    print(solution.hasCycle(node!))
    node = generateListNode(1, 2)
    node?.next?.next = node
    print(solution.hasCycle(node!))
    node = generateListNode(1)
    print(solution.hasCycle(node!))
}
