/*
 * @lc app=leetcode.cn id=472 lang=swift
 *
 * [472] 连接词
 */

// @lc code=start
class Solution {
    private var root = Trie()
    func findAllConcatenatedWordsInADict(_ words: [String]) -> [String] {
        var ans: [String] = []
        let words_ = words.sorted { $0.count < $1.count }
        for word in words_ {
            if canBeConcatenated(word.map { $0 }, 0) {
                ans.append(word)
            } else {
                root.insert(word)
            }
        }
        return ans
    }
    
    private func canBeConcatenated(_ s: [Character], _ idx: Int) -> Bool {
        if idx > 0 && idx == s.count {
            return true
        }
        var node = root
        for i in idx..<s.count {
            if node.child[s[i]] == nil {
                return false
            }
            node = node.child[s[i]]!
            if node.isEnd && canBeConcatenated(s, i + 1) {
                return true
            }
        }
        return false
    }
    
    class Trie {
        var isEnd = false
        var child: [Character: Trie] = [:]
        
        func insert(_ word: String) {
            var node = self
            for c in word {
                if node.child[c] == nil {
                    node.child[c] = Trie()
                }
                node = node.child[c]!
            }
            node.isEnd = true
        }
    }
}
// @lc code=end

func main() {
    var words: [String]
    var res: [String]
    
    /**
     输入：words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
     输出：["catsdogcats","dogcatsdog","ratcatdogcat"]
     解释："catsdogcats" 由 "cats", "dog" 和 "cats" 组成;
          "dogcatsdog" 由 "dog", "cats" 和 "dog" 组成;
          "ratcatdogcat" 由 "rat", "cat", "dog" 和 "cat" 组成。
     */
    words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
    res = ["dogcatsdog","catsdogcats","ratcatdogcat"]
    assert(res == Solution().findAllConcatenatedWordsInADict(words))
    
    /**
     输入：words = ["cat","dog","catdog"]
     输出：["catdog"]
     */
    words = ["cat","dog","catdog"]
    res = ["catdog"]
    assert(res == Solution().findAllConcatenatedWordsInADict(words))
    
    /**
     输入：words = [""]
     输出：[]
     */
    words = [""]
    res = []
    assert(res == Solution().findAllConcatenatedWordsInADict(words))
}
