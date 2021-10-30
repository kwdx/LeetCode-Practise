/*
 * @lc app=leetcode.cn id=20 lang=swift
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
    func isValid(_ s: String) -> Bool {
        var stack = [String]()
        for ch in s {
            let chstr = String(ch)
            switch chstr {
            case "(", "[", "{":
                stack.append(chstr)
            case ")":
                if stack.popLast() != "(" {
                    return false
                }
            case "]":
                if stack.popLast() != "[" {
                    return false
                }
            case "}":
                if stack.popLast() != "{" {
                    return false
                }
            default: break
            }
        }
        return stack.isEmpty
    }
}
// @lc code=end

func main() {
    var s: String
    var res: Bool
    
    /**
     输入：s = "()"
     输出：true
     */
    s = "()"
    res = true
    assert(res == Solution().isValid(s))
    
    /**
     输入：s = "()[]{}"
     输出：true
     */
    s = "()[]{}"
    res = true
    assert(res == Solution().isValid(s))
    
    /**
     输入：s = "(]"
     输出：false
     */
    s = "(]"
    res = false
    assert(res == Solution().isValid(s))
    
    /**
     输入：s = "([)]"
     输出：false
     */
    s = "([)]"
    res = false
    assert(res == Solution().isValid(s))
    
    /**
     输入：s = "{[]}"
     输出：true
     */
    s = "{[]}"
    res = true
    assert(res == Solution().isValid(s))
}
