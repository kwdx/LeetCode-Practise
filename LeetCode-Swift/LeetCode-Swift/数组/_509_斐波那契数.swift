//
//  _509_斐波那契数.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//

import Foundation

class _509_斐波那契数 {
    func fib(_ N: Int) -> Int {
        if N == 0 {
            return 0
        }
        var f0 = 0
        var f1 = 1
        for _ in 1..<N {
            let tmp = f1
            f1 = f1 + f0
            f0 = tmp
        }
        return f1
    }
}

/**
 输入：2
 输出：1
 解释：F(2) = F(1) + F(0) = 1 + 0 = 1.

 输入：3
 输出：2
 解释：F(3) = F(2) + F(1) = 1 + 1 = 2.

 输入：4
 输出：3
 解释：F(4) = F(3) + F(2) = 2 + 1 = 3.
*/
func test_509() {
    let solution = _509_斐波那契数()
    print(solution.fib(0))
    print(solution.fib(1))
    print(solution.fib(2))
    print(solution.fib(3))
    print(solution.fib(4))
    print(solution.fib(5))
    print(solution.fib(6))
    print(solution.fib(7))
    print(solution.fib(8))
}
