//
//  _20_有效的括号.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/12/2.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/valid-parentheses/

import Foundation

class _20_有效的括号 {
    func isValid(_ s: String) -> Bool {
        var stack = [String]()
        for ch in s {
            let chstr = String(ch)
            switch chstr {
            case "(", "[", "{":
                stack.append(chstr)
            case ")":
                if stack.popLast() != "(" {
                    return false
                }
            case "]":
                if stack.popLast() != "[" {
                    return false
                }
            case "}":
                if stack.popLast() != "{" {
                    return false
                }
            default: break
            }
        }
        return stack.isEmpty
    }
}

/**
 输入: "()"
 输出: true

 输入: "()[]{}"
 输出: true

 输入: "(]"
 输出: false

 输入: "([)]"
 输出: false

 输入: "{[]}"
 输出: true
*/
func test_20() {
    let solution = _20_有效的括号()
    print(solution.isValid("()"))
    print(solution.isValid("()[]{}"))
    print(solution.isValid("(]"))
    print(solution.isValid("([)]"))
    print(solution.isValid("{[]}"))
}
