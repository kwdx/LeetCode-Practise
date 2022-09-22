/*
 * @lc app=leetcode.cn id=854 lang=swift
 *
 * [854] 相似度为 K 的字符串
 */

// @lc code=start
class Solution {
    func kSimilarity(_ s1: String, _ s2: String) -> Int {
        let s1 = Array(s1)
        let s2 = Array(s2)
        let n = s1.count
        var q = [(s1, 0)]
        var visit: Set<[String.Element]> = []
        var step = 0
        while true {
            let sz = q.count
            for _ in 0..<sz {
                var (cur, pos) = q.removeFirst()
                if cur == s2 {
                    return step
                }
                while pos < n && cur[pos] == s2[pos] {
                    pos += 1
                }
                var j = pos + 1
                while j < n {
                    if (cur[j] != s2[j] && cur[j] == s2[pos]) {
                        cur.swapAt(pos, j)
                        if !visit.contains(cur) {
                            visit.insert(cur)
                            q.append((cur, pos + 1))
                        }
                        cur.swapAt(pos, j)
                    }
                    j += 1
                }
            }
            step += 1
        }
    }
}
// @lc code=end

func main() {
    var s1: String
    var s2: String
    var res: Int
    
    /**
     输入：s1 = "ab", s2 = "ba"
     输出：1
     */
    s1 = "ab"
    s2 = "ba"
    res = 1
    assert(res == Solution().kSimilarity(s1, s2))
    
    /**
     输入：s1 = "abc", s2 = "bca"
     输出：2
     */
    s1 = "abc"
    s2 = "bca"
    res = 2
    assert(res == Solution().kSimilarity(s1, s2))
}
