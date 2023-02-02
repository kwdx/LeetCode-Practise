/*
 * @lc app=leetcode.cn id=1129 lang=swift
 *
 * [1129] 颜色交替的最短路径
 */

// @lc code=start
class Solution {
    func shortestAlternatingPaths(_ n: Int, _ redEdges: [[Int]], _ blueEdges: [[Int]]) -> [Int] {
        var next = [[[Int]]](repeating: [[Int]](repeating: [], count: n), count: 2)
        for e in redEdges {
            next[0][e[0]].append(e[1])
        }
        for e in blueEdges {
            next[1][e[0]].append(e[1])
        }
        
        // 两种类型的颜色最短路径的长度
        var dist = [[Int]](repeating: .init(repeating: .max, count: n), count: 2)
        dist[0][0] = 0
        dist[1][0] = 0
        // [(节点，颜色)]
        var q: [(Int, Int)] = [(0,0),(0,1)]
        while let (x, t) = q.first {
            q.removeFirst()
            for y in next[1 - t][x] {
                if dist[1 - t][y] != .max {
                    continue
                }
                dist[1 - t][y] = dist[t][x] + 1
                q.append((y, 1 - t))
            }
        }
        
        var ans = [Int](repeating: 0, count: n)
        for i in 0..<n {
            ans[i] = min(dist[0][i], dist[1][i])
            if ans[i] == .max {
                ans[i] = -1
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var n: Int
    var redEdges: [[Int]]
    var blueEdges: [[Int]]
    var res: [Int]
    
    /**
     输入：n = 3, red_edges = [[0,1],[1,2]], blue_edges = []
     输出：[0,1,-1]
     */
    n = 3
    redEdges = [[0,1],[1,2]]
    blueEdges = []
    res = [0,1,-1]
    assert(res == Solution().shortestAlternatingPaths(n, redEdges, blueEdges))
    
    /**
     输入：n = 3, red_edges = [[0,1]], blue_edges = [[2,1]]
     输出：[0,1,-1]
     */
    n = 3
    redEdges = [[0,1]]
    blueEdges = [[2,1]]
    res = [0,1,-1]
    assert(res == Solution().shortestAlternatingPaths(n, redEdges, blueEdges))
    
    /**
     输入：n = 3, red_edges = [[1,0]], blue_edges = [[2,1]]
     输出：[0,-1,-1]
     */
    n = 3
    redEdges = [[1,0]]
    blueEdges = [[2,1]]
    res = [0,-1,-1]
    assert(res == Solution().shortestAlternatingPaths(n, redEdges, blueEdges))
    
    /**
     输入：n = 3, red_edges = [[0,1]], blue_edges = [[1,2]]
     输出：[0,1,2]
     */
    n = 3
    redEdges = [[0,1]]
    blueEdges = [[1,2]]
    res = [0,1,2]
    assert(res == Solution().shortestAlternatingPaths(n, redEdges, blueEdges))
    
    /**
     输入：n = 3, red_edges = [[0,1],[0,2]], blue_edges = [[1,0]]
     输出：[0,1,1]
     */
    n = 3
    redEdges = [[0,1],[0,2]]
    blueEdges = [[1,0]]
    res = [0,1,1]
    assert(res == Solution().shortestAlternatingPaths(n, redEdges, blueEdges))
}
