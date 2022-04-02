/*
 * @lc app=leetcode.cn id=420 lang=swift
 *
 * [420] 强密码检验器
 */

// @lc code=start
class Solution {
    func strongPasswordChecker(_ password: String) -> Int {
        let chars = Array(password)
        var A = 0, B = 0, C = 0
        for c in chars {
            switch c {
            case "a"..."z":
                A = 1
            case "A"..."Z":
                B = 1
            default:
                C = 1
            }
        }
        let n = password.count
        let m = A + B + C

        if n < 6 {
            return max(6 - n, 3 - m)
        } else if n <= 20 {
            var ans = 0
            var i = 0
            while i < n {
                var j = i
                while j < n && chars[j] == chars[i] {
                    j += 1
                }
                if j - i >= 3 {
                    ans += (j - i) / 3
                }
                i = j
            }
            return max(ans, 3 - m)
        } else {
            var ans = 0
            var cnts = [Int](repeating: 0, count: 3)
            var i = 0
            while i < n {
                var j = i
                while j < n && chars[j] == chars[i] {
                    j += 1
                }
                if j - i >= 3 {
                    ans += (j - i) / 3
                    cnts[(j - i) % 3] += 1
                }
                i = j
            }
            var base = n - 20, cur = base;
            for i in 0..<3 {
                if i == 2 {
                    cnts[i] = ans;
                }
                if cnts[i] != 0 && cur > 0 {
                    let t = min(cnts[i] * (i + 1), cur)
                    cur -= t
                    ans -= t / (i + 1)
                }
            }
            return base + max(ans, 3 - m)
        }
    }
}
// @lc code=end

func main() {
    var password: String
    var res: Int
    
    /**
     输入：password = "a"
     输出：5
     */
    password = "a"
    res = 5
    assert(res == Solution().strongPasswordChecker(password))
    
    /**
     输入：password = "aA1"
     输出：3
     */
    password = "aA1"
    res = 3
    assert(res == Solution().strongPasswordChecker(password))
    
    /**
     输入：password = "1337C0d3"
     输出：0
     */
    password = "1337C0d3"
    res = 0
    assert(res == Solution().strongPasswordChecker(password))
    
    password = "bbaaaaaaaaaaaaaaacccccc"
    res = 8
    assert(res == Solution().strongPasswordChecker(password))
}
