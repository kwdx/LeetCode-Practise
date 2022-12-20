/*
 * @lc app=leetcode.cn id=1971 lang=swift
 *
 * [1971] 寻找图中是否存在路径
 */

// @lc code=start
class Solution {
    func validPath(_ n: Int, _ edges: [[Int]], _ source: Int, _ destination: Int) -> Bool {
        if source == destination {
            return true
        }
        var uf = UnionFind(n)
        for edge in edges {
            uf.unionn(edge[0], edge[1])
        }
        return uf.isConnected(source, destination)
    }
    
    struct UnionFind {
        // 图的容量
        private var capacity: Int
        private var parents: [Int]
        private var size: [Int]
        
        init(_ n: Int) {
            self.capacity = n
            self.parents = [Int](0..<n)
            self.size = [Int](repeating: 1, count: n)
        }
        
        mutating func unionn(_ p: Int, _ q: Int) {
            let rootP = find(p)
            let rootQ = find(q)
            
            if rootP == rootQ {
                return
            }
            
            if size[rootP] > size[rootQ] {
                parents[rootQ] = rootP
                size[rootP] += size[rootQ]
            } else {
                parents[rootP] = rootQ
                size[rootQ] += size[rootP]
            }
            capacity -= 1
        }
        
        mutating func isConnected(_ p: Int, _ q: Int) -> Bool {
            find(p) == find(q)
        }
        
        mutating func find(_ x: Int) -> Int {
            var x = x
            while parents[x] != x {
                parents[x] = parents[parents[x]]
                x = parents[x]
            }
            return x
        }
    }
}
// @lc code=end

func main() {
    var n: Int
    var edges: [[Int]]
    var source: Int
    var destination: Int
    var res: Bool
    
    /**
     输入：n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
     输出：true
     解释：存在由顶点 0 到顶点 2 的路径:
     - 0 → 1 → 2
     - 0 → 2
     */
    n = 3
    edges = [[0,1],[1,2],[2,0]]
    source = 0
    destination = 2
    res = true
    assert(res == Solution().validPath(n, edges, source, destination))
    
    /**
     输入：n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
     输出：false
     解释：不存在由顶点 0 到顶点 5 的路径.
     */
    n = 6
    edges = [[0,1],[0,2],[3,5],[5,4],[4,3]]
    source = 0
    destination = 5
    res = false
    assert(res == Solution().validPath(n, edges, source, destination))
}
