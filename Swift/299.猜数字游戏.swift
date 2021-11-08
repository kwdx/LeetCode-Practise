/*
 * @lc app=leetcode.cn id=299 lang=swift
 *
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution {
    func getHint(_ secret: String, _ guess: String) -> String {
        let n = secret.count
        var S = [Int](repeating: 0, count: 10)
        var G = [Int](repeating: 0, count: 10)
        
        var A = 0
        var B = 0
        
        let sAsciies = secret.unicodeScalars.map { Int($0.value - 48) }
        let gAsciies = guess.unicodeScalars.map { Int($0.value - 48) }
        
        for i in 0..<n {
            if sAsciies[i] == gAsciies[i] {
                A += 1
            } else {
                S[sAsciies[i]] = 1 + S[sAsciies[i]]
                G[gAsciies[i]] = 1 + G[gAsciies[i]]
            }
        }
        
        for i in 0..<10 {
            B += min(S[i], G[i])
        }
        return "\(A)A\(B)B"
    }
}
// @lc code=end

func main() {
    var secret: String
    var guess: String
    var res: String
    
    /**
     输入: secret = "1807", guess = "7810"
     输出: "1A3B"
     解释: 数字和位置都对（公牛）用 '|' 连接，数字猜对位置不对（奶牛）的采用斜体加粗标识。
     "1807"
       |
     "7810"
     */
    secret = "1807"
    guess = "7810"
    res = "1A3B"
    assert(res == Solution().getHint(secret, guess))
    
    /**
     输入: secret = "1123", guess = "0111"
     输出: "1A1B"
     解释: 数字和位置都对（公牛）用 '|' 连接，数字猜对位置不对（奶牛）的采用斜体加粗标识。
     "1123"        "1123"
       |      or     |
     "0111"        "0111"
     注意，两个不匹配的 1 中，只有一个会算作奶牛（数字猜对位置不对）。通过重新排列非公牛数字，其中仅有一个 1 可以成为公牛数字。
     */
    secret = "1123"
    guess = "0111"
    res = "1A1B"
    assert(res == Solution().getHint(secret, guess))
    
    /**
     输入：secret = "1", guess = "0"
     输出："0A0B"
     */
    secret = "1"
    guess = "0"
    res = "0A0B"
    assert(res == Solution().getHint(secret, guess))
    
    /**
     输入：secret = "1", guess = "1"
     输出："1A0B"
     */
    secret = "1"
    guess = "1"
    res = "1A0B"
    assert(res == Solution().getHint(secret, guess))
    
    /**
     输入：secret = "1122", guess = "1222"
     输出："3A0B"
     */
    secret = "1122"
    guess = "1222"
    res = "3A0B"
    assert(res == Solution().getHint(secret, guess))
}
