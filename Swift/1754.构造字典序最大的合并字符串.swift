/*
 * @lc app=leetcode.cn id=1754 lang=swift
 *
 * [1754] 构造字典序最大的合并字符串
 */

// @lc code=start
class Solution {
    func largestMerge(_ word1: String, _ word2: String) -> String {
        var word1 = word1
        var word2 = word2
        var ans = ""
        while !word1.isEmpty || !word2.isEmpty {
            if word1 < word2 {
                ans.append(word2.removeFirst())
            } else {
                ans.append(word1.removeFirst())
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var word1: String
    var word2: String
    var res: String
    
    /**
     输入：word1 = "cabaa", word2 = "bcaaa"
     输出："cbcabaaaaa"
     解释：构造字典序最大的合并字符串，可行的一种方法如下所示：
     - 从 word1 中取第一个字符：merge = "c"，word1 = "abaa"，word2 = "bcaaa"
     - 从 word2 中取第一个字符：merge = "cb"，word1 = "abaa"，word2 = "caaa"
     - 从 word2 中取第一个字符：merge = "cbc"，word1 = "abaa"，word2 = "aaa"
     - 从 word1 中取第一个字符：merge = "cbca"，word1 = "baa"，word2 = "aaa"
     - 从 word1 中取第一个字符：merge = "cbcab"，word1 = "aa"，word2 = "aaa"
     - 将 word1 和 word2 中剩下的 5 个 a 附加到 merge 的末尾。
     */
    word1 = "cabaa"
    word2 = "bcaaa"
    res = "cbcabaaaaa"
//    assert(res == Solution().largestMerge(word1, word2))
    
    /**
     输入：word1 = "abcabc", word2 = "abdcaba"
     输出："abdcabcabcaba"
     */
    word1 = "abcabc"
    word2 = "abdcaba"
    res = "abdcabcabcaba"
    assert(res == Solution().largestMerge(word1, word2))
}
