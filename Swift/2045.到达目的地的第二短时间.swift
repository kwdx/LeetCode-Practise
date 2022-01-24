/*
 * @lc app=leetcode.cn id=2045 lang=swift
 *
 * [2045] 到达目的地的第二短时间
 */

// @lc code=start
class Solution {
//    let N = 10010, M = 4 * 10010, INF = 0x3f3f3f3f
//    var idx = 0
//    lazy var he = [Int](repeating: -1, count: N)
//    lazy var e = [Int](repeating: 0, count: M)
//    lazy var ne = [Int](repeating: 0, count: M)
//
//    func add(_ a: Int, _ b: Int) {
//        e[idx] = b
//        ne[idx] = he[a]
//        he[a] = idx
//        idx += 1
//    }
//
//    func secondMinimum(_ n: Int, _ edges: [[Int]], _ time: Int, _ change: Int) -> Int {
//        for edge in edges {
//            add(edge[0], edge[1])
//            add(edge[1], edge[0])
//        }
//        var d = [(Int, Int)]()
//        var dist1 = [Int](repeating: INF, count: n + 10)
//        var dist2 = [Int](repeating: INF, count: n + 10)
//        d.append((1, 0))
//        dist1[1] = 0
//        while !d.isEmpty {
//            let (u, dist) = d.removeFirst()
//            var i = he[u]
//            while i != -1 {
//                let j = e[i]
//                if dist1[j] > dist + 1 {
//                    dist2[j] = dist1[j]
//                    dist1[j] = dist + 1
//                    d.append((j, dist1[j]))
//                } else if dist1[j] < dist + 1 && dist + 1 < dist2[j] {
//                    dist2[j] = dist + 1
//                    d.append((j, dist2[j]))
//                }
//                i = ne[i]
//            }
//        }
//        var ans = 0
//        for _ in 0..<dist2[n] {
//            let a = ans / change, b = ans % change
//            ans += time + (a % 2 == 0 ? 0 : change - b)
//        }
//        return ans
//    }
    
    func secondMinimum(_ n: Int, _ edges: [[Int]], _ time: Int, _ change: Int) -> Int {
        var graph: [[Int]] = .init(repeating: [], count: n + 1)
        for edge in edges {
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])
        }

        // path[i][0] 表示从 1 到 i 的最短路长度，path[i][1] 表示从 1 到 i 的严格次短路长度
        var path = [[Int]](repeating: .init(repeating: .max, count: 2), count: n + 1)
        path[1][0] = 0
        var q: [(Int, Int)] = [(1, 0)]
        while path[n][1] == .max {
            let (cur, len) = q.removeFirst()
            for next in graph[cur] {
                if len + 1 < path[next][0] {
                    path[next][0] = len + 1
                    q.append((next, len + 1))
                } else if len + 1 > path[next][0] && len + 1 < path[next][1] {
                    path[next][1] = len + 1
                    q.append((next, len + 1))
                }
            }
        }

        var ans = 0
        for _ in 0..<path[n][1] {
            if ans % (2 * change) >= change {
                ans = ans + (2 * change - ans % (2 * change))
            }
            ans = ans + time
        }
        return ans
    }
}
// @lc code=end

func main() {
    var n: Int
    var edges: [[Int]]
    var time: Int
    var change: Int
    var res: Int
    
    /**
     输入：n = 5, edges = [[1,2],[1,3],[1,4],[3,4],[4,5]], time = 3, change = 5
     输出：13
     解释：
     上面的左图展现了给出的城市交通图。
     右图中的蓝色路径是最短时间路径。
     花费的时间是：
     - 从节点 1 开始，总花费时间=0
     - 1 -> 4：3 分钟，总花费时间=3
     - 4 -> 5：3 分钟，总花费时间=6
     因此需要的最小时间是 6 分钟。

     右图中的红色路径是第二短时间路径。
     - 从节点 1 开始，总花费时间=0
     - 1 -> 3：3 分钟，总花费时间=3
     - 3 -> 4：3 分钟，总花费时间=6
     - 在节点 4 等待 4 分钟，总花费时间=10
     - 4 -> 5：3 分钟，总花费时间=13
     因此第二短时间是 13 分钟。
     */
    n = 5
    edges = [[1,2],[1,3],[1,4],[3,4],[4,5]]
    time = 3
    change = 5
    res = 13
    assert(res == Solution().secondMinimum(n, edges, time, change))
    
    /**
     输入：n = 2, edges = [[1,2]], time = 3, change = 2
     输出：11
     解释：
     最短时间路径是 1 -> 2 ，总花费时间 = 3 分钟
     最短时间路径是 1 -> 2 -> 1 -> 2 ，总花费时间 = 11 分钟
     */
    n = 2
    edges = [[1,2]]
    time = 3
    change = 2
    res = 11
    assert(res == Solution().secondMinimum(n, edges, time, change))
}
