/*
 * @lc app=leetcode.cn id=1592 lang=swift
 *
 * [1592] 重新排列单词间的空格
 */

// @lc code=start
class Solution {
    func reorderSpaces(_ text: String) -> String {        
        let words = text.components(separatedBy: " ").filter { !$0.isEmpty }
        let spaces = text.count - words.reduce(0, { $0 + $1.count })
        
        let cnt: Int
        if words.count == 1 {
            cnt = spaces
        } else {
            cnt = spaces / (words.count - 1)
        }
        var ans = words.joined(separator: String(repeating: " ", count: cnt))
        ans += String(repeating: " ", count: text.count - ans.count)
        return ans
    }
}
// @lc code=end

func main() {
    var text: String
    var res: String
    
    /**
     输入：text = "  this   is  a sentence "
     输出："this   is   a   sentence"
     解释：总共有 9 个空格和 4 个单词。可以将 9 个空格平均分配到相邻单词之间，相邻单词间空格数为：9 / (4-1) = 3 个。
     */
    text = "  this   is  a sentence "
    res = "this   is   a   sentence"
    assert(res == Solution().reorderSpaces(text))
    
    /**
     输入：text = " practice   makes   perfect"
     输出："practice   makes   perfect "
     解释：总共有 7 个空格和 3 个单词。7 / (3-1) = 3 个空格加上 1 个多余的空格。多余的空格需要放在字符串的末尾。
     */
    text = " practice   makes   perfect"
    res = "practice   makes   perfect "
    assert(res == Solution().reorderSpaces(text))
    
    /**
     输入：text = "hello   world"
     输出："hello   world"
     */
    text = "hello   world"
    res = "hello   world"
    assert(res == Solution().reorderSpaces(text))
    
    /**
     输入：text = "  walks  udp package   into  bar a"
     输出："walks  udp  package  into  bar  a "

     */
    text = "  walks  udp package   into  bar a"
    res = "walks  udp  package  into  bar  a "
    assert(res == Solution().reorderSpaces(text))
    
    /**
     输入：text = "a"
     输出："a"
     */
    text = "a"
    res = "a"
    assert(res == Solution().reorderSpaces(text))
}
