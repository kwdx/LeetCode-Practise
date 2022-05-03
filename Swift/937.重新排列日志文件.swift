/*
 * @lc app=leetcode.cn id=937 lang=swift
 *
 * [937] 重新排列日志文件
 */

// @lc code=start
class Solution {
    private class Log {
        let idx: Int
        let ori: String
        let sign: String
        let content: String
        var isDigit: Bool { content.first?.isNumber ?? false }
        
        init(_ s: String, _ idx: Int) {
            self.ori = s
            self.idx = idx
            var i = 0
            let chars = Array(s)
            while i < s.count && chars[i] != " " {
                i += 1
            }
            
            self.sign = .init(s.prefix(i))
            self.content = .init(s.dropFirst(i + 1))
        }
    }
    func reorderLogFiles(_ logs: [String]) -> [String] {
        let n = logs.count
        var arr: [Log] = []
        for i in 0..<n {
            arr.append(.init(logs[i], i))
        }
        arr = arr.sorted { a, b in
            if a.isDigit != b.isDigit {
                return !a.isDigit
            }
            if a.isDigit {
                return a.idx < b.idx
            }
            return a.content != b.content ?
            a.content < b.content :
            a.sign < b.sign
        }
        return arr.map { $0.ori }
    }
}
// @lc code=end

func main() {
    var logs: [String]
    var res: [String]
    
    /**'
     输入：logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
     输出：["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
     解释：
     字母日志的内容都不同，所以顺序为 "art can", "art zero", "own kit dig" 。
     数字日志保留原来的相对顺序 "dig1 8 1 5 1", "dig2 3 6" 。
     */
    logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
    res = ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
    assert(res == Solution().reorderLogFiles(logs))

    /**
     输入：logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
     输出：["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
     */
    logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
    res = ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
    assert(res == Solution().reorderLogFiles(logs))
}
