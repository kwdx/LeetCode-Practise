/*
 * @lc app=leetcode.cn id=1106 lang=swift
 *
 * [1106] 解析布尔表达式
 */

// @lc code=start
class Solution {
    func parseBoolExpr(_ expression: String) -> Bool {
        let expression = Array(expression)
        var opSt = [Character]()
        var numSt = [Character]()
        for c in expression {
            switch c {
            case ",":
                continue
            case "&", "|", "!":
                opSt.append(c)
            case "t", "f":
                numSt.append(c)
            case "(":
                numSt.append("-")
            default:
                let op = opSt.removeLast()
                var cur: Character = " "
                while !numSt.isEmpty && numSt.last != "-" {
                    let top = numSt.removeLast()
                    cur = cur == " " ? top : calc(top, cur, op)
                }
                if op == "!" {
                    cur = cur == "t" ? "f" : "t"
                }
                numSt.removeLast()
                numSt.append(cur)
            }
        }
        return numSt.last == "t"
    }
    
    func calc(_ a: Character, _ b: Character, _ op: Character) -> Character {
        let x = a == "t"
        let y = b == "t"
        let ans = op == "|" ? (x || y) : (x && y)
        return ans ? "t" : "f"
    }
}
// @lc code=end

func main() {
    var expression: String
    var res: Bool
    
    /**
     输入：expression = "!(f)"
     输出：true
     */
    expression = "!(f)"
    res = true
    assert(res == Solution().parseBoolExpr(expression))
    
    /**
     输入：expression = "|(f,t)"
     输出：true
     */
    expression = "|(f,t)"
    res = true
    assert(res == Solution().parseBoolExpr(expression))
    
    /**
     输入：expression = "&(t,f)"
     输出：false
     */
    expression = "&(t,f)"
    res = false
    assert(res == Solution().parseBoolExpr(expression))
    
    /**
     输入：expression = "|(&(t,f,t),!(t))"
     输出：false
     */
    expression = "|(&(t,f,t),!(t))"
    res = false
    assert(res == Solution().parseBoolExpr(expression))
}
