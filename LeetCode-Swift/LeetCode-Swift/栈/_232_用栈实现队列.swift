//
//  _232_用栈实现队列.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/12/3.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/implement-queue-using-stacks/

import Foundation

class _232_用栈实现队列 {
    
    private var inS = [Int]()
    private var outS = [Int]()
    
    private func pushInToOutIfEmpty() {
        if (outS.isEmpty) {
            while !inS.isEmpty {
                outS.append(inS.removeLast())
            }
        }
    }
    
    /** Initialize your data structure here. */
    init() {
        
    }
    
    /** Push element x to the back of queue. */
    func push(_ x: Int) {
        inS.append(x)
    }
    
    /** Removes the element from in front of queue and returns that element. */
    func pop() -> Int {
        pushInToOutIfEmpty()
        return outS.removeLast()
    }
    
    /** Get the front element. */
    func peek() -> Int {
        pushInToOutIfEmpty();
        return outS.last ?? 0
    }
    
    /** Returns whether the queue is empty. */
    func empty() -> Bool {
        pushInToOutIfEmpty();
        return outS.isEmpty;
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * let obj = MyQueue()
 * obj.push(x)
 * let ret_2: Int = obj.pop()
 * let ret_3: Int = obj.peek()
 * let ret_4: Bool = obj.empty()
 */
