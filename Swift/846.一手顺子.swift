/*
 * @lc app=leetcode.cn id=846 lang=swift
 *
 * [846] 一手顺子
 */

// @lc code=start
class Solution {
    func isNStraightHand(_ hand: [Int], _ groupSize: Int) -> Bool {
        var pq = PriorityQueue<Int>()
        var maps: [Int: Int] = [:]
        for num in hand {
            pq.push(num)
            maps[num] = 1 + (maps[num] ?? 0)
        }
        while let val = pq.pop() {
            if maps[val]! == 0 {
                continue
            }
            maps[val] = maps[val]! - 1
            for i in 1..<groupSize {
                if let cnt = maps[val - i], cnt > 0 {
                    maps[val - i] = maps[val - i]! - 1
                } else {
                    return false
                }
            }
        }
        return true
    }
}
// @lc code=end

func main() {
    var hand: [Int]
    var groupSize: Int
    var res: Bool
    
    /**
     输入：hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
     输出：true
     解释：Alice 手中的牌可以被重新排列为 [1,2,3]，[2,3,4]，[6,7,8]。
     */
    hand = [1,2,3,6,2,3,4,7,8]
    groupSize = 3
    res = true
    assert(res == Solution().isNStraightHand(hand, groupSize))
    
    /**
     输入：hand = [1,2,3,4,5], groupSize = 4
     输出：false
     解释：Alice 手中的牌无法被重新排列成几个大小为 4 的组。
     */
    hand = [1,2,3,4,5]
    groupSize = 4
    res = false
    assert(res == Solution().isNStraightHand(hand, groupSize))
}
