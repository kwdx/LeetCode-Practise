/*
 * @lc app=leetcode.cn id=1807 lang=swift
 *
 * [1807] 替换字符串中的括号内容
 */

// @lc code=start
class Solution {
    func evaluate(_ s: String, _ knowledge: [[String]]) -> String {
        var maps = [String: String]()
        for arr in knowledge {
            maps[arr[0]] = arr[1]
        }
        var ans = ""
        var word = ""
        var isKey = false
        for c in s {
            switch c {
            case "(":
                isKey = true
            case ")":
                if let val = maps[word] {
                    ans += val
                } else {
                    ans += "?"
                }
                word = ""
                isKey = false
            default:
                if (isKey) {
                    word.append(c)
                } else {
                    ans.append(c)
                }
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var s: String
    var knowledge: [[String]]
    var res: String

    /**
     输入：s = "(name)is(age)yearsold", knowledge = [["name","bob"],["age","two"]]
     输出："bobistwoyearsold"
     解释：
     键 "name" 对应的值为 "bob" ，所以将 "(name)" 替换为 "bob" 。
     键 "age" 对应的值为 "two" ，所以将 "(age)" 替换为 "two" 。
     */
    s = "(name)is(age)yearsold"
    knowledge = [["name","bob"],["age","two"]]
    res = "bobistwoyearsold"
    assert(res == Solution().evaluate(s, knowledge))
    
    /**
     输入：s = "hi(name)", knowledge = [["a","b"]]
     输出："hi?"
     解释：由于不知道键 "name" 对应的值，所以用 "?" 替换 "(name)" 。
     */
    s = "hi(name)"
    knowledge = [["a","b"]]
    res = "hi?"
    assert(res == Solution().evaluate(s, knowledge))
    
    /**
     输入：s = "(a)(a)(a)aaa", knowledge = [["a","yes"]]
     输出："yesyesyesaaa"
     解释：相同的键在 s 中可能会出现多次。
     键 "a" 对应的值为 "yes" ，所以将所有的 "(a)" 替换为 "yes" 。
     注意，不在括号里的 "a" 不需要被替换。
     */
    s = "(a)(a)(a)aaa"
    knowledge = [["a","yes"]]
    res = "yesyesyesaaa"
    assert(res == Solution().evaluate(s, knowledge))
}
