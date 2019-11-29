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
