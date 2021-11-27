/*
 * @lc app=leetcode.cn id=458 lang=swift
 *
 * [458] 可怜的小猪
 */

import Darwin

// @lc code=start
class Solution {
    func poorPigs(_ buckets: Int, _ minutesToDie: Int, _ minutesToTest: Int) -> Int {
        let rounds = minutesToTest / minutesToDie + 1
        let pigs = ceil(log(Double(buckets)) / log(Double(rounds)))
        return Int(pigs)
    }
}
// @lc code=end

func main() {
    var buckets: Int
    var minutesToDie: Int
    var minutesToTest: Int
    var res: Int
    
    /**
     输入：buckets = 1000, minutesToDie = 15, minutesToTest = 60
     输出：5
     */
    buckets = 1000
    minutesToDie = 15
    minutesToTest = 60
    res = 5
    assert(res == Solution().poorPigs(buckets, minutesToDie, minutesToTest))
    
    /**
     输入：buckets = 4, minutesToDie = 15, minutesToTest = 15
     输出：2
     */
    buckets = 4
    minutesToDie = 15
    minutesToTest = 15
    res = 2
    assert(res == Solution().poorPigs(buckets, minutesToDie, minutesToTest))
    
    /**
     输入：buckets = 4, minutesToDie = 15, minutesToTest = 30
     输出：2
     */
    buckets = 4
    minutesToDie = 15
    minutesToTest = 30
    res = 2
    assert(res == Solution().poorPigs(buckets, minutesToDie, minutesToTest))
}
