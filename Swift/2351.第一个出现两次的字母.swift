/*
 * @lc app=leetcode.cn id=2351 lang=swift
 *
 * [2351] 第一个出现两次的字母
 */

// @lc code=start
class Solution {
    func repeatedCharacter(_ s: String) -> Character {
        var chars = Set<Character>()
        for c in s {
            if chars.contains(c) {
                return c
            }
            chars.insert(c)
        }
        return s.first!
    }
}
// @lc code=end

func main() {
    var s: String
    var res: Character
    
    /**
     输入：s = "abccbaacz"
     输出："c"
     解释：
     字母 'a' 在下标 0 、5 和 6 处出现。
     字母 'b' 在下标 1 和 4 处出现。
     字母 'c' 在下标 2 、3 和 7 处出现。
     字母 'z' 在下标 8 处出现。
     字母 'c' 是第一个出现两次的字母，因为在所有字母中，'c' 第二次出现的下标是最小的。
     */
    s = "abccbaacz"
    res = "c"
    assert(res == Solution().repeatedCharacter(s))
    
    /**
     输入：s = "abcdd"
     输出："d"
     解释：
     只有字母 'd' 出现两次，所以返回 'd' 。
     */
    s = "abcdd"
    res = "d"
    assert(res == Solution().repeatedCharacter(s))
}
