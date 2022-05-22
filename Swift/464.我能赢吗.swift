/*
 * @lc app=leetcode.cn id=464 lang=swift
 *
 * [464] 我能赢吗
 */

// @lc code=start
class Solution {
    private var n = 0
    private var t = 0
    var f: [Int] = .init(repeating: 0, count: 1 << 20)
    
    func dfs(_ state: Int, _ tot: Int) -> Int {
        if f[state] != 0 {
            return f[state]
        }
        for i in 0..<n {
            if ((state >> i) & 1) == 1 {
                continue
            }
            if tot + i + 1 >= t {
                f[state] = 1
                return 1
            }
            if dfs(state | (1 << i), tot + i + 1) == -1 {
                f[state] = 1
                return 1
            }
        }
        f[state] = -1
        return -1
    }

    func canIWin(_ maxChoosableInteger: Int, _ desiredTotal: Int) -> Bool {
        n = maxChoosableInteger
        t = desiredTotal
        if n * (n + 1) / 2 < t {
            return false
        }
        if t == 0 {
            return true
        }
        return dfs(0, 0) == 1
    }
}
// @lc code=end

func main() {
    var maxChoosableInteger: Int
    var desiredTotal: Int
    var res: Bool
    
    /**
     输入：maxChoosableInteger = 10, desiredTotal = 11
     输出：false
     解释：
     无论第一个玩家选择哪个整数，他都会失败。
     第一个玩家可以选择从 1 到 10 的整数。
     如果第一个玩家选择 1，那么第二个玩家只能选择从 2 到 10 的整数。
     第二个玩家可以通过选择整数 10（那么累积和为 11 >= desiredTotal），从而取得胜利.
     同样地，第一个玩家选择任意其他整数，第二个玩家都会赢。
     */
    maxChoosableInteger = 10
    desiredTotal = 11
    res = false
    assert(res == Solution().canIWin(maxChoosableInteger, desiredTotal))
    
    /**
     输入：maxChoosableInteger = 10, desiredTotal = 0
     输出：true
     */
    maxChoosableInteger = 10
    desiredTotal = 0
    res = true
    assert(res == Solution().canIWin(maxChoosableInteger, desiredTotal))

    /**
     输入：maxChoosableInteger = 10, desiredTotal = 1
     输出：true
     */
    maxChoosableInteger = 10
    desiredTotal = 1
    res = true
    assert(res == Solution().canIWin(maxChoosableInteger, desiredTotal))
}
