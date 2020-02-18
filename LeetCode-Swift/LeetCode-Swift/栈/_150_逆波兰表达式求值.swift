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

/**
示例 1：

输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: ((2 + 1) * 3) = 9
示例 2：

输入: ["4", "13", "5", "/", "+"]
输出: 6
解释: (4 + (13 / 5)) = 6
示例 3：

输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
输出: 22
*/
func test_150() {
    let solution = _150_逆波兰表达式求值()
    print(solution.evalRPN(["2", "1", "+", "3", "*"]))
    print(solution.evalRPN(["4", "13", "5", "/", "+"]))
    print(solution.evalRPN(["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]))
}
