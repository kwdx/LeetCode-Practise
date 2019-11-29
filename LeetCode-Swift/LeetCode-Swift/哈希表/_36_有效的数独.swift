//
//  _36_有效的数独.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/valid-sudoku/

import Foundation

class _36_有效的数独 {
    func isValidSudoku(_ board: [[Character]]) -> Bool {
        var rows = [Int16](repeating: 0, count: 9)
        var cols = [Int16](repeating: 0, count: 9)
        var boxes = [Int16](repeating: 0, count: 9)
        
        let ascii_1: Character = "1"
        let ascii_value = ascii_1.asciiValue!
        for row in 0..<9 {
            for col in 0..<9 {
                let ch = board[row][col]
                if ch == "." {
                    continue
                }
                let num: Int16 = 1 << (ch.asciiValue! - ascii_value)
                if (rows[row] & num) != 0 {
                    return false
                }
                if (cols[col] & num) != 0 {
                    return false
                }
                let box = (row / 3) * 3 + col / 3
                if (boxes[box] & num) != 0 {
                    return false
                }
                
                rows[row] |= num
                cols[col] |= num
                boxes[box] |= num
            }
        }
        
        return true
    }
}
