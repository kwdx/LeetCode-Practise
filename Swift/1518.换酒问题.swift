/*
 * @lc app=leetcode.cn id=1518 lang=swift
 *
 * [1518] 换酒问题
 */

// @lc code=start
class Solution {
    func numWaterBottles(_ numBottles: Int, _ numExchange: Int) -> Int {
        var n = numBottles
        var ans = numBottles
        while n >= numExchange {
            let add = n / numExchange
            ans += add
            n = n % numExchange + add
        }
        return ans
    }
}
// @lc code=end

func main() {
    var numBottles: Int
    var numExchange: Int
    var res: Int
    
    /**
     输入：numBottles = 9, numExchange = 3
     输出：13
     解释：你可以用 3 个空酒瓶兑换 1 瓶酒。
     所以最多能喝到 9 + 3 + 1 = 13 瓶酒。
     */
    numBottles = 9
    numExchange = 3
    res = 13
    assert(res == Solution().numWaterBottles(numBottles, numExchange))
    
    /**
     输入：numBottles = 15, numExchange = 4
     输出：19
     解释：你可以用 4 个空酒瓶兑换 1 瓶酒。
     所以最多能喝到 15 + 3 + 1 = 19 瓶酒。
     */
    numBottles = 15
    numExchange = 4
    res = 19
    assert(res == Solution().numWaterBottles(numBottles, numExchange))
    
    /**
     输入：numBottles = 5, numExchange = 5
     输出：6
     */
    numBottles = 5
    numExchange = 5
    res = 6
    assert(res == Solution().numWaterBottles(numBottles, numExchange))
    
    /**
     输入：numBottles = 2, numExchange = 3
     输出：2
     */
    numBottles = 2
    numExchange = 3
    res = 2
    assert(res == Solution().numWaterBottles(numBottles, numExchange))
}
