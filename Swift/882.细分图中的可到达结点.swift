/*
 * @lc app=leetcode.cn id=882 lang=swift
 *
 * [882] 细分图中的可到达结点
 */

// @lc code=start
class Solution {
    func reachableNodes(_ edges: [[Int]], _ maxMoves: Int, _ n: Int) -> Int {
        typealias pii = (Int, Int)
        var g = [[pii]](repeating: [], count: n)
        for edge in edges {
            let u = edge[0]
            let v = edge[1]
            let cnt = edge[2] + 1
            g[u].append((v, cnt))
            g[v].append((u, cnt))
        }
        var q = PriorityQueue<pii> { $0.1 < $1.1 }
        q.push((0, 0))
        var dist = [Int](repeating: .max, count: n)
        dist[0] = 0
        while let (d, u) = q.pop() {
            for (v, cnt) in g[u] {
                if d + cnt < dist[v] {
                    dist[v] = d + cnt
                    q.push((dist[v], v))
                }
            }
        }
        var ans = 0
        for d in dist {
            if d <= maxMoves {
                ans += 1
            }
        }
        
        for edge in edges {
            let u = edge[0]
            let v = edge[1]
            let cnt = edge[2]
            let a = min(cnt, max(0, maxMoves - dist[u]))
            let b = min(cnt, max(0, maxMoves - dist[v]))
            ans += min(cnt, a + b)
        }
        return ans
    }
}
// @lc code=end

func main() {
    var edges: [[Int]]
    var maxMoves: Int
    var n: Int
    var res: Int
        
    /**
     输入：edges = [[0,1,10],[0,2,1],[1,2,2]], maxMoves = 6, n = 3
     输出：13
     解释：边的细分情况如上图所示。
     可以到达的节点已经用黄色标注出来。
     */
    edges = [[0,1,10],[0,2,1],[1,2,2]]
    maxMoves = 6
    n = 3
    res = 13
    assert(res == Solution().reachableNodes(edges, maxMoves, n))
    
    /**
     输入：edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], maxMoves = 10, n = 4
     输出：23
     */
    edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]]
    maxMoves = 10
    n = 4
    res = 23
    assert(res == Solution().reachableNodes(edges, maxMoves, n))
    
    /**
     输入：edges = [[1,2,4],[1,4,5],[1,3,1],[2,3,4],[3,4,5]], maxMoves = 17, n = 5
     输出：1
     解释：节点 0 与图的其余部分没有连通，所以只有节点 0 可以到达。
     */
    edges = [[1,2,4],[1,4,5],[1,3,1],[2,3,4],[3,4,5]]
    maxMoves = 17
    n = 5
    res = 1
    assert(res == Solution().reachableNodes(edges, maxMoves, n))
}
