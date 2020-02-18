//
//  _237_删除链表中的节点.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/11/27.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/delete-node-in-a-linked-list

import Foundation

class _237_删除链表中的节点 {
    func deleteNode(_ node: ListNode) {
        node.val = node.next!.val
        node.next = node.next?.next
    }
}

/**
 输入: head = [4,5,1,9], node = 5
 输出: [4,1,9]
 解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.

 输入: head = [4,5,1,9], node = 1
 输出: [4,5,9]
 解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
*/
func test_237() {
    let node1 = generateListNode(4, 5, 1, 9)
    let solution = _237_删除链表中的节点()
//    solution.deleteNode(node1!.next!)
    solution.deleteNode(node1!.next!.next!)
    printListNode(node1)
}
