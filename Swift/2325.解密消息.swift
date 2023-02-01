/*
 * @lc app=leetcode.cn id=2325 lang=swift
 *
 * [2325] 解密消息
 */

// @lc code=start
class Solution {
    let chars: [Character] = ["a","b","c","d","e","f","g","h","i","j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v","w","x","y","z"]
    
    func decodeMessage(_ key: String, _ message: String) -> String {
        var cur = 0
        var rules = [Character: Character]()
        for c in key {
            if c != " " && rules[c] == nil {
                rules[c] = chars[cur]
                cur += 1
            }
        }
        return String(message.map { rules[$0] ?? $0 })
    }
}
// @lc code=end

func main() {
    var key: String
    var message: String
    var res: String
    
    /**
     输入：key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"
     输出："this is a secret"
     解释：对照表如上图所示。
     提取 "the quick brown fox jumps over the lazy dog" 中每个字母的首次出现可以得到替换表。
     */
    key = "the quick brown fox jumps over the lazy dog"
    message = "vkbs bs t suepuv"
    res = "this is a secret"
    assert(res == Solution().decodeMessage(key, message))
    
    /**
     输入：key = "eljuxhpwnyrdgtqkviszcfmabo", message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb"
     输出："the five boxing wizards jump quickly"
     解释：对照表如上图所示。
     提取 "eljuxhpwnyrdgtqkviszcfmabo" 中每个字母的首次出现可以得到替换表。
     */
    key = "eljuxhpwnyrdgtqkviszcfmabo"
    message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb"
    res = "the five boxing wizards jump quickly"
    assert(res == Solution().decodeMessage(key, message))
}
