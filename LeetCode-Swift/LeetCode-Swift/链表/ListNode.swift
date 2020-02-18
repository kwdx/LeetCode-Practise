//
//  ListNode.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//

import Foundation

public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

// 生成节点链表
func generateListNode(_ nodes: Int ...) -> ListNode? {
    let head = ListNode(0)
    var p = head
    for node in nodes {
        p.next = ListNode(node)
        p = p.next!
    }
    return head.next
}

// 打印节点链表
func printListNode(_ node: ListNode?) {
    if node == nil {
        return
    }
    var printNode = node;
    var arr = [String]()
    while printNode != nil {
        arr.append(String(printNode!.val))
        printNode = printNode?.next
    }
    print(arr)
}
