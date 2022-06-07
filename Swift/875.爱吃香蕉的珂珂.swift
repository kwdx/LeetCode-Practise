/*
 * @lc app=leetcode.cn id=875 lang=swift
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution {
    func minEatingSpeed(_ piles: [Int], _ h: Int) -> Int {
        var l = 1
        var r = Int(1e9)
        while l < r {
            let mid = (l + r) >> 1
            if eatTime(piles, mid) <= h {
                r = mid
            } else {
                l = mid + 1
            }
        }
        return l
    }
    
    private func eatTime(_ piles: [Int], _ speed: Int) -> Int {
        var hours = 0
        for i in 0..<piles.count {
            hours += piles[i] / speed
            if piles[i] % speed > 0 {
                hours += 1
            }
        }
        return hours
    }
}
// @lc code=end

func main() {
    var piles: [Int]
    var h: Int
    var res: Int
    
    /**
     输入：piles = [3,6,7,11], h = 8
     输出：4
     */
    piles = [3,6,7,11]
    h = 8
    res = 4
    assert(res == Solution().minEatingSpeed(piles, h))
    
    /**
     输入：piles = [30,11,23,4,20], h = 5
     输出：30
     */
    piles = [30,11,23,4,20]
    h = 5
    res = 30
    assert(res == Solution().minEatingSpeed(piles, h))
    
    /**
     输入：piles = [30,11,23,4,20], h = 6
     输出：23
     */
    piles = [30,11,23,4,20]
    h = 6
    res = 23
    assert(res == Solution().minEatingSpeed(piles, h))
}
