/*
 * @lc app=leetcode.cn id=792 lang=swift
 *
 * [792] 匹配子序列的单词数
 */

// @lc code=start
class Solution {
    func numMatchingSubseq(_ s: String, _ words: [String]) -> Int {
        var pos = [Character: [Int]]()
        for (i, c) in s.enumerated() {
            pos[c] = (pos[c] ?? []) + [i]
        }
        var ans = words.count
        for word in words {
            if word.count > s.count {
                ans -= 1
                continue
            }
            var p = -1
            for c in word {
                if let it = match(p, pos[c] ?? []) {
                   p = it
                } else {
                    ans -= 1
                    break
                }
            }
        }
        return ans
    }
    
    func match(_ value: Int, _ ps: [Int]) -> Int? {
        var left = 0
        var right = ps.count
        while left < right {
            let mid = (left + right) / 2
            if ps[mid] > value {
                right = mid
            } else {
                left = mid + 1
            }
        }
        if right >= ps.count {
            return nil
        }
        return ps[right]
    }
}
// @lc code=end

func main() {
    var s: String
    var words: [String]
    var res: Int
        
    /**
     输入: s = "abcde", words = ["a","bb","acd","ace"]
     输出: 3
     解释: 有三个是 s 的子序列的单词: "a", "acd", "ace"。
     */
    s = "abcde"
    words = ["a","bb","acd","ace"]
    res = 3
    assert(res == Solution().numMatchingSubseq(s, words))
    
    /**
     输入: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
     输出: 2
     */
    s = "dsahjpjauf"
    words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
    res = 2
    assert(res == Solution().numMatchingSubseq(s, words))
}
