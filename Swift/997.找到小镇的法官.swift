/*
 * @lc app=leetcode.cn id=997 lang=swift
 *
 * [997] 找到小镇的法官
 */

// @lc code=start
class Solution {
    func findJudge(_ n: Int, _ trust: [[Int]]) -> Int {
        var ins = [Int](repeating: 0, count: n + 1)
        var outs = [Int](repeating: 0, count: n + 1)
        for p in trust {
            ins[p[1]] = ins[p[1]] + 1
            outs[p[0]] = outs[p[0]] + 1
        }
        for i in 1...n {
            if ins[i] == n - 1 && outs[i] == 0 {
                return i
            }
        }
        return -1
    }
}
// @lc code=end

func main() {
    var n: Int
    var trust: [[Int]]
    var res: Int
    
    /**
     输入：n = 2, trust = [[1,2]]
     输出：2
     */
    n = 2
    trust = [[1,2]]
    res = 2
    assert(res == Solution().findJudge(n, trust))
    
    /**
     输入：n = 3, trust = [[1,3],[2,3]]
     输出：3
     */
    n = 3
    trust = [[1,3],[2,3]]
    res = 3
    assert(res == Solution().findJudge(n, trust))
    
    /**
     输入：n = 3, trust = [[1,3],[2,3],[3,1]]
     输出：-1
     */
    n = 3
    trust = [[1,3],[2,3],[3,1]]
    res = -1
    assert(res == Solution().findJudge(n, trust))
    
    /**
     输入：n = 3, trust = [[1,2],[2,3]]
     输出：-1
     */
    n = 3
    trust = [[1,2],[2,3]]
    res = -1
    assert(res == Solution().findJudge(n, trust))
    
    /**
     输入：n = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
     输出：3
     */
    n = 4
    trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
    res = 3
    assert(res == Solution().findJudge(n, trust))
}
