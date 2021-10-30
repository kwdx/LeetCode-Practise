/*
 * @lc app=leetcode.cn id=224 lang=swift
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
    func calculate(_ s: String) -> Int {
        var score = 0
        var num = 0
        var opFlag = true
        var opStack = [opFlag]
        for ch in s {
            switch ch {
            case "+", "-":
                score += opFlag ? num : -num
                opFlag = opStack.last! == (ch == "+")
                num = 0
            case "(":
                opStack.append(opFlag)
//                opFlag = true
            case ")":
                opStack.removeLast()
//                opFlag = opStack.last!
            case " ":
                break
            default:
                num = num * 10 + ch.wholeNumberValue!
            }
        }
        return score + ((opStack.last! == opFlag) ? num : -num)
    }
    
    func calculate1(_ s: String) -> Int {
        var score = [Int]()
        var parenthese = [Int]()
        var num = 0
        var opFlag = true
        for ch in s {
            if ch.isNumber {
                num = num * 10 + Int(String(ch))!
            } else {
                if num != 0 {
                    if opFlag {
                        score.append(num)
                    } else {
                        score.append(-num)
                    }
                    num = 0
                    opFlag = true
                }
                switch ch {
                case Character("+"):
                    opFlag = true
                case Character("-"):
                    opFlag = false
                case Character("("):
                    score.append(opFlag ? 0 : -1)
                    parenthese.append(score.count)
                    opFlag = true
                case Character(")"):
                    let leftPos = parenthese.removeLast()
                    var val = 0
                    while score.count > leftPos {
                        val += score.removeLast()
                    }
                    if score.removeLast() == -1 {
                        score.append(-val)
                    } else {
                        score.append(val)
                    }
                default:
                    break
                }
            }
        }
        return score.reduce(opFlag ? num : -num) { $0 + $1 }
    }
}
// @lc code=end

func main() {
    var s: String
    var res: Int
    
    /**
     输入：s = "1 + 1"
     输出：2
     */
    s = "1 + 1"
    res = 2
    assert(res == Solution().calculate(s))
    
    /**
     输入：s = " 2-1 + 2 "
     输出：3
     */
    s = " 2-1 + 2 "
    res = 3
    assert(res == Solution().calculate(s))
    
    /**
     输入：s = "(1+(4+5+2)-3)+(6+8)"
     输出：23
     */
    s = "(1+(4+5+2)-3)+(6+8)"
    res = 23
    assert(res == Solution().calculate(s))
}
