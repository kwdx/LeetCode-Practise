//
//  _225_用队列实现栈.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/12/3.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/implement-stack-using-queues/

import Foundation

class _225_用队列实现栈 {
    private var queue = [Int]()
    /** Initialize your data structure here. */
    init() {
    }
    
    /** Push element x onto stack. */
    func push(_ x: Int) {
        let count = queue.count
        queue.append(x)
        for _ in 0..<count {
            queue.append(queue.removeFirst())
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    func pop() -> Int {
        return queue.removeFirst()
    }
    
    /** Get the top element. */
    func top() -> Int {
        return queue.first ?? 0
    }
    
    /** Returns whether the stack is empty. */
    func empty() -> Bool {
        return queue.isEmpty
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * let obj = MyStack()
 * obj.push(x)
 * let ret_2: Int = obj.pop()
 * let ret_3: Int = obj.top()
 * let ret_4: Bool = obj.empty()
 */
