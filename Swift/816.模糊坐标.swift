/*
 * @lc app=leetcode.cn id=816 lang=swift
 *
 * [816] 模糊坐标
 */

// @lc code=start
class Solution {
    func ambiguousCoordinates(_ s: String) -> [String] {
        var s: [Character] = Array(s)
        let n = s.count - 2
        var ans = [String]()
        s = Array(s[1..<(s.count - 1)])
        for l in 1..<n {
            let lt = getPos(Array(s[0..<l]))
            if lt.isEmpty {
                continue
            }
            let rt = getPos(Array(s[l...]))
            if rt.isEmpty {
                continue
            }
            for i in lt {
                for j in rt {
                    ans.append("(\(String(i)), \(String(j)))")
                }
            }
        }
        return ans
    }
    
    private func getPos(_ s: [Character]) -> [[Character]] {
        var pos = [[Character]]()
        if s[0] != "0" || s == ["0"] {
            pos.append(s)
        }
        for p in 1..<s.count {
            if (p != 1 && s[0] == "0") || s.last == "0" {
                continue
            }
            pos.append(s[0..<p] + ["."] + s[p...])
        }
        return pos
    }
}
// @lc code=end

func main() {
    var s: String
    var res: [String]
    
    /**
     示例 1:
     输入: "(123)"
     输出: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]
     */
    s = "(123)"
    res = ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]
    assert(res.sorted() == Solution().ambiguousCoordinates(s).sorted())
    
    /**
     示例 2:
     输入: "(00011)"
     输出:  ["(0.001, 1)", "(0, 0.011)"]
     解释:
     0.0, 00, 0001 或 00.01 是不被允许的。
     */
    s = "(00011)"
    res = ["(0.001, 1)", "(0, 0.011)"]
    assert(res.sorted() == Solution().ambiguousCoordinates(s).sorted())

    /**
     示例 3:
     输入: "(0123)"
     输出: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"]
     */
    s = "(0123)"
    res = ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"]
    assert(res.sorted() == Solution().ambiguousCoordinates(s).sorted())
    
    /**
     示例 4:
     输入: "(100)"
     输出: [(10, 0)]
     解释:
     1.0 是不被允许的。
     */
    s = "(100)"
    res = ["(10, 0)"]
    assert(res.sorted() == Solution().ambiguousCoordinates(s).sorted())
}
