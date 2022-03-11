/*
 * @lc app=leetcode.cn id=2049 lang=swift
 *
 * [2049] 统计最高分的节点数目
 */

// @lc code=start
class Solution {
    private var n = 0
    private var cnt = 0
    private var maxScore = 0
    private var children: [[Int]] = []

    @discardableResult
    private func dfs(_ node: Int) -> Int {
        var score = 1
        var size = n - 1
        for child in children[node] {
            let t = dfs(child)
            score *= t
            size -= t
        }
        if node != 0 {
            score *= size
        }
        if score == maxScore {
            cnt += 1
        } else if score > maxScore {
            maxScore = score
            cnt = 1
        }
        return n - size
    }
    
    func countHighestScoreNodes(_ parents: [Int]) -> Int {
        n = parents.count
        children = [[Int]](repeating: [], count: n)
        for i in 0..<n {
            let parent = parents[i]
            if parent != -1 {
                children[parent].append(i)
            }
        }
        dfs(0)
        return cnt
    }
}
// @lc code=end

func main() {
    var parents: [Int]
    var res: Int
    
    /**
     输入：parents = [-1,2,0,2,0]
     输出：3
     解释：
     - 节点 0 的分数为：3 * 1 = 3
     - 节点 1 的分数为：4 = 4
     - 节点 2 的分数为：1 * 1 * 2 = 2
     - 节点 3 的分数为：4 = 4
     - 节点 4 的分数为：4 = 4
     最高得分为 4 ，有三个节点得分为 4 （分别是节点 1，3 和 4 ）。
     */
    parents = [-1,2,0,2,0]
    res = 3
    assert(res == Solution().countHighestScoreNodes(parents))
    
    /**
     输入：parents = [-1,2,0]
     输出：2
     解释：
     - 节点 0 的分数为：2 = 2
     - 节点 1 的分数为：2 = 2
     - 节点 2 的分数为：1 * 1 = 1
     最高分数为 2 ，有两个节点分数为 2 （分别为节点 0 和 1 ）。
     */
    parents = [-1,2,0]
    res = 2
    assert(res == Solution().countHighestScoreNodes(parents))
}
