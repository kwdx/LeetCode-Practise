/*
 * @lc app=leetcode.cn id=788 lang=swift
 *
 * [788] 旋转数字
 */

// @lc code=start
class Solution {
    func rotatedDigits(_ n: Int) -> Int {
        var ans = 0
        for i in 1...n {
            var isOK = false
            var isBreak = false
            var x = i
            while x != 0 {
                let t = x % 10
                x /= 10
                if t == 2 || t == 5 || t == 6 || t == 9 {
                    isOK = true
                } else if t != 0 && t != 1 && t != 8 {
                    isBreak = true
                    break
                }
            }
            if isOK && !isBreak {
                ans += 1
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var n: Int
    var res: Int
    
    /**
     输入: 10
     输出: 4
     解释:
     在[1, 10]中有四个好数： 2, 5, 6, 9。
     注意 1 和 10 不是好数, 因为他们在旋转之后不变。
     */
    n = 10
    res = 4
    assert(res == Solution().rotatedDigits(n))
}
