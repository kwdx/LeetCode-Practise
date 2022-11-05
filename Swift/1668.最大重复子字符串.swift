/*
 * @lc app=leetcode.cn id=1668 lang=swift
 *
 * [1668] 最大重复子字符串
 */

// @lc code=start
class Solution {
    func maxRepeating(_ sequence: String, _ word: String) -> Int {
        let sequence = Array(sequence)
        let word = Array(word)
        let n = sequence.count
        let m = word.count
        if n < m {
            return 0
        }
        var fail = [Int](repeating: -1, count: m)
        for i in 1..<m {
            var j = fail[i - 1]
            while j != -1 && word[j + 1] != word[i] {
                j = fail[j]
            }
            if word[j + 1] == word[i] {
                fail[i] = j + 1
            }
        }
        
        var f = [Int](repeating: 0, count: n)
        var j = -1
        for i in 0..<n {
            while j != -1 && word[j + 1] != sequence[i] {
                j = fail[j]
            }
            if word[j + 1] == sequence[i] {
                j += 1
                if j == m - 1 {
                    f[i] = (i >= m ? f[i - m] : 0) + 1
                    j = fail[j]
                }
            }
        }
        return f.max()!
    }
}
// @lc code=end

func main() {
    var sequence: String
    var word: String
    var res: Int
    
    /**
     "aaabaaaabaaabaaaabaaaabaaaabaaaaba"
     "aaaba"
     */
    sequence = "aaabaaaabaaabaaaabaaaabaaaabaaaaba"
    word = "aaaba"
    res = 5
    assert(res == Solution().maxRepeating(sequence, word))

    /**
     输入：sequence = "ababc", word = "ab"
     输出：2
     解释："abab" 是 "ababc" 的子字符串。
     */
    sequence = "ababc"
    word = "ab"
    res = 2
    assert(res == Solution().maxRepeating(sequence, word))
    
    /**
     输入：sequence = "ababc", word = "ba"
     输出：1
     解释："ba" 是 "ababc" 的子字符串，但 "baba" 不是 "ababc" 的子字符串。
     */
    sequence = "ababc"
    word = "ba"
    res = 1
    assert(res == Solution().maxRepeating(sequence, word))
    
    /**
     输入：sequence = "ababc", word = "ac"
     输出：0
     解释："ac" 不是 "ababc" 的子字符串。
     */
    sequence = "ababc"
    word = "ac"
    res = 0
    assert(res == Solution().maxRepeating(sequence, word))
}
