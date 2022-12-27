/*
 * @lc app=leetcode.cn id=1739 lang=swift
 *
 * [1739] 放置盒子
 */

// @lc code=start
class Solution {
    func minimumBoxes(_ n: Int) -> Int {
        var cur = 1
        var n = n
        var i = 1, j = 1
        while n > cur {
            n -= cur
            i += 1
            cur += i
        }
        cur = 1
        while n > cur {
            n -= cur
            j += 1
            cur += 1
        }
        return (i - 1) * i / 2 + j
    }
}
// @lc code=end

func main() {
    var n: Int
    var res: Int
    
    /**
     输入：n = 3
     输出：3
     解释：上图是 3 个盒子的摆放位置。
     这些盒子放在房间的一角，对应左侧位置。
     */
    n = 3
    res = 3
    assert(res == Solution().minimumBoxes(n))
    
    /**
     输入：n = 4
     输出：3
     解释：上图是 3 个盒子的摆放位置。
     这些盒子放在房间的一角，对应左侧位置。
     */
    n = 4
    res = 3
    assert(res == Solution().minimumBoxes(n))
    
    /**
     输入：n = 10
     输出：6
     解释：上图是 10 个盒子的摆放位置。
     这些盒子放在房间的一角，对应后方位置。
     */
    n = 10
    res = 6
    assert(res == Solution().minimumBoxes(n))
}
