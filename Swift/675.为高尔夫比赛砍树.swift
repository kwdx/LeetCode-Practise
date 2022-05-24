/*
 * @lc app=leetcode.cn id=675 lang=swift
 *
 * [675] 为高尔夫比赛砍树
 */

// @lc code=start
class Solution {
    private var forest: [[Int]] = []
    private var row: Int { forest.count }
    private var col: Int { forest[0].count }
    
    static let dirs: [(Int, Int)] = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    private func bfs(_ cur: (Int, Int), _ target: (Int, Int)) -> Int {
        if cur == target {
            // 起始点和目标点一致
            return 0
        }
        var step = 0
        var q: [(Int, Int)] = [cur]
        var visited: [[Bool]] = .init(repeating: .init(repeating: false, count: col), count: row)
        visited[cur.0][cur.1] = true
        
        while !q.isEmpty {
            step += 1
            let cnt = q.count
            for _ in 0..<cnt {
                let tree = q.removeFirst()
                for dir in Self.dirs {
                    let nTree = (tree.0 + dir.0, tree.1 + dir.1)
                    if nTree.0 >= 0 && nTree.0 < row && nTree.1 >= 0 && nTree.1 < col {
                        if !visited[nTree.0][nTree.1] && forest[nTree.0][nTree.1] > 0 {
                            if nTree == target {
                                return step
                            }
                            q.append(nTree)
                            visited[nTree.0][nTree.1] = true
                        }
                    }
                }
            }
        }
        return -1;
    }
    
    func cutOffTree(_ forest: [[Int]]) -> Int {
        self.forest = forest
        var trees: [(Int, Int)] = []
        for i in 0..<row {
            for j in 0..<col {
                if forest[i][j] > 1 {
                    trees.append((i, j))
                }
            }
        }
        trees.sort { forest[$0.0][$0.1] < forest[$1.0][$1.1] }
        
        var ans = 0
        
        var cur = (0, 0)
        
        for tree in trees {
            let steps = bfs(cur, tree)
            if steps == -1 {
                return -1
            }
            ans += steps
            cur = tree
        }
        return ans
    }
}
// @lc code=end

func main() {
    var forest: [[Int]]
    var res: Int
    
    /**
     输入：forest = [[1,2,3],[0,0,4],[7,6,5]]
     输出：6
     解释：沿着上面的路径，你可以用 6 步，按从最矮到最高的顺序砍掉这些树。。
     */
    forest = [[1,2,3],[0,0,4],[7,6,5]]
    res = 6
    assert(res == Solution().cutOffTree(forest))
    
    /**
     输入：forest = [[1,2,3],[0,0,0],[7,6,5]]
     输出：-1
     解释：由于中间一行被障碍阻塞，无法访问最下面一行中的树。
     */
    forest = [[1,2,3],[0,0,0],[7,6,5]]
    res = -1
    assert(res == Solution().cutOffTree(forest))

    /**
     输入：forest = [[2,3,4],[0,0,5],[8,7,6]]
     输出：6
     解释：可以按与示例 1 相同的路径来砍掉所有的树。
     (0,0) 位置的树，可以直接砍去，不用算步数。
     */
    forest = [[2,3,4],[0,0,5],[8,7,6]]
    res = 6
    assert(res == Solution().cutOffTree(forest))
}
