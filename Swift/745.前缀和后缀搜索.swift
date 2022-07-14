/*
 * @lc app=leetcode.cn id=745 lang=swift
 *
 * [745] 前缀和后缀搜索
 */

// @lc code=start

class WordFilter {

    var map: [String: Int] = [:]

    init(_ words: [String]) {
        for i in 0..<words.count {
            let word  = words[i]
            var prefs: [Substring] = []
            var suffs: [Substring] = []
            for i in 0...word.count {
                prefs.append(word.prefix(i))
                suffs.append(word.suffix(i))
            }
            for pref in prefs {
                for suff in suffs {
                    map[String(pref + "_" + suff)] = i
                }
            }
        }
    }
    
    func f(_ pref: String, _ suff: String) -> Int {
        return map[pref + "_" + suff] ?? -1
    }
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * let obj = WordFilter(words)
 * let ret_1: Int = obj.f(pref, suff)
 */
// @lc code=end

func main() {
    /**
     输入
     ["WordFilter", "f"]
     [[["apple"]], ["a", "e"]]
     输出
     [null, 0]
     解释
     WordFilter wordFilter = new WordFilter(["apple"]);
     wordFilter.f("a", "e"); // 返回 0 ，因为下标为 0 的单词：前缀 prefix = "a" 且 后缀 suff = "e" 。
     */
    let wordFilter = WordFilter(["apple"])
    assert(wordFilter.f("a", "e") == 0)
}
