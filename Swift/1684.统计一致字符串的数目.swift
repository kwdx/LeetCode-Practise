/*
 * @lc app=leetcode.cn id=1684 lang=swift
 *
 * [1684] 统计一致字符串的数目
 */

// @lc code=start
class Solution {
    func countConsistentStrings(_ allowed: String, _ words: [String]) -> Int {
        var ans = 0
        let chars = Set(allowed)
        for word in words {
            var flag = true
            for c in word {
                if !chars.contains(c) {
                    flag = false
                    break;
                }
            }
            if flag {
                ans += 1
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var allowed: String
    var words: [String]
    var res: Int
    
    /**
     输入：allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
     输出：2
     解释：字符串 "aaab" 和 "baa" 都是一致字符串，因为它们只包含字符 'a' 和 'b' 。
     */
    allowed = "ab"
    words = ["ad","bd","aaab","baa","badab"]
    res = 2
    assert(res == Solution().countConsistentStrings(allowed, words))
    
    /**
     输入：allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
     输出：7
     解释：所有字符串都是一致的。
     */
    allowed = "abc"
    words = ["a","b","c","ab","ac","bc","abc"]
    res = 7
    assert(res == Solution().countConsistentStrings(allowed, words))
    
    /**
     输入：allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
     输出：4
     解释：字符串 "cc"，"acd"，"ac" 和 "d" 是一致字符串。
     */
    allowed = "cad"
    words = ["cc","acd","b","ba","bac","bad","ac","d"]
    res = 4
    assert(res == Solution().countConsistentStrings(allowed, words))
}
