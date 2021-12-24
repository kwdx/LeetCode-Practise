/*
 * @lc app=leetcode.cn id=1154 lang=swift
 *
 * [1154] 一年中的第几天
 */

import Foundation

// @lc code=start
class Solution {
    private let days = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    
    func dayOfYear(_ date: String) -> Int {
        let arr = date.split(separator: "-").map { Int($0)! }
        let (year, month, day) = (arr[0], arr[1], arr[2])
        
        let ans = days[0..<month].reduce(0, +) + day
        if month > 2 {
            if year % 400 == 0 || (year % 100 != 0 && year % 4 == 0) {
                return ans + 1
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var date: String
    var res: Int
    
    /**
     输入：date = "2019-01-09"
     输出：9
     */
    date = "2019-01-09"
    res = 9
    assert(res == Solution().dayOfYear(date))
    
    /**
     输入：date = "2019-02-10"
     输出：41
     */
    date = "2019-02-10"
    res = 41
    assert(res == Solution().dayOfYear(date))
    
    /**
     输入：date = "2003-03-01"
     输出：60
     */
    date = "2003-03-01"
    res = 60
    assert(res == Solution().dayOfYear(date))
    
    /**
     输入：date = "2004-03-01"
     输出：61
     */
    date = "2004-03-01"
    res = 61
    assert(res == Solution().dayOfYear(date))
}
