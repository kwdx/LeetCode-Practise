/*
 * @lc app=leetcode.cn id=1823 lang=swift
 *
 * [1823] 找出游戏的获胜者
 */

// @lc code=start
class Solution {
    func findTheWinner(_ n: Int, _ k: Int) -> Int {
        guard n > 1 else { return n }
        let ans = (findTheWinner(n - 1, k) + k) % n
        return ans == 0 ? n : ans
    }
}
// @lc code=end

func main() {
    var n: Int
    var k: Int
    var res: Int
    
    /**'
     输入：n = 5, k = 2
     输出：3
     解释：游戏运行步骤如下：
     1) 从小伙伴 1 开始。
     2) 顺时针数 2 名小伙伴，也就是小伙伴 1 和 2 。
     3) 小伙伴 2 离开圈子。下一次从小伙伴 3 开始。
     4) 顺时针数 2 名小伙伴，也就是小伙伴 3 和 4 。
     5) 小伙伴 4 离开圈子。下一次从小伙伴 5 开始。
     6) 顺时针数 2 名小伙伴，也就是小伙伴 5 和 1 。
     7) 小伙伴 1 离开圈子。下一次从小伙伴 3 开始。
     8) 顺时针数 2 名小伙伴，也就是小伙伴 3 和 5 。
     9) 小伙伴 5 离开圈子。只剩下小伙伴 3 。所以小伙伴 3 是游戏的获胜者。
     */
    n = 5
    k = 2
    res = 3
    assert(res == Solution().findTheWinner(n, k))

    /**
     输入：n = 6, k = 5
     输出：1
     解释：小伙伴离开圈子的顺序：5、4、6、2、3 。小伙伴 1 是游戏的获胜者。
     */
    n = 6
    k = 5
    res = 1
    assert(res == Solution().findTheWinner(n, k))
}
