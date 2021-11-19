/*
 * @lc app=leetcode.cn id=397 lang=swift
 *
 * [397] 整数替换
 */

// @lc code=start
class Solution {
    private var memo: [Int: Int] = [:]
    func integerReplacement(_ n: Int) -> Int {
        if n == 1 {
            return 0;
        }
        if let val = memo[n] {
            return val
        }
        let val: Int
        if n % 2 == 0 {
            val = 1 + integerReplacement(n / 2)
        } else {
            val = 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1))
        }
        memo[n] = val
        return val
    }
}
// @lc code=end

func main() {
    var n: Int
    var res: Int
    
    /**
     输入：n = 8
     输出：3
     解释：8 -> 4 -> 2 -> 1
     */
    n = 8
    res = 3
    assert(res == Solution().integerReplacement(n))
    
    /**
     输入：n = 7
     输出：4
     解释：7 -> 8 -> 4 -> 2 -> 1
     或 7 -> 6 -> 3 -> 2 -> 1
     */
    n = 7
    res = 4
    assert(res == Solution().integerReplacement(n))
    
    /**
     输入：n = 4
     输出：2
     */
    n = 4
    res = 2
    assert(res == Solution().integerReplacement(n))
}
