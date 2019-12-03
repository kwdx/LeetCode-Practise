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
