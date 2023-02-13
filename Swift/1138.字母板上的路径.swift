/*
 * @lc app=leetcode.cn id=1138 lang=swift
 *
 * [1138] 字母板上的路径
 */

// @lc code=start
class Solution {
    func alphabetBoardPath(_ target: String) -> String {
        var cx = 0, cy = 0
        var ans = ""
        for c in target {
            let nx = Int(c.asciiValue! - 97) / 5
            let ny = Int(c.asciiValue! - 97) % 5
            if nx < cx {
                ans.append(.init(repeating: "U", count: cx - nx))
            }
            if ny < cy {
                ans.append(.init(repeating: "L", count: cy - ny))
            }
            if nx > cx {
                ans.append(.init(repeating: "D", count: nx - cx))
            }
            if ny > cy {
                ans.append(.init(repeating: "R", count: ny - cy))
            }
            ans.append("!")
            cx = nx
            cy = ny
        }
        return ans
    }
}
// @lc code=end

func main() {
    var target: String
    var res: String
    
    /**
     输入：target = "leet"
     输出："DDR!UURRR!!DDD!"
     */
    target = "leet"
    res = "DDR!UURRR!!DDD!"
    assert(res == Solution().alphabetBoardPath(target))
    
    /**
     输入：target = "code"
     输出："RR!DDRR!UUL!R!"
     */
    target = "code"
    res = "RR!DDRR!UUL!R!"
    assert(res == Solution().alphabetBoardPath(target))
}
