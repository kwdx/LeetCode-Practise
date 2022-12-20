/*
 * @lc app=leetcode.cn id=1832 lang=swift
 *
 * [1832] 判断句子是否为全字母句
 */

// @lc code=start
class Solution {
    func checkIfPangram(_ sentence: String) -> Bool {
        var mask = 0
        for c in sentence {
            mask |= 1 << Int(c.asciiValue! - 97)
        }
        return mask == 0x3FFFFFF
    }
}
// @lc code=end

func main() {
    var sentence: String
    var res: Bool
    
    /**
     输入：sentence = "thequickbrownfoxjumpsoverthelazydog"
     输出：true
     解释：sentence 包含英语字母表中每个字母至少一次。
     */
    sentence = "thequickbrownfoxjumpsoverthelazydog"
    res = true
    assert(res == Solution().checkIfPangram(sentence))
    
    /**
     输入：sentence = "leetcode"
     输出：false
     */
    sentence = "leetcode"
    res = false
    assert(res == Solution().checkIfPangram(sentence))
}
