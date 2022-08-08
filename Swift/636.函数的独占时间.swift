/*
 * @lc app=leetcode.cn id=636 lang=swift
 *
 * [636] 函数的独占时间
 */

// @lc code=start
class Solution {
    func exclusiveTime(_ n: Int, _ logs: [String]) -> [Int] {
        var ans = [Int](repeating: 0, count: n)
        var st = [(Int, Int)]()
        for log in logs {
            let components = log.split(separator: ":")
            let idx = Int(components[0])!
            let timestamp = Int(components[2])!
            if components[1] == "start" {
                if !st.isEmpty {
                    ans[st.last!.0] += timestamp - st.last!.1
                    st[st.count - 1].1 = timestamp
                }
                st.append((idx, timestamp))
            } else {
                let t = st.removeLast()
                ans[t.0] += timestamp - t.1 + 1
                if (!st.isEmpty) {
                    st[st.count - 1].1 = timestamp + 1
                }
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var n: Int
    var logs: [String]
    var res: [Int]
    
    /**
     输入：n = 2, logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
     输出：[3,4]
     解释：
     函数 0 在时间戳 0 的起始开始执行，执行 2 个单位时间，于时间戳 1 的末尾结束执行。
     函数 1 在时间戳 2 的起始开始执行，执行 4 个单位时间，于时间戳 5 的末尾结束执行。
     函数 0 在时间戳 6 的开始恢复执行，执行 1 个单位时间。
     所以函数 0 总共执行 2 + 1 = 3 个单位时间，函数 1 总共执行 4 个单位时间。
     */
    n = 2
    logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
    res = [3,4]
    assert(res == Solution().exclusiveTime(n, logs))
    
    /**
     输入：n = 1, logs = ["0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"]
     输出：[8]
     解释：
     函数 0 在时间戳 0 的起始开始执行，执行 2 个单位时间，并递归调用它自身。
     函数 0（递归调用）在时间戳 2 的起始开始执行，执行 4 个单位时间。
     函数 0（初始调用）恢复执行，并立刻再次调用它自身。
     函数 0（第二次递归调用）在时间戳 6 的起始开始执行，执行 1 个单位时间。
     函数 0（初始调用）在时间戳 7 的起始恢复执行，执行 1 个单位时间。
     所以函数 0 总共执行 2 + 4 + 1 + 1 = 8 个单位时间。
     */
    n = 1
    logs = ["0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"]
    res = [8]
    assert(res == Solution().exclusiveTime(n, logs))
    
    /**
     输入：n = 2, logs = ["0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"]
     输出：[7,1]
     解释：
     函数 0 在时间戳 0 的起始开始执行，执行 2 个单位时间，并递归调用它自身。
     函数 0（递归调用）在时间戳 2 的起始开始执行，执行 4 个单位时间。
     函数 0（初始调用）恢复执行，并立刻调用函数 1 。
     函数 1在时间戳 6 的起始开始执行，执行 1 个单位时间，于时间戳 6 的末尾结束执行。
     函数 0（初始调用）在时间戳 7 的起始恢复执行，执行 1 个单位时间，于时间戳 7 的末尾结束执行。
     所以函数 0 总共执行 2 + 4 + 1 = 7 个单位时间，函数 1 总共执行 1 个单位时间。
     */
    n = 2
    logs = ["0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"]
    res = [7,1]
    assert(res == Solution().exclusiveTime(n, logs))
    
    /**
     输入：n = 2, logs = ["0:start:0","0:start:2","0:end:5","1:start:7","1:end:7","0:end:8"]
     输出：[8,1]
     */
    n = 2
    logs = ["0:start:0","0:start:2","0:end:5","1:start:7","1:end:7","0:end:8"]
    res = [8,1]
    assert(res == Solution().exclusiveTime(n, logs))
    
    /**
     输入：n = 1, logs = ["0:start:0","0:end:0"]
     输出：[1]
     */
    n = 1
    logs = ["0:start:0","0:end:0"]
    res = [1]
    assert(res == Solution().exclusiveTime(n, logs))
}
