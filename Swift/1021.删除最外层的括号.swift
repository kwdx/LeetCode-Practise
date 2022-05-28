/*
 * @lc app=leetcode.cn id=1021 lang=swift
 *
 * [1021] 删除最外层的括号
 */

// @lc code=start
class Solution {
    func removeOuterParentheses(_ s: String) -> String {
        var ans: String = ""
        var st: [Character] = []
        for char in s {
            if char == ")" {
                st.removeLast()
            }
            if !st.isEmpty {
                ans.append(char)
            }
            if char == "(" {
                st.append(char)
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var s: String
    var res: String
    
    /**
     输入：s = "(()())(())"
     输出："()()()"
     解释：
     输入字符串为 "(()())(())"，原语化分解得到 "(()())" + "(())"，
     删除每个部分中的最外层括号后得到 "()()" + "()" = "()()()"。
     */
    s = "(()())(())"
    res = "()()()"
    assert(res == Solution().removeOuterParentheses(s))
    
    /**
     输入：s = "(()())(())(()(()))"
     输出："()()()()(())"
     解释：
     输入字符串为 "(()())(())(()(()))"，原语化分解得到 "(()())" + "(())" + "(()(()))"，
     删除每个部分中的最外层括号后得到 "()()" + "()" + "()(())" = "()()()()(())"。
     */
    s = "(()())(())(()(()))"
    res = "()()()()(())"
    assert(res == Solution().removeOuterParentheses(s))
    
    /**
     输入：s = "()()"
     输出：""
     解释：
     输入字符串为 "()()"，原语化分解得到 "()" + "()"，
     删除每个部分中的最外层括号后得到 "" + "" = ""。
     */
    s = "()()"
    res = ""
    assert(res == Solution().removeOuterParentheses(s))
}
