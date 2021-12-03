/*
 * @lc app=leetcode.cn id=400 lang=swift
 *
 * [400] 第 N 位数字
 */

import CoreGraphics
import Foundation

// @lc code=start
class Solution {
    func findNthDigit(_ n: Int) -> Int {
        // 定位数字为几位数
        var d = 1
        var count = 9
        var n_ = n
        while n_ > d * count {
            n_ -= d * count
            d += 1
            count *= 10
        }
        
        let index = n_ - 1
        let start = Int(pow(10, Double(d - 1)))
        let num = start + index / d
        let digitIndex = index % d
        let digit = (num / Int(pow(10, Double(d - digitIndex - 1)))) % 10
        return digit
    }
}
// @lc code=end

func main() {
    var n: Int
    var res: Int
    
    /**
     输入：n = 3
     输出：3
     */
    n = 3
    res = 3
    assert(res == Solution().findNthDigit(n))
    
    /**
     输入：n = 11
     输出：0
     解释：第 11 位数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是 0 ，它是 10 的一部分。
     */
    n = 11
    res = 0
    assert(res == Solution().findNthDigit(n))
}
