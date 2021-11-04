/*
 * @lc app=leetcode.cn id=367 lang=swift
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
    func isPerfectSquare(_ num: Int) -> Bool {
        var left = 0
        var right = num
        while left <= right {
            let mid = left + ((right - left) >> 1)
            let square = mid * mid
            if square < num {
                left = mid + 1
            } else if square > num {
                right = mid - 1
            } else {
                return true
            }
        }
        return false
    }
}
// @lc code=end


func main() {
    var num: Int
    var res: Bool

    /**
     输入：num = 16
     输出：true
     */
    num = 16
    res = true
    assert(res == Solution().isPerfectSquare(num))

    /**
     输入：num = 14
     输出：false
     */
    num = 14
    res = false
    assert(res == Solution().isPerfectSquare(num))

    /**
     输入：num = 2000105819
     输出：false
     */
    num = 2000105819
    res = false
    assert(res == Solution().isPerfectSquare(num))
}
