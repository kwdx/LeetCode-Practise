/*
 * @lc app=leetcode.cn id=2299 lang=swift
 *
 * [2299] 强密码检验器 II
 */

// @lc code=start
class Solution {
    func strongPasswordCheckerII(_ password: String) -> Bool {
        guard password.count >= 8 else {
            return false
        }
        let password = Array(password)
        var kind = 0
        for i in 0..<password.count {
            if (i != 0 && password[i] == password[i - 1]) {
                return false
            }
            switch password[i] {
            case "a"..."z":
                kind |= 1 << 0
            case "A"..."Z":
                kind |= 1 << 1
            case "0"..."9":
                kind |= 1 << 2
            default:
                kind |= 1 << 3
            }
        }
        return (kind & 0xF) == 0xF
    }
}
// @lc code=end

func main() {
    var password: String
    var res: Bool
    
    /**
     输入：password = "IloveLe3tcode!"
     输出：true
     解释：密码满足所有的要求，所以我们返回 true 。
     */
    password = "IloveLe3tcode!"
    res = true
    assert(res == Solution().strongPasswordCheckerII(password))
    
    /**
     输入：password = "Me+You--IsMyDream"
     输出：false
     解释：密码不包含数字，且包含 2 个连续相同的字符。所以我们返回 false 。
     */
    password = "Me+You--IsMyDream"
    res = false
    assert(res == Solution().strongPasswordCheckerII(password))
    
    /**
     输入：password = "1aB!"
     输出：false
     解释：密码不符合长度要求。所以我们返回 false 。
     */
    password = "1aB!"
    res = false
    assert(res == Solution().strongPasswordCheckerII(password))
}
