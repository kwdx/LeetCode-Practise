/*
 * @lc app=leetcode.cn id=793 lang=swift
 *
 * [793] 阶乘函数后 K 个零
 */

// @lc code=start
class Solution {
    func preimageSizeFZF(_ k: Int) -> Int {
        func zeta(_ x: Int) -> Int {
            var ans = 0
            var x = x
            while x > 0 {
                ans += x / 5
                x /= 5
            }
            return ans
        }
        
        func help(_ k: Int) -> Int {
            var r = 5 * k
            var l = 0
            while l <= r {
                let mid = (l + r) >> 1
                if zeta(mid) < k {
                    l = mid + 1
                } else {
                    r = mid - 1
                }
            }
            return r + 1
        }
        return help(k + 1) - help(k)
    }
}
// @lc code=end

func main() {
    var k: Int
    var res: Int
    
    /**
     输入：k = 0
     输出：5
     解释：0!, 1!, 2!, 3!, 和 4! 均符合 k = 0 的条件。
     */
    k = 0
    res = 5
    assert(res == Solution().preimageSizeFZF(k))
    
    /**
     输入：k = 5
     输出：0
     解释：没有匹配到这样的 x!，符合 k = 5 的条件。
     */
    k = 5
    res = 0
    assert(res == Solution().preimageSizeFZF(k))

    /**
     输入: k = 3
     输出: 5
     */
    k = 3
    res = 5
    assert(res == Solution().preimageSizeFZF(k))
}
