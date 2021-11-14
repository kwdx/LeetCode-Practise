/*
 * @lc app=leetcode.cn id=520 lang=swift
 *
 * [520] 检测大写字母
 */

import Darwin

// @lc code=start
class Solution {
    func detectCapitalUse(_ word: String) -> Bool {
        if word.count < 2 {
            return true
        }
        let isLowercases = word.unicodeScalars.map { Character($0).isLowercase }
        if isLowercases[0] && !isLowercases[1] {
            return false
        }
        for i in 2..<isLowercases.count {
            if isLowercases[i] != isLowercases[1] {
                return false
            }
        }
        return true
    }
}
// @lc code=end

func main() {
    var word: String
    var res: Bool
    
    /**
     输入：word = "USA"
     输出：true
     */
    word = "USA"
    res = true
    assert(res == Solution().detectCapitalUse(word))
    
    /**
     输入：word = "FlaG"
     输出：false
     */
    word = "FlaG"
    res = false
    assert(res == Solution().detectCapitalUse(word))
}
