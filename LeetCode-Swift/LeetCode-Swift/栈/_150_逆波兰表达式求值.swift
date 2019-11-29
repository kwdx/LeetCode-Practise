//
//  _150_逆波兰表达式求值.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/evaluate-reverse-polish-notation

import Foundation

//class Solution {
class _150_逆波兰表达式求值 {
    func evalRPN(_ tokens: [String]) -> Int {
        var stack = [Int]()
        for token in tokens {
            switch token {
            case "+":
                stack.append(stack.popLast()! + stack.popLast()!)
            case "-":
                stack.append(-stack.popLast()! + stack.popLast()!)
            case "*":
                stack.append(stack.popLast()! * stack.popLast()!)
            case "/":
                let right = stack.popLast()!
                let left = stack.popLast()!
                stack.append(left / right)
            default:
                stack.append(Int(token)!)
            }
        }
        return stack.popLast()!
    }
}
