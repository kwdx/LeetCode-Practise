/*
 * @lc app=leetcode.cn id=1816 lang=swift
 *
 * [1816] 截断句子
 */

// @lc code=start
class Solution {
    func truncateSentence(_ s: String, _ k: Int) -> String {
        s.split(separator: " ").prefix(k).joined(separator: " ")
    }
    
    func truncateSentence1(_ s: String, _ k: Int) -> String {
        var end = 0
        var cnt = 0
        for i in 1...s.count {
            if i == s.count || s[s.index(s.startIndex, offsetBy: i)] == " " {
                cnt += 1
                if cnt == k {
                    end = i
                    break
                }
            }
        }
        return String(s[s.startIndex..<s.index(s.startIndex, offsetBy: end)])
    }
}
// @lc code=end

func main() {
    var s: String
    var k: Int
    var res: String
    
    /**
     输入：s = "Hello how are you Contestant", k = 4
     输出："Hello how are you"
     解释：
     s 中的单词为 ["Hello", "how" "are", "you", "Contestant"]
     前 4 个单词为 ["Hello", "how", "are", "you"]
     因此，应当返回 "Hello how are you"
     */
    s = "Hello how are you Contestant"
    k = 4
    res = "Hello how are you"
    assert(res == Solution().truncateSentence(s, k))
    
    /**
     输入：s = "What is the solution to this problem", k = 4
     输出："What is the solution"
     解释：
     s 中的单词为 ["What", "is" "the", "solution", "to", "this", "problem"]
     前 4 个单词为 ["What", "is", "the", "solution"]
     因此，应当返回 "What is the solution"
     */
    s = "What is the solution to this problem"
    k = 4
    res = "What is the solution"
    assert(res == Solution().truncateSentence(s, k))
    
    /**
     输入：s = "chopper is not a tanuki", k = 5
     输出："chopper is not a tanuki"
     */
    s = "chopper is not a tanuki"
    k = 5
    res = "chopper is not a tanuki"
    assert(res == Solution().truncateSentence(s, k))
}
