//
//  _451_根据字符出现频率排序.swift
//  LeetCode-Swift
//
//  Created by warden on 2020/2/24.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/sort-characters-by-frequency/

import Foundation

class _451_根据字符出现频率排序 {
    func frequencySort(_ s: String) -> String {
        typealias Pair = (Character, Int)
        var m = [Character: Int]()
        for ch in s {
            m[ch] = 1 + (m[ch] ?? 0);
        }
        var pq = [Pair]()
        for item in m {
            pq.append((item.key, item.value))
        }
        pq.sort { (item1, item2) -> Bool in
            return item1.1 > item2.1
        }
        var res = String()
        for item in pq {
            res += String(repeating: item.0, count: item.1)
        }
        return res
    }
}

/**
 示例 1:

 输入:
 "tree"

 输出:
 "eert"

 示例 2:

 输入:
 "cccaaa"

 输出:
 "cccaaa"

 示例 3:

 输入:
 "Aabb"

 输出:
 "bbAa"
 */
func test_451() {
    let solution = _451_根据字符出现频率排序()
    print(solution.frequencySort("tree"))
    print(solution.frequencySort("cccaaa"))
    print(solution.frequencySort("Aabb"))
}
