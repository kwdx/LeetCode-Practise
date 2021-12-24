/*
 * @lc app=leetcode.cn id=686 lang=swift
 *
 * [686] 重复叠加字符串匹配
 */

// @lc code=start
class Solution {
    func repeatedStringMatch(_ a: String, _ b: String) -> Int {
        var ab: String = ""
        var ans = 0
        while ab.count < b.count {
            ans += 1
            ab += a
        }
        ab += a
        let idx = KMP(ab.map { $0 }, b.map { $0 })
        if idx == -1 {
            return -1
        }
        return idx + b.count > a.count * ans ? ans + 1 : ans
    }
    
    private func KMP(_ s: [Character], _ p: [Character]) -> Int {
        let nexts = getNext(p)
        var j = 0
        for i in 0..<s.count {
            if j >= p.count {
                return i - j
            }
            while (j > 0 && s[i] != p[j]) {
                j = nexts[j - 1]
            }
            if s[i] == p[j] {
                j += 1
            }
        }
        return -1
    }
    
    private func getNext(_ p: [Character]) -> [Int] {
        var nexts: [Int] = .init(repeating: 0, count: p.count)
        var j = 0
        for i in 1..<p.count {
            while j > 0 && p[j] != p[i] {
                j = nexts[j - 1]
            }
            if p[i] == p[j] {
                j += 1
                nexts[i] = j
            }
        }
        return nexts
    }
}
// @lc code=end

func main() {
    var a: String, b: String
    var res: Int
    
    /**
     输入：a = "abcd", b = "cdabcdab"
     输出：3
     解释：a 重复叠加三遍后为 "abcdabcdabcd", 此时 b 是其子串。
     */
    a = "abcd"
    b = "cdabcdab"
    res = 3
    assert(res == Solution().repeatedStringMatch(a, b))
    
    /**
     输入：a = "a", b = "aa"
     输出：2
     */
    a = "a"
    b = "aa"
    res = 2
    assert(res == Solution().repeatedStringMatch(a, b))
    
    /**
     输入：a = "a", b = "a"
     输出：1
     */
    a = "a"
    b = "a"
    res = 1
    assert(res == Solution().repeatedStringMatch(a, b))
    
    /**
     输入：a = "abc", b = "wxyz"
     输出：-1
     */
    a = "abc"
    b = "wxyz"
    res = -1
    assert(res == Solution().repeatedStringMatch(a, b))
}
