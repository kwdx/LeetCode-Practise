/*
 * @lc app=leetcode.cn id=667 lang=swift
 *
 * [667] 优美的排列 II
 */

// @lc code=start
class Solution {
    func constructArray(_ n: Int, _ k: Int) -> [Int] {
        var ans = [Int]()
        for i in 1..<(n - k) {
            ans.append(i)
        }
        var i = n - k, j = n
        while i <= j {
            ans.append(i)
            if i != j {
                ans.append(j)
            }
            i += 1
            j -= 1
        }
        return ans
    }
}
// @lc code=end

func main() {
    var n: Int
    var k: Int
    var res: [Int]
    
    /**
     输入：n = 3, k = 1
     输出：[1, 2, 3]
     解释：[1, 2, 3] 包含 3 个范围在 1-3 的不同整数，并且 [1, 1] 中有且仅有 1 个不同整数：1
     */
    n = 3
    k = 1
    res = [1,2,3]
    assert(res == Solution().constructArray(n, k))
    
    /**
     输入：n = 3, k = 2
     输出：[1, 3, 2]
     解释：[1, 3, 2] 包含 3 个范围在 1-3 的不同整数，并且 [2, 1] 中有且仅有 2 个不同整数：1 和 2
     */
    n = 3
    k = 2
    res = [1,3,2]
    assert(res == Solution().constructArray(n, k))
}
