/*
 * @lc app=leetcode.cn id=150 lang=swift
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
    func evalRPN(_ tokens: [String]) -> Int {
        var stack = [Int]()
        for token in tokens {
            switch token {
            case "+":
                stack.append(stack.popLast()! + stack.popLast()!)
            case "-":
                stack.append(-stack.popLast()! + stack.popLast()!)
            case "*":
                stack.append(stack.popLast()! * stack.popLast()!)
            case "/":
                let right = stack.popLast()!
                let left = stack.popLast()!
                stack.append(left / right)
            default:
                stack.append(Int(token)!)
            }
        }
        return stack.popLast()!
    }
}
// @lc code=end

func main() {
    var tokens: [String]
    var res: Int
    
    /**
     输入：tokens = ["2","1","+","3","*"]
     输出：9
     解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
     */
    tokens = ["2","1","+","3","*"]
    res = 9
    assert(res == Solution().evalRPN(tokens))
    
    /**
     输入：tokens = ["4","13","5","/","+"]
     输出：6
     解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
     */
    tokens = ["4","13","5","/","+"]
    res = 6
    assert(res == Solution().evalRPN(tokens))
    
    /**
     输入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
     输出：22
     解释：
     该算式转化为常见的中缀算术表达式为：
       ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
     = ((10 * (6 / (12 * -11))) + 17) + 5
     = ((10 * (6 / -132)) + 17) + 5
     = ((10 * 0) + 17) + 5
     = (0 + 17) + 5
     = 17 + 5
     = 22
     */
    tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
    res = 22
    assert(res == Solution().evalRPN(tokens))
}
