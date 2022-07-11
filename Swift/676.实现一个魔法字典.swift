/*
 * @lc app=leetcode.cn id=676 lang=swift
 *
 * [676] 实现一个魔法字典
 */

// @lc code=start

class MagicDictionary {
    private var dict: [Int: [String]] = [:]
    
    init() {

    }
    
    func buildDict(_ dictionary: [String]) {
        for word in dictionary {
            if dict[word.count] == nil {
                dict[word.count] = []
            }
            dict[word.count]?.append(word)
        }
    }
    
    func search(_ searchWord: String) -> Bool {
        guard let words = dict[searchWord.count] else {
            return false
        }
        let searches = Array(searchWord)
        for word in words {
            var diff = 0
            let chars = Array(word)
            for i in 0..<chars.count {
                if chars[i] == searches[i] {
                    continue
                }
                diff += 1
            }
            if diff == 1 {
                return true
            }
        }
        return false
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * let obj = MagicDictionary()
 * obj.buildDict(dictionary)
 * let ret_2: Bool = obj.search(searchWord)
 */
// @lc code=end

func main() {
    /**
     输入
     ["MagicDictionary", "buildDict", "search", "search", "search", "search"]
     [[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
     输出
     [null, null, false, true, false, false]

     解释
     MagicDictionary magicDictionary = new MagicDictionary();
     magicDictionary.buildDict(["hello", "leetcode"]);
     magicDictionary.search("hello"); // 返回 False
     magicDictionary.search("hhllo"); // 将第二个 'h' 替换为 'e' 可以匹配 "hello" ，所以返回 True
     magicDictionary.search("hell"); // 返回 False
     magicDictionary.search("leetcoded"); // 返回 False
     */
    let obj = MagicDictionary()
    obj.buildDict(["hello", "leetcode"])
    assert(false == obj.search("hello")) // 返回 False
    assert(true == obj.search("hhllo")) // 将第二个 'h' 替换为 'e' 可以匹配 "hello" ，所以返回 True
    assert(false == obj.search("hell")) // 返回 False
    assert(false == obj.search("leetcoded")) // 返回 False
}
