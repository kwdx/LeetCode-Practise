/*
 * @lc app=leetcode.cn id=827 lang=swift
 *
 * [827] 最大人工岛
 */

// @lc code=start
class Solution {
    private let dirs = [(1,0),(-1,0),(0,1),(0,-1)]
    private var p = [Int]()
    private var sz = [Int]()
    
    func find(_ x: Int) -> Int {
        if p[x] != x {
            p[x] = find(p[x])
        }
        return p[x]
    }
    
    func union(_ a: Int, _ b: Int) {
        let ax = find(a)
        let bx = find(b)
        if ax == bx {
            return
        }
        if sz[ax] > sz[bx] {
            union(b, a)
        } else {
            sz[bx] += sz[ax]
            p[ax] = p[bx]
        }
    }
    
    func largestIsland(_ grid: [[Int]]) -> Int {
        let n = grid.count
        let m = n * n
        p = [Int](repeating: 0, count: m + 1)
        sz = [Int](repeating: 0, count: m + 1)
        for i in 1...m {
            p[i] = i
            sz[i] = 1
        }
        for i in 0..<n {
            for j in 0..<n {
                if grid[i][j] == 0 {
                    continue
                }
                for dir in dirs {
                    let x = i + dir.0
                    let y = j + dir.1
                    if x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 0 {
                        continue
                    }
                    union(i * n + j + 1, x * n + y + 1)
                }
            }
        }
        var ans = 0
        for i in 0..<n {
            for j in 0..<n {
                if grid[i][j] == 1 {
                    ans = max(ans, sz[find(i * n + j + 1)])
                } else {
                    var total = 1
                    var sets: Set<Int> = []
                    for dir in dirs {
                        let x = i + dir.0
                        let y = j + dir.1
                        if x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 0 {
                            continue
                        }
                        let root = find(x * n + y + 1)
                        if sets.contains(root) {
                            continue
                        }
                        total += sz[root]
                        sets.insert(root)
                    }
                    ans = max(ans, total)
                }
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var grid: [[Int]]
    var res: Int
    
    /**
     输入: grid = [[1, 0], [0, 1]]
     输出: 3
     解释: 将一格0变成1，最终连通两个小岛得到面积为 3 的岛屿。
     */
    grid = [[1, 0], [0, 1]]
    res = 3
    assert(res == Solution().largestIsland(grid))
    
    /**
     输入: grid = [[1, 1], [1, 0]]
     输出: 4
     解释: 将一格0变成1，岛屿的面积扩大为 4。
     */
    grid = [[1, 1], [1, 0]]
    res = 4
    assert(res == Solution().largestIsland(grid))
    
    /**
     输入: grid = [[1, 1], [1, 1]]
     输出: 4
     解释: 没有0可以让我们变成1，面积依然为 4。
     */
    grid = [[1, 1], [1, 1]]
    res = 4
    assert(res == Solution().largestIsland(grid))
}
