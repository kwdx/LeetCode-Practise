/*
 * @lc app=leetcode.cn id=2000 lang=swift
 *
 * [2000] 反转单词前缀
 */

// @lc code=start
class Solution {
    func reversePrefix(_ word: String, _ ch: Character) -> String {
        if let idx = word.firstIndex(of: ch) {
            return String(word[...idx].reversed()) + String(word[word.index(after: idx)...])
        }
        return
    }
}
// @lc code=end

func main() {
    var word: String
    var ch: Character
    var res: String
    
    /**
     输入：word = "abcdefd", ch = "d"
     输出："dcbaefd"
     解释："d" 第一次出现在下标 3 。
     反转从下标 0 到下标 3（含下标 3）的这段字符，结果字符串是 "dcbaefd" 。
     */
    word = "abcdefd"
    ch = "d"
    res = "dcbaefd"
    assert(res == Solution().reversePrefix(word, ch))
    
    /**
     输入：word = "xyxzxe", ch = "z"
     输出："zxyxxe"
     解释："z" 第一次也是唯一一次出现是在下标 3 。
     反转从下标 0 到下标 3（含下标 3）的这段字符，结果字符串是 "zxyxxe" 。
     */
    word = "xyxzxe"
    ch = "z"
    res = "zxyxxe"
    assert(res == Solution().reversePrefix(word, ch))
    
    /**
     输入：word = "abcd", ch = "z"
     输出："abcd"
     解释："z" 不存在于 word 中。
     无需执行反转操作，结果字符串是 "abcd" 。
     */
    word = "abcd"
    ch = "z"
    res = "abcd"
    assert(res == Solution().reversePrefix(word, ch))
}
