/*
 * @lc app=leetcode.cn id=856 lang=swift
 *
 * [856] 括号的分数
 */

// @lc code=start
class Solution {
    func scoreOfParentheses(_ s: String) -> Int {
        var scoreArr = [Int]()
        var parentheseArr = [Int]()
        for c in s {
            if c == "(" {
                scoreArr.append(0)
                parentheseArr.append(scoreArr.count)
            } else {
                let leftPos = parentheseArr.removeLast()
                if leftPos == scoreArr.count {
                    scoreArr.removeLast()
                    scoreArr.append(1)
                } else {
                    var val = 0
                    while scoreArr.count >= leftPos {
                        val += scoreArr.removeLast()
                    }
                    scoreArr.append(val * 2)
                }
            }
        }
        return scoreArr.reduce(0) { $0 + $1 }
    }
}
// @lc code=end

func main() {
    var s: String
    var res: Int
    
    /**
     输入： "()"
     输出： 1
     */
    s = "()"
    res = 1
    assert(res == Solution().scoreOfParentheses(s))
    
    /**
     输入： "(())"
     输出： 2
     */
    s = "(())"
    res = 2
    assert(res == Solution().scoreOfParentheses(s))
    
    /**
     输入： "()()"
     输出： 2
     */
    s = "()()"
    res = 2
    assert(res == Solution().scoreOfParentheses(s))
    
    /**
     输入： "(()(()))"
     输出： 6
     */
    s = "(()(()))"
    res = 6
    assert(res == Solution().scoreOfParentheses(s))
}
