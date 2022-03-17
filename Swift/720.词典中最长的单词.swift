/*
 * @lc app=leetcode.cn id=720 lang=swift
 *
 * [720] 词典中最长的单词
 */

// @lc code=start
class Solution {
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
        
        func search(_ word: String) -> Bool {
            var node: Trie = self
            for c in word {
                if node.child[c] == nil || !node.child[c]!.isEnd {
                    return false
                }
                node = node.child[c]!
            }
            return node.isEnd
        }
    }
    
    func longestWord(_ words: [String]) -> String {
        let trie = Trie()
        for word in words {
            trie.insert(word)
        }
        var ans = ""
        for word in words {
            if trie.search(word) {
                if word.count > ans.count ||
                    (word.count == ans.count && word < ans) {
                    ans = word
                }
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var words: [String]
    var res: String
    
    /**
     输入：words = ["w","wo","wor","worl", "world"]
     输出："world"
     解释： 单词"world"可由"w", "wo", "wor", 和 "worl"逐步添加一个字母组成。
     */
    words = ["w","wo","wor","worl", "world"]
    res = "world"
    assert(res == Solution().longestWord(words))
    
    /**
     输入：words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
     输出："apple"
     解释："apply" 和 "apple" 都能由词典中的单词组成。但是 "apple" 的字典序小于 "apply"
     */
    words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
    res = "apple"
    assert(res == Solution().longestWord(words))
}
