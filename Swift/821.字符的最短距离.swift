/*
 * @lc app=leetcode.cn id=821 lang=swift
 *
 * [821] 字符的最短距离
 */

// @lc code=start
class Solution {
    func shortestToChar(_ s: String, _ c: Character) -> [Int] {
        let n =  s.count;
        let chars = Array(s)
        var ans: [Int] = .init(repeating: n + 1, count: s.count)
        var i = 0, j = -1
        while i < n {
            if chars[i] == c {
                j = i
            }
            if j != -1 {
                ans[i] = i - j
            }
            i += 1
        }
        i = n - 1
        j = -1
        while i >= 0 {
            if chars[i] == c {
                j = i
            }
            if j != -1 {
                ans[i] = min(ans[i], j - i)
            }
            i -= 1
        }
        return ans
    }
}
// @lc code=end

func main() {
    var s: String
    var c: Character
    var res: [Int]
    
    /**
     输入：s = "loveleetcode", c = "e"
     输出：[3,2,1,0,1,0,0,1,2,2,1,0]
     解释：字符 'e' 出现在下标 3、5、6 和 11 处（下标从 0 开始计数）。
     距下标 0 最近的 'e' 出现在下标 3 ，所以距离为 abs(0 - 3) = 3 。
     距下标 1 最近的 'e' 出现在下标 3 ，所以距离为 abs(1 - 3) = 2 。
     对于下标 4 ，出现在下标 3 和下标 5 处的 'e' 都离它最近，但距离是一样的 abs(4 - 3) == abs(4 - 5) = 1 。
     距下标 8 最近的 'e' 出现在下标 6 ，所以距离为 abs(8 - 6) = 2 。
     */
    s = "loveleetcode"
    c = "e"
    res = [3,2,1,0,1,0,0,1,2,2,1,0]
    assert(res == Solution().shortestToChar(s, c))
    
    /**
     输入：s = "aaab", c = "b"
     输出：[3,2,1,0]
     */
    s = "aaab"
    c = "b"
    res = [3,2,1,0]
    assert(res == Solution().shortestToChar(s, c))
}
