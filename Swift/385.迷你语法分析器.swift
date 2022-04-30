/*
 * @lc app=leetcode.cn id=385 lang=swift
 *
 * [385] 迷你语法分析器
 */

import Foundation

class NestedInteger {
    private var value = 0
    
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    public func isInteger() -> Bool { false }
    
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    public func getInteger() -> Int { 0 }
    
    // Set this NestedInteger to hold a single integer.
    public func setInteger(value: Int) {}
    
    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    public func add(elem: NestedInteger) {}
    
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    public func getList() -> [NestedInteger] { [] }
}

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public func isInteger() -> Bool
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     public func getInteger() -> Int
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public func setInteger(value: Int)
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public func add(elem: NestedInteger)
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     public func getList() -> [NestedInteger]
 * }
 */

class Solution {
    func deserialize(_ s: String) -> NestedInteger {
        let chars = Array(s)
        if chars[0] != "[" {
            let ni = NestedInteger()
            if let val = Int(s) {
                ni.setInteger(value: val)
            }
            return ni
        }
        
        var st: [NestedInteger] = []
        var num = 0
        var negative = false
        
        for i in 0..<s.count {
            let c = chars[i]
            if c == "-" {
                negative = true
            } else if c.isNumber {
                num = num * 10 + (c.wholeNumberValue ?? 0)
            } else if c == "[" {
                st.append(NestedInteger())
            } else if c == "," || c == "]" {
                if chars[i - 1].isNumber {
                    if negative {
                        num = -num
                    }
                    let ni = NestedInteger()
                    ni.setInteger(value: num)
                    st.last?.add(elem: ni)
                }
                num = 0
                negative = false
                if c == "]" && st.count > 1 {
                    let ni = st.removeLast()
                    st.last?.add(elem: ni)
                }
            }
        }
        return st.last!
    }
}
// @lc code=end

func main() {
    
}
