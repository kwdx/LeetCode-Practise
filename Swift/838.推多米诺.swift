/*
 * @lc app=leetcode.cn id=838 lang=swift
 *
 * [838] 推多米诺
 */

// @lc code=start
class Solution {
    
    // 超时了
    func pushDominoes(_ dominoes: String) -> String {
        var chars = Array(dominoes)
        let n = dominoes.count
        var g = [Int](repeating: 0, count: n)
        var d: [(Int, Int, Int)] = []
        for i in 0..<n {
            if chars[i] == "." {
                continue
            }
            let dire = chars[i] == "L" ? -1 : 1
            d.append((i, 1, dire))
            g[i] = 1
        }
        // BFS遍历
        while !d.isEmpty {
            let (loc, time, dire) = d.removeFirst();
            let next = loc + dire
            if chars[loc] == "." || next < 0 || next >= n {
                continue
            }
            if g[next] == 0 {   // 首次受力
                d.append((next, time + 1, dire))
                g[next] = time + 1
                chars[next] = dire == -1 ? "L" : "R"
            } else if (g[next] == time + 1) {   // 多次受力
                chars[next] = "."
            }
        }
        return String(chars)
    }
}
// @lc code=end

func main() {
    var dominoes: String
    var res: String
    
    /**
     输入：dominoes = "RR.L"
     输出："RR.L"
     解释：第一张多米诺骨牌没有给第二张施加额外的力。
     */
    dominoes = "RR.L"
    res = "RR.L"
    assert(res == Solution().pushDominoes(dominoes))
    
    /**
     输入：dominoes = ".L.R...LR..L.."
     输出："LL.RR.LLRRLL.."
     */
    dominoes = ".L.R...LR..L.."
    res = "LL.RR.LLRRLL.."
    assert(res == Solution().pushDominoes(dominoes))
}
