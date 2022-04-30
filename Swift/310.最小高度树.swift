/*
 * @lc app=leetcode.cn id=310 lang=swift
 *
 * [310] 最小高度树
 */

// @lc code=start
class Solution {
    func findMinHeightTrees(_ n: Int, _ edges: [[Int]]) -> [Int] {
        if n == 1 {
            return [0]
        }
        
        var degree = [Int](repeating: 0, count: n) // 每个节点对应的度数
        var neighbor = [[Int]](repeating: [], count: n) // 邻接表
        
        for edge in edges {
            let u = edge[0]
            let v = edge[1]
            degree[u] += 1
            degree[v] += 1
            neighbor[u].append(v)
            neighbor[v].append(u)
        }
        
        var ans = [Int]()
        
        // 叶子节点入栈
        var q: [Int] = (0..<n).filter { degree[$0] == 1 }
        
        // 从外向内一层一层剥
        while !q.isEmpty {
            ans.removeAll()
            let s = q.count
            for _ in 0..<s {
                let t = q.removeFirst()
                ans.append(t)
                for j in neighbor[t] {
                    degree[j] -= 1
                    if degree[j] == 1 {
                        q.append(j)
                    }
                }
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var n: Int
    var edges: [[Int]]
    var res: [Int]
    
    /**
     输入：n = 4, edges = [[1,0],[1,2],[1,3]]
     输出：[1]
     解释：如图所示，当根是标签为 1 的节点时，树的高度是 1 ，这是唯一的最小高度树。
     */
    n = 4
    edges = [[1,0],[1,2],[1,3]]
    res = [1]
    assert(res == Solution().findMinHeightTrees(n, edges))
    
    /**
     输入：n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
     输出：[3,4]
     */
    n = 6
    edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
    res = [3,4]
    assert(res == Solution().findMinHeightTrees(n, edges))
}
