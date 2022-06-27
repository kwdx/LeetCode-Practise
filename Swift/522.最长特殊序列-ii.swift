/*
 * @lc app=leetcode.cn id=522 lang=swift
 *
 * [522] 最长特殊序列 II
 */

// @lc code=start
class Solution {
    func findLUSlength(_ strs: [String]) -> Int {
        let isSubStr: ([Character], [Character]) -> Bool = { a, b in
            var idx1 = 0, idx2 = 0
            while idx1 < a.count && idx2 < b.count {
                if a[idx1] == b[idx2] {
                    idx1 += 1
                }
                idx2 += 1
            }
            return idx1 == a.count
        }
        var ans = -1
        for i in 0..<strs.count {
            if strs[i].count <= ans {
                continue
            }
            var isOK = true
            for j in 0..<strs.count {
                if i != j && isSubStr(Array(strs[i]), Array(strs[j])) {
                    isOK = false
                    break
                }
            }
            if isOK {
                ans = max(ans, strs[i].count)
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var strs: [String]
    var res: Int
    
    strs = ["aabbcc", "aabbcc","cb","abc"]
    res = 2
    assert(res == Solution().findLUSlength(strs))
    
    /**
     输入: strs = ["aba","cdc","eae"]
     输出: 3
     */
    strs = ["aba","cdc","eae"]
    res = 3
    assert(res == Solution().findLUSlength(strs))
    
    /**
     输入: strs = ["aaa","aaa","aa"]
     输出: -1
     */
    strs = ["aaa","aaa","aa"]
    res = -1
    assert(res == Solution().findLUSlength(strs))
}
