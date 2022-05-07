/*
 * @lc app=leetcode.cn id=433 lang=swift
 *
 * [433] 最小基因变化
 */

// @lc code=start
class Solution {
    private func encode(_ code: String) -> Int {
        var ans = 0
        for c in code {
            ans <<= 2
            switch c {
            case "A":
                break
            case "C":
                ans |= 1
            case "G":
                ans |= 2
            case "T":
                ans |= 3
            default:
                break
            }
        }
        return ans
    }
    
    private func mutate(_ code: Int, _ pos: Int, _ val: Int) -> Int {
        let pos_ = pos * 2
        return ((code & ~(3 << pos_) | (val << pos_)) & 0xffff)
    }
    
    func minMutation(_ start: String, _ end: String, _ bank: [String]) -> Int {
        let sCode = encode(start)
        let eCode = encode(end)
        
        // 基因库编码后保存到集合中
        var codes: Set<Int> = []
        for code in bank {
            codes.insert(encode(code))
        }
        
        if !codes.contains(eCode) {
            return -1
        }
        // 移除开始的基因
        codes.remove(sCode)
              
        // bfs
        var q: [Int] = [sCode]
        var ans = 0
        while !q.isEmpty {
            ans += 1
            let cnt = q.count
            for _ in 0..<cnt {
                let cur = q.removeFirst()
                for j in 0..<8 {
                    for k in 0..<4 {
                        let code = mutate(cur, j, k)
                        if codes.contains(code) {
                            if code == eCode {
                                return ans
                            }
                            q.append(code)
                            codes.remove(code)
                        }
                    }
                }
            }
        }
        return -1
    }
}
// @lc code=end

func main() {
    var start: String
    var end: String
    var bank: [String]
    var res: Int
    
    /**
     输入：start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
     输出：1
     */
    start = "AACCGGTT"
    end = "AACCGGTA"
    bank = ["AACCGGTA"]
    res = 1
    assert(res == Solution().minMutation(start, end, bank))
    
    /**
     输入：start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
     输出：2
     */
    start = "AACCGGTT"
    end = "AAACGGTA"
    bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
    res = 2
    assert(res == Solution().minMutation(start, end, bank))
    
    /**
     输入：start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
     输出：3
     */
    start = "AAAAACCC"
    end = "AACCCCCC"
    bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
    res = 3
    assert(res == Solution().minMutation(start, end, bank))
}
