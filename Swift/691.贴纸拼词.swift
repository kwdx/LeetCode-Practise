/*
 * @lc app=leetcode.cn id=691 lang=swift
 *
 * [691] 贴纸拼词
 */

// @lc code=start
class Solution {
    let N = 20
    let M = 1 << 20
    let INF = 50
    lazy var f = [Int](repeating: -1, count: M)
    var ss: [String] = []
    var t: String = ""
    
    func dfs(_ state: Int) -> Int {
        let n = t.count
        if state == (1 << n) - 1 {
            return 0
        }
        if f[state] != -1 {
            return f[state]
        }
        var ans = INF
        for s in ss {
            var nstate = state
            for char in s {
                for i in 0..<n {
                    if t[t.index(t.startIndex, offsetBy: i)] == char && ((nstate >> i) & 1) == 0 {
                        nstate |= (1 << i)
                        break
                    }
                }
            }
            if nstate != state {
                ans = min(ans, dfs(nstate) + 1)
            }
        }
        f[state] = ans
        return ans
    }
    
    func minStickers(_ stickers: [String], _ target: String) -> Int {
        self.ss = stickers
        self.t = target
        let ans = dfs(0)
        return ans == INF ? -1 : ans
    }
}
// @lc code=end

func main() {
    var stickers: [String]
    var target: String
    var res: Int
    
    /**
     输入： stickers = ["with","example","science"], target = "thehat"
     输出：3
     解释：
     我们可以使用 2 个 "with" 贴纸，和 1 个 "example" 贴纸。
     把贴纸上的字母剪下来并重新排列后，就可以形成目标 “thehat“ 了。
     此外，这是形成目标字符串所需的最小贴纸数量。
     */
    stickers = ["with","example","science"]
    target = "thehat"
    res = 3
    assert(res == Solution().minStickers(stickers, target))
    
    /**
     输入：stickers = ["notice","possible"], target = "basicbasic"
     输出：-1
     解释：我们不能通过剪切给定贴纸的字母来形成目标“basicbasic”。
     */
    stickers = ["notice","possible"]
    target = "basicbasic"
    res = -1
    assert(res == Solution().minStickers(stickers, target))
}
