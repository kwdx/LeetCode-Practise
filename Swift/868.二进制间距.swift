/*
 * @lc app=leetcode.cn id=868 lang=swift
 *
 * [868] 二进制间距
 */

// @lc code=start
class Solution {
    func binaryGap(_ n: Int) -> Int {
        var ans = 0
        var i = 0
        var pre = -1
        var num = n
        while num > 0 {
            if (num & 0x1) == 1 {
                if pre != -1 {
                    ans = max(ans, i - pre)
                }
                pre = i
            }
            num >>= 1
            i += 1
        }
        return ans
    }
}
// @lc code=end

func main() {
    var n: Int
    var res: Int
    
    /**
     输入：n = 22
     输出：2
     解释：22 的二进制是 "10110" 。
     在 22 的二进制表示中，有三个 1，组成两对相邻的 1 。
     第一对相邻的 1 中，两个 1 之间的距离为 2 。
     第二对相邻的 1 中，两个 1 之间的距离为 1 。
     答案取两个距离之中最大的，也就是 2 。
     */
    n = 22
    res = 2
    assert(res == Solution().binaryGap(n))
    
    /**
     输入：n = 8
     输出：0
     解释：8 的二进制是 "1000" 。
     在 8 的二进制表示中没有相邻的两个 1，所以返回 0 。
     */
    n = 8
    res = 0
    assert(res == Solution().binaryGap(n))
    
    /**
     输入：n = 5
     输出：2
     解释：5 的二进制是 "101" 。
     */
    n = 5
    res = 2
    assert(res == Solution().binaryGap(n))
}
