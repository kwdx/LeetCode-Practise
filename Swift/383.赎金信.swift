/*
 * @lc app=leetcode.cn id=383 lang=swift
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
    func canConstruct(_ ransomNote: String, _ magazine: String) -> Bool {
        guard magazine.count >= ransomNote.count else {
            return false
        }
        var characters: [Character: Int] = [:]
        for ch in magazine {
            characters[ch] = 1 + (characters[ch] ?? 0)
        }
        for ch in ransomNote {
            if let cnt = characters[ch], cnt > 0 {
                characters[ch] = cnt - 1
            } else {
                return false
            }
        }
        return true
    }
}
// @lc code=end

func main() {
    var ransomNote: String
    var magazine: String
    var res: Bool
    
    /**
     输入：ransomNote = "a", magazine = "b"
     输出：false
     */
    ransomNote = "a"
    magazine = "b"
    res = false
    assert(res == Solution().canConstruct(ransomNote, magazine))
    
    /**
     输入：ransomNote = "aa", magazine = "ab"
     输出：false
     */
    ransomNote = "aa"
    magazine = "ab"
    res = false
    assert(res == Solution().canConstruct(ransomNote, magazine))
    
    /**
     输入：ransomNote = "aa", magazine = "aab"
     输出：true
     */
    ransomNote = "aa"
    magazine = "aab"
    res = true
    assert(res == Solution().canConstruct(ransomNote, magazine))
}
