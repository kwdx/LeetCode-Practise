/*
 * @lc app=leetcode.cn id=804 lang=swift
 *
 * [804] 唯一摩尔斯密码词
 */

// @lc code=start
class Solution {
    static let keys: [String] = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
    func uniqueMorseRepresentations(_ words: [String]) -> Int {
        let pwds = words.map { word in
            word.unicodeScalars.map { Self.keys[Int($0.value) - 97] }.joined()
        }
        return Set(pwds).count
    }
}
// @lc code=end

func main() {
    var words: [String]
    var res: Int
    
    /**
     输入: words = ["gin", "zen", "gig", "msg"]
     输出: 2
     解释:
     各单词翻译如下:
     "gin" -> "--...-."
     "zen" -> "--...-."
     "gig" -> "--...--."
     "msg" -> "--...--."

     共有 2 种不同翻译, "--...-." 和 "--...--.".
     */
    words = ["gin", "zen", "gig", "msg"]
    res = 2
    assert(res == Solution().uniqueMorseRepresentations(words))
    
    /**
     输入：words = ["a"]
     输出：1
     */
    words = ["a"]
    res = 1
    assert(res == Solution().uniqueMorseRepresentations(words))
}
