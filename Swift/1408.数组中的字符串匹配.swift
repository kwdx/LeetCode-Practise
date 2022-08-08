/*
 * @lc app=leetcode.cn id=1408 lang=swift
 *
 * [1408] 数组中的字符串匹配
 */

// @lc code=start
class Solution {
    func stringMatching(_ words: [String]) -> [String] {
        var ans: [String] = []
        for i in 0..<words.count {
            for j in 0..<words.count {
                if i != j && words[j].contains(words[i]) {
                    ans.append(words[i])
                    break
                }
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var words: [String]
    var res: [String]
    
    /**
     输入：words = ["mass","as","hero","superhero"]
     输出：["as","hero"]
     解释："as" 是 "mass" 的子字符串，"hero" 是 "superhero" 的子字符串。
     ["hero","as"] 也是有效的答案。
     */
    words = ["mass","as","hero","superhero"]
    res = ["as","hero"]
    assert(res == Solution().stringMatching(words))
    
    /**
     输入：words = ["leetcode","et","code"]
     输出：["et","code"]
     解释："et" 和 "code" 都是 "leetcode" 的子字符串。
     */
    words = ["leetcode","et","code"]
    res = ["et","code"]
    assert(res == Solution().stringMatching(words))
    
    /**
     输入：words = ["blue","green","bu"]
     输出：[]
     */
    words = ["blue","green","bu"]
    res = []
    assert(res == Solution().stringMatching(words))
}
