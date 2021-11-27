/*
 * @lc app=leetcode.cn id=859 lang=swift
 *
 * [859] 亲密字符串
 */

// @lc code=start
class Solution {
    func buddyStrings(_ s: String, _ goal: String) -> Bool {
        guard s.count == goal.count, s.count > 1 else {
            return false
        }
        let n = s.count
        if s == goal {
            var count: [Character: Int] = [:]
            for c in s {
                count[c] = (count[c] ?? 0) + 1
                if (count[c] ?? 0) > 1 {
                    return true
                }
            }
            return false
        } else {
            var left = -1
            var right = -1
            let sCharacters = s.map { $0 }
            let gCharacters = goal.map { $0 }
            for i in 0..<n {
                if sCharacters[i] != gCharacters[i] {
                    if left == -1 {
                        left = i
                    } else if right == -1 {
                        right = i
                    } else {
                        return false
                    }
                }
            }
            return right != -1 && sCharacters[left] == gCharacters[right] && sCharacters[right] == gCharacters[left]
        }
    }
}
// @lc code=end

func main() {
    var s: String
    var goal: String
    var res: Bool
    
    /**
     输入：s = "ab", goal = "ba"
     输出：true
     解释：你可以交换 s[0] = 'a' 和 s[1] = 'b' 生成 "ba"，此时 s 和 goal 相等。
     */
    s = "ab"
    goal = "ba"
    res = true
    assert(res == Solution().buddyStrings(s, goal))
    
    /**
     输入：s = "ab", goal = "ab"
     输出：false
     解释：你只能交换 s[0] = 'a' 和 s[1] = 'b' 生成 "ba"，此时 s 和 goal 不相等。
     */
    s = "ab"
    goal = "ab"
    res = false
    assert(res == Solution().buddyStrings(s, goal))
    
    /**
     输入：s = "aa", goal = "aa"
     输出：true
     解释：你可以交换 s[0] = 'a' 和 s[1] = 'a' 生成 "aa"，此时 s 和 goal 相等。
     */
    s = "aa"
    goal = "aa"
    res = true
    assert(res == Solution().buddyStrings(s, goal))
    
    /**
     输入：s = "aaaaaaabc", goal = "aaaaaaacb"
     输出：true
     */
    s = "aaaaaaabc"
    goal = "aaaaaaacb"
    res = true
    assert(res == Solution().buddyStrings(s, goal))
}
