/*
 * @lc app=leetcode.cn id=322 lang=swift
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
//    private func getCoins(_ coins: [Int],  dp: inout [Int], n: Int) -> Int {
//        if n < 0 { return -1 }
//        if n == 0 { return 0 }
//        if dp[n] == 0 {
//            var num = -1
//            for coin in coins {
//                let num_ = getCoins(coins, dp: &dp, n: n - coin)
//                if num_ >= 0 {
//                    if num == -1 { num = num_ + 1}
//                    else { num = min(max(num, 0), num_ + 1) }
//                }
//            }
//            dp[n] = num
//        }
//        return dp[n]
//    }
//    
//    func coinChange1(_ coins: [Int], _ amount: Int) -> Int {
//        if amount == 0 { return 0 }
//        var dp: [Int] = .init(repeating: 0, count: amount + 1)
//        
//        for coin in coins {
//            if (coin <= amount) { dp[coin] = 1 }
//        }
//        
//        return getCoins(coins, dp: &dp, n: amount)
//    }
    
    func coinChange(_ coins: [Int], _ amount: Int) -> Int {
        var dp: [Int] = .init(repeating: Int.max, count: amount + 1)
        dp[0] = 0
        
        for coin in coins {
            var i = 0
            while (i + coin) <= amount {
                if dp[i] != Int.max {
                    dp[i + coin] = min(dp[i] + 1, dp[i + coin])
                }
                i += 1
            }
        }
        
        return dp[amount] == Int.max ? -1 : dp[amount]
    }
}
// @lc code=end

func main() {
    var coins: [Int]
    var amount: Int
    var res: Int
    
    /**
     输入：coins = [1, 2, 5], amount = 11
     输出：3
     解释：11 = 5 + 5 + 1
     */
    coins = [1,2,5]
    amount = 11
    res = 3
    assert(res == Solution().coinChange(coins, amount))
    
    /**
     输入：coins = [2], amount = 3
     输出：-1
     */
    coins = [2]
    amount = 3
    res = -1
    assert(res == Solution().coinChange(coins, amount))
    
    /**
     输入：coins = [1], amount = 0
     输出：0
     */
    coins = [1]
    amount = 0
    res = 0
    assert(res == Solution().coinChange(coins, amount))
    
    /**
     输入：coins = [1], amount = 1
     输出：1
     */
    coins = [1]
    amount = 1
    res = 1
    assert(res == Solution().coinChange(coins, amount))
    
    /**
     输入：coins = [1], amount = 2
     输出：2
     */
    coins = [1]
    amount = 2
    res = 2
    assert(res == Solution().coinChange(coins, amount))
}
