/*
 * @lc app=leetcode.cn id=709 lang=swift
 *
 * [709] 转换成小写字母
 */

// @lc code=start
class Solution {
    func toLowerCase(_ s: String) -> String {
        s.lowercased()
    }
}
// @lc code=end

func main() {
    var s: String
    var res: String
    
    /**
     输入：s = "Hello"
     输出："hello"
     */
    s = "Hello"
    res = "hello"
    assert(res == Solution().toLowerCase(s))
    
    /**
     输入：s = "here"
     输出："here"
     */
    s = "here"
    res = "here"
    assert(res == Solution().toLowerCase(s))
    
    /**
     输入：s = "LOVELY"
     输出："lovely"
     */
    s = "LOVELY"
    res = "lovely"
    assert(res == Solution().toLowerCase(s))

}
