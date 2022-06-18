//
//  114.外星文字典.swift
//  swift_
//
//  Created by kingsoft on 2022/5/31.
//

// @lc code=start
class Solution {
    func alienOrder(_ words: [String]) -> String {
        // 邻接矩阵
        var g: [Character: Set<Character>] = [:]
        // 存每个字母的入度
        var d: [Character: Int] = [:]
        // 初始化每个字母的入度
        for word in words {
            for c in word {
                d[c] = 0
            }
        }
        
        for i in 1..<words.count {
            let word1 = Array(words[i - 1])
            let word2 = Array(words[i])
            let len = min(word1.count, word2.count)
            var j = 0
            while j < len {
                if word1[j] == word2[j] {
                    j += 1
                    continue
                }
                if !(g[word1[j]]?.contains(word2[j]) ?? false) {
                    if g[word1[j]] != nil {
                        g[word1[j]]?.insert(word2[j])
                    } else {
                        g[word1[j]] = [word2[j]]
                    }
                    d[word2[j]] = 1 + (d[word2[j]] ?? 0)
                }
                break
            }
            if j == len && word1.count > word2.count {
                return ""
            }
        }
        
        var q: [Character] = []
        for (x, y) in d {
            if y == 0 {
                q.append(x)
            }
        }
        
        var ans = ""
        while !q.isEmpty {
            let t = q.removeFirst()
            ans.append(t)
            if g[t] == nil {
                g[t] = []
            }
            for c in g[t]! {
                d[c] = (d[c] ?? 0) - 1
                if d[c] == 0 {
                    q.append(c)
                }
            }
        }
        return ans.count == g.count ? ans : ""
    }
}
// @lc code=end

func main() {
    var words: [String]
    var res: String
    
    /**
     输入：words = ["wrt","wrf","er","ett","rftt"]
     输出："wertf"
     */
    words = ["wrt","wrf","er","ett","rftt"]
    res = "wertf"
    assert(res == Solution().alienOrder(words))
    
    /**
     输入：words = ["z","x"]
     输出："zx"
     */
    words = ["z","x"]
    res = "zx"
    assert(res == Solution().alienOrder(words))
    
    /**
     输入：words = ["z","x","z"]
     输出：""
     解释：不存在合法字母顺序，因此返回 "" 。
     */
    words = ["z","x","z"]
    res = ""
    assert(res == Solution().alienOrder(words))
}
