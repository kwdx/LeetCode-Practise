/*
 * @lc app=leetcode.cn id=1405 lang=swift
 *
 * [1405] 最长快乐字符串
 */

// @lc code=start
class Solution {
    func longestDiverseString(_ a: Int, _ b: Int, _ c: Int) -> String {
        var ans: [Character] = []
        var q = PriorityQueue<(Character, Int)> { $1.1 > $0.1 }
        if a > 0 {
            q.push(("a", a))
        }
        if b > 0 {
            q.push(("b", b))
        }
        if c > 0 {
            q.push(("c", c))
        }
        while var cur = q.pop() {
            let n = ans.count
            if n >= 2 && ans[n - 1] == cur.0 && ans[n - 2] == cur.0 {
                if var next = q.pop() {
                    ans.append(next.0)
                    next.1 -= 1
                    if next.1 > 0 {
                        q.push(next)
                    }
                    q.push(cur)
                } else {
                    break
                }
            } else {
                ans.append(cur.0)
                cur.1 -= 1
                if cur.1 > 0 {
                    q.push(cur)
                }
            }
        }
        
        return .init(ans)
    }
}
// @lc code=end

func main() {
    var a: Int
    var b: Int
    var c: Int
    var res: String
    
    /**
     输入：a = 1, b = 1, c = 7
     输出："ccaccbcc"
     解释："ccbccacc" 也是一种正确答案。
     */
    a = 1
    b = 1
    c = 7
    res = "ccbccacc"
    assert(res == Solution().longestDiverseString(a, b, c))
    
    /**
     输入：a = 2, b = 2, c = 1
     输出："aabbc"
     */
    a = 2
    b = 2
    c = 1
    res = "abcab"// "aabbc"
    assert(res == Solution().longestDiverseString(a, b, c))
    
    /**
     输入：a = 7, b = 1, c = 0
     输出："aabaa"
     解释：这是该测试用例的唯一正确答案。
     */
    a = 7
    b = 1
    c = 0
    res = "aabaa"
    assert(res == Solution().longestDiverseString(a, b, c))
}
