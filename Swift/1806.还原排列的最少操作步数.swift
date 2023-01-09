/*
 * @lc app=leetcode.cn id=1806 lang=swift
 *
 * [1806] 还原排列的最少操作步数
 */

// @lc code=start
class Solution {
    func reinitializePermutation(_ n: Int) -> Int {
        if n == 2 {
            return 1
        }
        var ans = 1, p = 2
        while p != 1 {
            ans += 1
            p = p * 2 % (n - 1)
        }
        return ans
    }
}
// @lc code=end

func main() {
    var n: Int
    var res: Int
    
    /**
     输入：n = 2
     输出：1
     解释：最初，perm = [0,1]
     第 1 步操作后，perm = [0,1]
     所以，仅需执行 1 步操作
     */
    n = 2
    res = 1
    assert(res == Solution().reinitializePermutation(n))
    
    /**
     输入：n = 4
     输出：2
     解释：最初，perm = [0,1,2,3]
     第 1 步操作后，perm = [0,2,1,3]
     第 2 步操作后，perm = [0,1,2,3]
     所以，仅需执行 2 步操作
     */
    n = 4
    res = 2
    assert(res == Solution().reinitializePermutation(n))
    
    /**
     输入：n = 6
     输出：4
     */
    n = 6
    res = 4
    assert(res == Solution().reinitializePermutation(n))
}
