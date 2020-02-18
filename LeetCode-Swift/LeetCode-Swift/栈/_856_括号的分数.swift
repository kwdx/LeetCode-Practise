//
//  _856_括号的分数.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/12/3.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/score-of-parentheses/

import Foundation

class _856_括号的分数 {
    func scoreOfParentheses(_ S: String) -> Int {
        var scoreArr = [Int]()
        var parentheseArr = [Int]()
        for s in S {
            if s == "(" {
                scoreArr.append(0)
                parentheseArr.append(scoreArr.count)
            } else {
                let leftPos = parentheseArr.removeLast()
                if leftPos == scoreArr.count {
                    scoreArr.removeLast()
                    scoreArr.append(1)
                } else {
                    var val = 0
                    while scoreArr.count >= leftPos {
                        val += scoreArr.removeLast()
                    }
                    scoreArr.append(val * 2)
                }
            }
        }
        return scoreArr.reduce(0) { $0 + $1 }
    }
}

/**
 () 得 1 分。
 AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。
 (A) 得 2 * A 分，其中 A 是平衡括号字符串。

 输入： "()"
 输出： 1

 输入： "(())"
 输出： 2

 输入： "()()"
 输出： 2

 输入： "(()(()))"
 输出： 6
*/
func test_856() {
    let solution = _856_括号的分数()
    print(solution.scoreOfParentheses("()"))
    print(solution.scoreOfParentheses("(())"))
    print(solution.scoreOfParentheses("()()"))
    print(solution.scoreOfParentheses("(()(()))"))
}
