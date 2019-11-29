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
