/*
 * @lc app=leetcode.cn id=1189 lang=swift
 *
 * [1189] “气球” 的最大数量
 */

// @lc code=start
class Solution {
    func maxNumberOfBalloons(_ text: String) -> Int {
        var cnts: [Int] = .init(repeating: 0, count: 5)
        text.forEach {
            switch $0 {
            case "b": cnts[0] += 1
            case "a": cnts[1] += 1
            case "l": cnts[2] += 1
            case "o": cnts[3] += 1
            case "n": cnts[4] += 1
            default: break
            }
        }
        cnts[2] >>= 1
        cnts[3] >>= 1
        return cnts.min()!
    }
}
// @lc code=end

func main() {
    var text: String
    var res: Int
    
    /**
     输入：text = "nlaebolko"
     输出：1
     */
    text = "nlaebolko"
    res = 1
    assert(res == Solution().maxNumberOfBalloons(text))
    
    /**
     输入：text = "loonbalxballpoon"
     输出：2
     */
    text = "loonbalxballpoon"
    res = 2
    assert(res == Solution().maxNumberOfBalloons(text))
    
    /**
     输入：text = "leetcode"
     输出：0
     */
    text = "leetcode"
    res = 0
    assert(res == Solution().maxNumberOfBalloons(text))
}
