/*
 * @lc app=leetcode.cn id=2028 lang=swift
 *
 * [2028] 找出缺失的观测数据
 */

// @lc code=start
class Solution {
    func missingRolls(_ rolls: [Int], _ mean: Int, _ n: Int) -> [Int] {
        let m = rolls.count
        let total = (m + n) * mean
        let t = total - rolls.reduce(0, +)
        if t < n || t > n * 6 {
            return []
        }
        var ans: [Int] = .init(repeating: t / n, count: n)
        if t / n * n < t {
            var d = t - (t / n * n)
            var idx = 0
            while d > 0 {
                ans[idx] += 1
                idx += 1
                d -= 1
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var rolls: [Int]
    var mean: Int
    var n: Int
    var res: [Int]
    
    /**
     输入：rolls = [3,2,4,3], mean = 4, n = 2
     输出：[6,6]
     解释：所有 n + m 次投掷的平均值是 (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4 。
     */
    rolls = [3,2,4,3]
    mean = 4
    n = 2
    res = [6,6]
    assert(res == Solution().missingRolls(rolls, mean, n))
    
    /**
     输入：rolls = [1,5,6], mean = 3, n = 4
     输出：[2,3,2,2]
     解释：所有 n + m 次投掷的平均值是 (1 + 5 + 6 + 2 + 3 + 2 + 2) / 7 = 3 。
     */
    rolls = [1,5,6]
    mean = 3
    n = 4
    res = [3,2,2,2]
    assert(res == Solution().missingRolls(rolls, mean, n))
    
    /**
     输入：rolls = [1,2,3,4], mean = 6, n = 4
     输出：[]
     解释：无论丢失的 4 次数据是什么，平均值都不可能是 6 。
     */
    rolls = [1,2,3,4]
    mean = 6
    n = 4
    res = []
    assert(res == Solution().missingRolls(rolls, mean, n))
    
    /**
     输入：rolls = [1], mean = 3, n = 1
     输出：[5]
     解释：所有 n + m 次投掷的平均值是 (1 + 5) / 2 = 3 。
     */
    rolls = [1]
    mean = 3
    n = 1
    res = [5]
    assert(res == Solution().missingRolls(rolls, mean, n))
}
